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
std::string ipAddress = "192.168.0.131";
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

struct OfferData {
    std::string sdp_text;
};

gboolean add_remote_offer_idle(gpointer data) {
    OfferData* d = static_cast<OfferData*>(data);

    GstSDPMessage *sdp = nullptr;
    gst_sdp_message_new(&sdp);
    gst_sdp_message_parse_buffer((const guint8*)d->sdp_text.c_str(), d->sdp_text.size(), sdp);
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

    auto node = rclcpp::Node::make_shared("receive_camera_node");
    
    // Callback de segurança para quando o ROS morrer
    rclcpp::on_shutdown([&]() {
        // Se já parou, chamar stop de novo não tem problema
        ws.stop();
        if (gst_loop_handle && g_main_loop_is_running(gst_loop_handle)) {
            g_main_loop_quit(gst_loop_handle);
        }
    });

    node->declare_parameter<std::string>("camera_topic", "/received_camera/image_raw");
    std::string camera_topic;
    node->get_parameter("camera_topic", camera_topic);
    RCLCPP_INFO(node->get_logger(), "Transmitindo vídeo no tópico: %s", camera_topic.c_str());

    std::string pipeline_str =
        "webrtcbin name=recv bundle-policy=max-bundle latency=100 "
        "rtpvp8depay name=depay ! "
        "queue max-size-buffers=1 leaky=downstream ! "
        "vp8dec ! "
        "videoconvert ! "
        "rosimagesink ros-topic=\"" + camera_topic + "\"";

    GError* error = nullptr;
    GstElement* pipeline = gst_parse_launch(pipeline_str.c_str(), &error);
    if (!pipeline) {
        RCLCPP_ERROR(node->get_logger(), "Falha ao criar pipeline: %s", error->message);
        g_error_free(error);
        return 1;
    }

    webrtc_recv = gst_bin_get_by_name(GST_BIN(pipeline), "recv");

    g_object_set(webrtc_recv, "stun-server", "stun://stun.relay.metered.ca:80", NULL);
    gst_element_set_state(pipeline, GST_STATE_READY);
    
    // Variáveis para facilitar a montagem
    std::string turn_user = "71715653733f5250dd465b78";
    std::string turn_pass = "KpBzzyrYWH6Ve6PG";
    std::string turn_host = "standard.relay.metered.ca";

    // Opção A: TURN na porta 80 (Geralmente passa como HTTP)
    std::string turn_uri_80 = "turn://" + turn_user + ":" + turn_pass + "@" + turn_host + ":80";
    g_signal_emit_by_name(webrtc_recv, "add-turn-server", turn_uri_80.c_str(), NULL);

    // Opção B: TURN na porta 443 (Geralmente passa como HTTPS)
    std::string turn_uri_443 = "turn://" + turn_user + ":" + turn_pass + "@" + turn_host + ":443";
    g_signal_emit_by_name(webrtc_recv, "add-turn-server", turn_uri_443.c_str(), NULL);

    // Opção C: TURNS (Secure/Encrypted TURN) na porta 443
    // Isso é a "arma nuclear" contra firewalls. O tráfego é criptografado via TLS,
    // então o firewall da universidade não consegue distinguir isso de um acesso a banco ou gmail.
    std::string turns_uri = "turns://" + turn_user + ":" + turn_pass + "@" + turn_host + ":443";
    g_signal_emit_by_name(webrtc_recv, "add-turn-server", turns_uri.c_str(), NULL);

    g_signal_connect(webrtc_recv, "notify::ice-connection-state", 
                     G_CALLBACK(on_ice_connection_state_notify), NULL);
    g_signal_connect(webrtc_recv, "on-ice-candidate", G_CALLBACK(on_ice_candidate), nullptr);
    g_signal_connect(webrtc_recv, "pad-added", G_CALLBACK(on_pad_added), pipeline);

    std::string signaling_url;
    // Solução da porta 80 (mantida conforme seu último sucesso parcial)
    if (port == "443") {
        signaling_url = "wss://" + ipAddress + "/" + localId;
    } else {
        signaling_url = "ws://" + ipAddress + ":" + port + "/" + localId;
    }
    
    RCLCPP_INFO(node->get_logger(), "Conectando em: %s", signaling_url.c_str());
    ws.setUrl(signaling_url);

    ix::WebSocketHttpHeaders headers;
    headers["ngrok-skip-browser-warning"] = "true";
    ws.setExtraHeaders(headers);

    ix::SocketTLSOptions tlsOptions;
    tlsOptions.caFile = "NONE"; 
    ws.setTLSOptions(tlsOptions);

    ws.setOnMessageCallback([node](const ix::WebSocketMessagePtr &msg) {
        if (msg->type == ix::WebSocketMessageType::Open) {
            RCLCPP_INFO(node->get_logger(), ">>> WEBSOCKET CONECTADO! <<<");
        }
        else if (msg->type == ix::WebSocketMessageType::Error) {
            RCLCPP_ERROR(node->get_logger(), "FALHA CONEXÃO: %s", msg->errorInfo.reason.c_str());
            RCLCPP_ERROR(node->get_logger(), "Status HTTP: %d", msg->errorInfo.http_status);
        }
        else if (msg->type == ix::WebSocketMessageType::Close) {
            RCLCPP_WARN(node->get_logger(), "Conexão Fechada: %d %s", msg->closeInfo.code, msg->closeInfo.reason.c_str());
        }
        else if (msg->type == ix::WebSocketMessageType::Message) {
            try {
                json message = json::parse(msg->str);

                if (message["type"] == "offer") {
                    auto data = new OfferData { message["sdp"] };
                    RCLCPP_INFO(node->get_logger(), "--> Oferta Recebida.");
                    if (data->sdp_text.length() > 0) {
                        g_idle_add(add_remote_offer_idle, data);
                    }
                } 
                else if (message["type"] == "candidate") {
                    auto data = new IceCandidateData{
                        message["sdpMLineIndex"],
                        message["candidate"]
                    };
                    g_idle_add(add_ice_candidate_idle, data);
                }
            } catch (json::parse_error &) {
                RCLCPP_ERROR(node->get_logger(), "JSON Inválido recebido.");
            }
        }
    });
    
    ws.start();

    // ---------------------------------------------------------
    // CORREÇÃO CRÍTICA DO LOOP DE ESPERA
    // ---------------------------------------------------------
    
    // Usa rclcpp::Rate para garantir que sinais do sistema (Ctrl+C) sejam processados
    rclcpp::Rate loop_rate(10); // 10Hz (verifica a cada 100ms)
    int wait_attempts = 0;

    while (ws.getReadyState() != ix::ReadyState::Open && rclcpp::ok()) {
        if (wait_attempts % 10 == 0) {
            RCLCPP_INFO(node->get_logger(), "Aguardando WebSocket... (%ds)", wait_attempts/10);
        }
        wait_attempts++;
        loop_rate.sleep(); // Isso permite o ROS processar callbacks e sinais
    }

    // SE O LOOP QUEBROU POR CAUSA DO CTRL+C (rclcpp::ok() == false)
    if (!rclcpp::ok()) {
        RCLCPP_WARN(node->get_logger(), "Interrupção detectada. Encerrando WebSocket...");
        ws.stop(); // <--- OBRIGATÓRIO: Mata a thread de conexão antes do destrutor
        
        gst_element_set_state(pipeline, GST_STATE_NULL);
        gst_object_unref(pipeline);
        rclcpp::shutdown();
        return 0;
    }

    // ---------------------------------------------------------

    gst_element_set_state(pipeline, GST_STATE_PLAYING);

    gst_loop_handle = g_main_loop_new(nullptr, FALSE);
    std::thread gst_thread([&]() { g_main_loop_run(gst_loop_handle); });

    rclcpp::executors::MultiThreadedExecutor executor;
    executor.add_node(node);
    executor.spin(); 

    // Cleanup padrão
    if (gst_thread.joinable()) gst_thread.join();
    
    // Stop explícito aqui também ajuda
    ws.stop();
    
    gst_element_set_state(pipeline, GST_STATE_NULL);
    gst_object_unref(pipeline);
    g_main_loop_unref(gst_loop_handle);
    rclcpp::shutdown();

    return 0;
}