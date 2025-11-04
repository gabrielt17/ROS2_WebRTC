#define GST_USE_UNSTABLE_API

#include <rclcpp/rclcpp.hpp>
#include <sensor_msgs/msg/image.hpp>
#include <cstdio>
#include <iostream>
#include <gst/gst.h>
#include <gst/sdp/sdp.h>
#include <gst/webrtc/webrtc.h>
#include <glib.h>
#include <nlohmann/json.hpp>
#include <ixwebsocket/IXWebSocket.h>

using json = nlohmann::json;

// Variáveis globais
std::string ipAddress = "localhost";
std::string port = "8000";
std::string localId = "alice"; // ID local do remetente
std::string remoteId = "gabrielt"; // ID remoto do destinatário

// Objeto principal do WebRTC
GstElement *webrtc_recv = nullptr;

// Objeto WebSocket para comunicação
ix::WebSocket ws;

GMainLoop* gst_loop_handle;
std::atomic<bool> running(true);

static void on_answer_created(GstPromise *promise, gpointer) {
    const GstStructure *reply = gst_promise_get_reply(promise);
    GstWebRTCSessionDescription *answer = nullptr;

    gst_structure_get(reply, "answer", GST_TYPE_WEBRTC_SESSION_DESCRIPTION, &answer, nullptr);
    g_signal_emit_by_name(webrtc_recv, "set-local-description", answer, nullptr);

    gchar *sdp_text = gst_sdp_message_as_text(answer->sdp);
    json sdp_answer = {
        {"id", remoteId},
        {"type", "answer"},
        {"sdp", sdp_text}
    };
    ws.send(sdp_answer.dump());
    std::cout << "\n>>> RESPOSTA GERADA:\n" << sdp_answer.dump() << std::endl;

    g_free(sdp_text);
    gst_webrtc_session_description_free(answer);
    gst_promise_unref(promise);
}

static void on_ice_candidate(GstElement *, guint mline_index, gchar *candidate) {
    json ice_candidate = {
        {"id", remoteId},
        {"type", "candidate"},
        {"candidate", candidate},
        {"sdpMLineIndex", mline_index}
    };
    ws.send(ice_candidate.dump());
    std::cout << "\n>>> CANDIDATO ICE GERADO:\n" << ice_candidate.dump() << std::endl;
}

static void on_pad_added(GstElement *, GstPad *pad, GstElement *pipeline) {
    RCLCPP_INFO(rclcpp::get_logger("receive_camera_node"), "Pad dinâmico recebido...");

    // 1. Pegar as "caps" (capacidades) do pad para inspecioná-lo
    GstCaps *caps = gst_pad_get_current_caps(pad);
    // Fallback se get_current_caps não funcionar (pipeline pode não estar rodando)
    if (!caps) {
        caps = gst_pad_query_caps(pad, NULL);
    }
    const gchar *caps_str = gst_caps_to_string(caps);

    RCLCPP_INFO(rclcpp::get_logger("receive_camera_node"), "  -> Caps: %s", caps_str);

    // 2. Verificar se é o pad de vídeo VP8 que queremos.
    // O pad de saída do webrtcbin para VP8 é 'application/x-rtp' 
    // com encoding-name='VP8'.
    if (g_str_has_prefix(caps_str, "application/x-rtp") && strstr(caps_str, "VP8")) {
        
        RCLCPP_INFO(rclcpp::get_logger("receive_camera_node"), "  -> É um pad VP8. Linkando...");

        // 3. Pegar o 'depay' (só se for VP8)
        GstElement *depay = gst_bin_get_by_name(GST_BIN(pipeline), "depay");
        GstPad *sinkpad = gst_element_get_static_pad(depay, "sink");

        // 4. Linkar
        if (gst_pad_link(pad, sinkpad) != GST_PAD_LINK_OK) {
            RCLCPP_ERROR(rclcpp::get_logger("receive_camera_node"), "Falha ao linkar pad de VÍDEO.\n");
        } else {
            RCLCPP_INFO(rclcpp::get_logger("receive_camera_node"), "  -> Linkagem de VÍDEO bem-sucedida.");
        }

        gst_object_unref(sinkpad);
        gst_object_unref(depay);

    } else {
        RCLCPP_INFO(rclcpp::get_logger("receive_camera_node"), "  -> Ignorando pad (provavelmente áudio ou outro formato).");
    }

    // 5. Limpar
    g_free((gpointer)caps_str);
    gst_caps_unref(caps);
}

// -------------------- Helper para thread safety --------------------
struct IceCandidateData {
    guint mline_index;
    std::string candidate;
};

gboolean add_ice_candidate_idle(gpointer data) {
    IceCandidateData* d = static_cast<IceCandidateData*>(data);
    g_signal_emit_by_name(webrtc_recv, "add-ice-candidate", d->mline_index, d->candidate.c_str());
    delete d;
    return G_SOURCE_REMOVE;
}

struct OfferData {
    std::string sdp_text;
};

gboolean add_remote_offer_idle(gpointer data) {
    OfferData* d = static_cast<OfferData*>(data);

    GstSDPMessage *sdp = nullptr;
    gst_sdp_message_new_from_text(d->sdp_text.c_str(), &sdp);
    GstWebRTCSessionDescription *offer = gst_webrtc_session_description_new(GST_WEBRTC_SDP_TYPE_OFFER, sdp);
    
    RCLCPP_INFO(rclcpp::get_logger("camera_webrtc_node"), ">>> OFERTA SDP RECEBIDA. Configurando descrição remota...");
    g_signal_emit_by_name(webrtc_recv, "set-remote-description", offer, NULL);
    
    gst_webrtc_session_description_free(offer);
    delete d;

    RCLCPP_INFO(rclcpp::get_logger("receive_camera_node"), ">>> Criando Resposta (Answer)...");
    GstPromise *promise = gst_promise_new_with_change_func(on_answer_created, nullptr, nullptr);
    g_signal_emit_by_name(webrtc_recv, "create-answer", nullptr, promise);

    return G_SOURCE_REMOVE;
}

// -------------------- Handler para SIGINT --------------------
void sigint_handler(int) {
    running = false;
    g_main_loop_quit(gst_loop_handle);
    rclcpp::shutdown();
}

// -------------------- Main --------------------

int main(int argc, char *argv[]) {

    rclcpp::init(argc, argv);
    gst_init(nullptr, nullptr);

    signal(SIGINT, sigint_handler);

    auto node = rclcpp::Node::make_shared("receive_camera_node");

    node->declare_parameter<std::string>("camera_topic", "/received_camera/image_raw");
    std::string camera_topic;
    node->get_parameter("camera_topic", camera_topic);
    RCLCPP_INFO(node->get_logger(), "Transmitindo vídeo no tópico: %s", camera_topic.c_str());

    std::string pipeline_str =
        "webrtcbin name=recv "
        "rtpvp8depay name=depay ! "
        "vp8dec ! "
        "videoconvert ! "
        "rosimagesink ros-topic=\"" + camera_topic + "\"";

    // Sinaliza problemas na construção da pipeline
    GError* error = nullptr;
    GstElement* pipeline = gst_parse_launch(pipeline_str.c_str(), &error);
    if (!pipeline) {
        RCLCPP_ERROR(node->get_logger(), "Falha ao criar pipeline: %s", error->message);
        g_error_free(error);
        return 1;
    }

    // Isola o elemento webrtcbin em um objeto global
    webrtc_recv = gst_bin_get_by_name(GST_BIN(pipeline), "recv");
    gst_element_set_state(pipeline, GST_STATE_READY);
    gst_element_get_state(pipeline, nullptr, nullptr, GST_CLOCK_TIME_NONE);

    // Associa sinais do webrtcbin a funções de callback
    g_signal_connect(webrtc_recv, "on-ice-candidate", G_CALLBACK(on_ice_candidate), nullptr);
    g_signal_connect(webrtc_recv, "pad-added", G_CALLBACK(on_pad_added), pipeline);

    std::string signaling_url = "ws://" + ipAddress + ":" + port + "/" + localId; // URL do servidor de sinalização
    ws.setUrl(signaling_url);

    ws.setOnMessageCallback([&](const ix::WebSocketMessagePtr &msg) {
        if (msg->type == ix::WebSocketMessageType::Message) {

            try {
                // Tenta analisar a mensagem JSON
                json message = json::parse(msg->str);

                // Verifica o tipo de mensagem
                if (message["type"] == "offer") {

                    auto data = new OfferData {
                    message["sdp"]
                    };

                    RCLCPP_INFO(node->get_logger(), "--> Recebida Oferta SDP, checando integridade");
                    GstSDPMessage *sdp = nullptr;
                    if (gst_sdp_message_new_from_text(data->sdp_text.c_str(), &sdp) == GST_SDP_OK) {
                        g_idle_add(add_remote_offer_idle, data);
                        RCLCPP_INFO(node->get_logger(), "--> Oferta SDP configurada.\n");

                    } else {
                        RCLCPP_ERROR(node->get_logger(), "Falha ao analisar SDP da oferta.\n");
                    }

                } else if (message["type"] == "candidate") {

                    auto data = new IceCandidateData{
                    message["sdpMLineIndex"],
                    message["candidate"]
                    };
                    g_idle_add(add_ice_candidate_idle, data); // thread safe

                } else {
                    RCLCPP_ERROR(node->get_logger(), "---!> Tipo de mensagem desconhecido: %s\n", message["type"].get<std::string>().c_str());
                }
            } catch (json::parse_error &) {
                RCLCPP_ERROR(node->get_logger(), "--!> Entrada inválida: não é JSON.\n");
            }
        }
    });
    
    // Inicia a conexão WebSocket
    ws.start();

    // Aguarda até que a conexão WebSocket esteja aberta
    while (ws.getReadyState() != ix::ReadyState::Open) {
        RCLCPP_INFO(node->get_logger(), "--> Aguardando conexão WebSocket...\n");
        g_usleep(100000); // Espera até que a conexão esteja aberta
    }

    // Inicia a pipeline
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