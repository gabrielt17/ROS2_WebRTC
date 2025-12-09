#define GST_USE_UNSTABLE_API

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <gst/gst.h>
#include <gst/webrtc/webrtc.h>
#include <gst/sdp/sdp.h>
#include <glib.h>
#include <string>
#include <cstdio>
#include <nlohmann/json.hpp>
#include <ixwebsocket/IXWebSocket.h>
#include <thread>
#include <atomic>
#include <csignal>

using namespace nlohmann;

// Variáveis globais
std::string ipAddress = "192.168.0.131";
std::string port = "8000";
std::string localId = "gabrielt";
std::string remoteId = "alice";

GstElement *webrtc_send;
ix::WebSocket ws;

GMainLoop* gst_loop_handle;
std::atomic<bool> running(true);

// -------------------- Callbacks do WebRTC --------------------
static void on_offer_created(GstPromise *promise, gpointer user_data) {
    GstWebRTCSessionDescription *offer = nullptr;
    const GstStructure *reply = gst_promise_get_reply(promise);
    gst_structure_get(reply, "offer", GST_TYPE_WEBRTC_SESSION_DESCRIPTION, &offer, NULL);

    g_signal_emit_by_name(webrtc_send, "set-local-description", offer, NULL);

    gchar *sdp_text = gst_sdp_message_as_text(offer->sdp);
    json sdp_offer = {
        {"id", remoteId},
        {"type", "offer"},
        {"sdp", sdp_text}
    };
    RCLCPP_INFO(rclcpp::get_logger("send_camera_node"), ">>> OFERTA GERADA:\n%s", sdp_offer.dump().c_str());
    ws.send(sdp_offer.dump());

    g_free(sdp_text);
    gst_webrtc_session_description_free(offer);
    gst_promise_unref(promise);
}

static void on_negotiation_needed(GstElement* element, gpointer user_data) {
    RCLCPP_INFO(rclcpp::get_logger("send_camera_node"), "Pipeline iniciada, aguardando frames...");
    GstPromise *promise = gst_promise_new_with_change_func(on_offer_created, NULL, NULL);
    g_signal_emit_by_name(element, "create-offer", NULL, promise);
}

static void on_ice_candidate(GstElement *webrtc, guint mline_index, gchar *candidate) {
    json ice_candidate = {
        {"id", remoteId},
        {"type", "candidate"},
        {"candidate", candidate},
        {"sdpMLineIndex", mline_index}
    };
    ws.send(ice_candidate.dump());
    RCLCPP_INFO(rclcpp::get_logger("send_camera_node"), ">>> CANDIDATO ICE GERADO:\n%s", ice_candidate.dump().c_str());
}

// -------------------- Helper para thread safety --------------------
struct IceCandidateData {
    guint mline_index;
    std::string candidate;
};

gboolean add_ice_candidate_idle(gpointer data) {
    IceCandidateData* d = static_cast<IceCandidateData*>(data);
    g_signal_emit_by_name(webrtc_send, "add-ice-candidate", d->mline_index, d->candidate.c_str());
    delete d;
    return G_SOURCE_REMOVE;
}

// Callback para monitorar o estado da conexão ICE
static void on_ice_connection_state_notify(GstElement *webrtc, GParamSpec *pspec, gpointer user_data) {
    GstWebRTCICEConnectionState ice_state;
    g_object_get(webrtc, "ice-connection-state", &ice_state, NULL);

    const char *state_str = "UNKNOWN";
    switch (ice_state) {
        case GST_WEBRTC_ICE_CONNECTION_STATE_NEW: state_str = "NEW"; break;
        case GST_WEBRTC_ICE_CONNECTION_STATE_CHECKING: state_str = "CHECKING"; break;
        case GST_WEBRTC_ICE_CONNECTION_STATE_CONNECTED: state_str = "CONNECTED"; break;
        case GST_WEBRTC_ICE_CONNECTION_STATE_COMPLETED: state_str = "COMPLETED"; break;
        case GST_WEBRTC_ICE_CONNECTION_STATE_FAILED: state_str = "FAILED"; break;
        case GST_WEBRTC_ICE_CONNECTION_STATE_DISCONNECTED: state_str = "DISCONNECTED"; break;
        case GST_WEBRTC_ICE_CONNECTION_STATE_CLOSED: state_str = "CLOSED"; break;
    }
    
    // Use RCLCPP_WARN para destacar no log
    auto logger = rclcpp::get_logger("webrtc_monitor");
    RCLCPP_WARN(logger, ">>> ESTADO ICE MUDOU PARA: %s <<<", state_str);
}

struct AnswerData {
    std::string sdp_text;
};

gboolean add_remote_answer_idle(gpointer data) {
    AnswerData* d = static_cast<AnswerData*>(data);

    GstSDPMessage *sdp = nullptr;
    gst_sdp_message_new(&sdp);
    gst_sdp_message_parse_buffer((const guint8*)d->sdp_text.c_str(), d->sdp_text.size(), sdp);
    GstWebRTCSessionDescription *answer = gst_webrtc_session_description_new(GST_WEBRTC_SDP_TYPE_ANSWER, sdp);
    
    RCLCPP_INFO(rclcpp::get_logger("send_camera_node"), ">>> RESPOSTA SDP RECEBIDA. Configurando descrição remota...");
    g_signal_emit_by_name(webrtc_send, "set-remote-description", answer, NULL);
    
    gst_webrtc_session_description_free(answer);
    delete d;
    return G_SOURCE_REMOVE;
}

// -------------------- Handler para SIGINT --------------------
void sigint_handler(int) {
    running = false;
    g_main_loop_quit(gst_loop_handle);
    rclcpp::shutdown();
}

// -------------------- Main --------------------
int main(int argc, char* argv[]) {
    rclcpp::init(argc, argv);
    gst_init(nullptr, nullptr);

    signal(SIGINT, sigint_handler);

    auto node = rclcpp::Node::make_shared("send_camera_node");

    node->declare_parameter<std::string>("camera_topic", "/camera/camera/color/image_raw");
    std::string camera_topic;
    node->get_parameter("camera_topic", camera_topic);
    RCLCPP_INFO(node->get_logger(), "Transmitindo vídeo do tópico: %s", camera_topic.c_str());

    std::string pipeline_str =
    "rosimagesrc ros-topic=\"" + camera_topic + "\" ! "
    "videoconvert ! "
    "video/x-raw,format=I420 ! "
    "nvvidconv ! "
    "video/x-raw(memory:NVMM),format=I420 ! "
    "queue max-size-buffers=1 leaky=downstream ! "
    // Removido preset-level (não suportado)
    // bitrate reduzido para 2Mbps para teste de estabilidade
    "nvv4l2h264enc bitrate=2000000 insert-sps-pps=true maxperf-enable=1 ! "
    "h264parse ! "
    // Removido aggregate-mode (não suportado)
    "rtph264pay config-interval=1 ! "
    "queue max-size-time=100000000 leaky=downstream ! "
    "webrtcbin name=send bundle-policy=max-bundle";

    GError* error = nullptr;
    GstElement* pipeline = gst_parse_launch(pipeline_str.c_str(), &error);
    if (!pipeline) {
        RCLCPP_ERROR(node->get_logger(), "Falha ao criar pipeline: %s", error->message);
        g_error_free(error);
        return 1;
    }

    webrtc_send = gst_bin_get_by_name(GST_BIN(pipeline), "send");

    // Credenciais Metered
    std::string turn_user = "71715653733f5250dd465b78";
    std::string turn_pass = "KpBzzyrYWH6Ve6PG";
    std::string turn_host = "standard.relay.metered.ca";

    // --- CONFIGURAÇÃO ESPECÍFICA PARA GSTREAMER 1.14 (UBUNTU 18.04) ---

    // 1. STUN: Use g_object_set. O webrtcbin 1.14 aceita isso bem.
    g_object_set(webrtc_send, "stun-server", "stun://stun.relay.metered.ca:80", NULL);
    
    // 2. TURN: A "Bala de Prata".
    // No GStreamer 1.14, a propriedade "turn-server" aceita apenas UMA string.
    // Não tente adicionar vários. Vamos escolher a porta 80 porque é a que tem
    // maior chance de passar pelo NAT Simétrico e Firewall da universidade sem TLS.
    // Formato: turn://user:pass@host:port
    
    std::string turn_uri_80 = "turn://" + turn_user + ":" + turn_pass + "@" + turn_host + ":80";
    
    // ATENÇÃO: Usamos g_object_set, não signals. Signals falham no 1.14.
    g_object_set(webrtc_send, "turn-server", turn_uri_80.c_str(), NULL);


    g_signal_connect(webrtc_send, "notify::ice-connection-state", 
                     G_CALLBACK(on_ice_connection_state_notify), NULL);
    g_signal_connect(webrtc_send, "on-negotiation-needed", G_CALLBACK(on_negotiation_needed), nullptr);
    g_signal_connect(webrtc_send, "on-ice-candidate", G_CALLBACK(on_ice_candidate), nullptr);

    // -------------------- WebSocket --------------------
    std::string signaling_url = "ws://" + ipAddress + ":" + port + "/" + localId;
    ws.setUrl(signaling_url);

    ws.setOnMessageCallback([node](const ix::WebSocketMessagePtr &msg) {
        if (msg->type != ix::WebSocketMessageType::Message) return;

        try {
            json message = json::parse(msg->str);

            if (message["type"] == "answer") {

                RCLCPP_INFO(node->get_logger(), ">>> SDP tipo resposta recebido. Chamando callback (add_remote).");
                auto data = new AnswerData {
                    message["sdp"]
                };
                g_idle_add(add_remote_answer_idle, data); // thread safe
            }

            else if (message["type"] == "candidate") {

                RCLCPP_INFO(node->get_logger(), ">>> CANDIDATO ICE RECEBIDO. Chamando callback.");
                auto data = new IceCandidateData{
                    message["sdpMLineIndex"],
                    message["candidate"]
                };
                g_idle_add(add_ice_candidate_idle, data); // thread safe
            }
            else {
                RCLCPP_WARN(node->get_logger(), "Tipo de mensagem desconhecido: %s", message["type"].get<std::string>().c_str());
            }
        } catch (json::parse_error &) {
            RCLCPP_ERROR(node->get_logger(), "Entrada inválida: não é JSON.");
        }
    });

    ws.start();

    while (ws.getReadyState() != ix::ReadyState::Open) {
        RCLCPP_INFO(node->get_logger(), "Aguardando conexão WebSocket...");
        g_usleep(100000);
    }

    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    // -------------------- Thread do GStreamer --------------------
    gst_loop_handle = g_main_loop_new(nullptr, FALSE);
    std::thread gst_thread([&]() { g_main_loop_run(gst_loop_handle); });

    // -------------------- Executor ROS --------------------
    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);

    executor.spin(); // roda callbacks ROS

    // -------------------- Cleanup --------------------
    g_main_loop_quit(gst_loop_handle);
    gst_thread.join();
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);

    return 0;
}
