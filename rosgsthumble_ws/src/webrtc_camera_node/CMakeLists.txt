cmake_minimum_required(VERSION 3.22)
project(webrtc_camera_node)

# --- Dependências ---
find_package(PkgConfig REQUIRED)

# Pacotes ROS2
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(gst_bridge REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED)

# GStreamer: REMOVIDO 'gstreamer-webrtc-1.0' desta lista para evitar erro
pkg_check_modules(GST REQUIRED 
    gstreamer-1.0
    gstreamer-app-1.0
    gstreamer-video-1.0
    gstreamer-sdp-1.0
    glib-2.0
)

# --- BUSCA MANUAL DO WEBRTC ---
# Como removemos o pacote de dev do 'bad-plugins', achamos a lib manualmente
find_library(GST_WEBRTC_LIB 
    NAMES gstwebrtc-1.0 
    PATHS /usr/lib/aarch64-linux-gnu /usr/lib /usr/local/lib
)

if(NOT GST_WEBRTC_LIB)
    message(FATAL_ERROR "Biblioteca gstwebrtc-1.0 não encontrada! Verifique se gstreamer1.0-plugins-bad está instalado.")
endif()

message(STATUS "WebRTC Library Found: ${GST_WEBRTC_LIB}")

include(FetchContent)

# --- FetchContent (Mantido igual) ---
FetchContent_Declare(
  nlohmann_json GIT_REPOSITORY https://github.com/nlohmann/json.git GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(nlohmann_json) 

FetchContent_Declare(
  ixwebsocket GIT_REPOSITORY https://github.com/machinezone/IXWebSocket.git GIT_TAG v11.4.6
)
FetchContent_MakeAvailable(ixwebsocket)

# --- Alvo 1: send_camera_node ---
add_executable(send_camera_node src/send_camera_node.cpp)

target_include_directories(send_camera_node PUBLIC
  ${GST_INCLUDE_DIRS}
)

target_link_libraries(send_camera_node
  ${GST_LIBRARIES}
  ${GST_WEBRTC_LIB}    # <--- Adicionado Manualmente
  nlohmann_json::nlohmann_json
  ixwebsocket
  Threads::Threads
  OpenSSL::SSL
  OpenSSL::Crypto
)

ament_target_dependencies(send_camera_node
  rclcpp
  sensor_msgs
  gst_bridge
)

# --- Alvo 2: receive_camera_node ---
add_executable(receive_camera_node src/receive_camera_node.cpp)

target_include_directories(receive_camera_node PUBLIC
  ${GST_INCLUDE_DIRS}
)

target_link_libraries(receive_camera_node
  ${GST_LIBRARIES}
  ${GST_WEBRTC_LIB}    # <--- Adicionado Manualmente
  nlohmann_json::nlohmann_json
  ixwebsocket
  Threads::Threads
  OpenSSL::SSL
  OpenSSL::Crypto
)

ament_target_dependencies(receive_camera_node
  rclcpp
  sensor_msgs
  gst_bridge
)

# --- Instalação ---
install(TARGETS 
  send_camera_node
  receive_camera_node
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()