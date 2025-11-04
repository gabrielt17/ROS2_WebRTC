cmake_minimum_required(VERSION 3.22)
project(webrtc_camera_node)

# --- Dependências (Sem alterações) ---
# Necessário para pkg_check_modules
find_package(PkgConfig REQUIRED)

# Pacotes ROS2
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(gst_bridge REQUIRED)
find_package(Threads REQUIRED)
find_package(OpenSSL REQUIRED) # Necessário para WSS (ixwebsocket usa)

# GStreamer
pkg_check_modules(GST REQUIRED 
    gstreamer-1.0
    gstreamer-webrtc-1.0
    gstreamer-app-1.0
    gstreamer-video-1.0
    gstreamer-sdp-1.0
    glib-2.0
)

include(FetchContent)

# --- Dependências via FetchContent (Sem alterações) ---

# nlohmann/json
FetchContent_Declare(
  nlohmann_json GIT_REPOSITORY https://github.com/nlohmann/json.git GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(nlohmann_json) 

# ixwebsocket
FetchContent_Declare(
  ixwebsocket GIT_REPOSITORY https://github.com/machinezone/IXWebSocket.git GIT_TAG v11.4.6
)
FetchContent_MakeAvailable(ixwebsocket)


# --- Alvo 1: send_camera_node ---
add_executable(send_camera_node src/send_camera_node.cpp)

# Define os includes (forma moderna)
target_include_directories(send_camera_node PUBLIC
  ${GST_INCLUDE_DIRS}
)

# Link das bibliotecas
target_link_libraries(send_camera_node
  ${GST_LIBRARIES}
  nlohmann_json::nlohmann_json # JSON
  ixwebsocket                  # WebSocket client
  Threads::Threads             # Threads
  OpenSSL::SSL                 # SSL para WSS
  OpenSSL::Crypto              # Crypto para WSS
)

# Dependências ROS2
ament_target_dependencies(send_camera_node
  rclcpp
  sensor_msgs
  gst_bridge
)

# --- Alvo 2: receive_camera_node (NOVO) ---
add_executable(receive_camera_node src/receive_camera_node.cpp)

# Define os includes (forma moderna)
target_include_directories(receive_camera_node PUBLIC
  ${GST_INCLUDE_DIRS}
)

# Link das bibliotecas (provavelmente idênticas)
target_link_libraries(receive_camera_node
  ${GST_LIBRARIES}
  nlohmann_json::nlohmann_json # JSON
  ixwebsocket                  # WebSocket client
  Threads::Threads             # Threads
  OpenSSL::SSL                 # SSL para WSS
  OpenSSL::Crypto              # Crypto para WSS
)

# Dependências ROS2 (assumindo que o receiver também é um nó)
# Nota: Se o seu receiver não for publicar a imagem no ROS, 
# você pode remover sensor_msgs e gst_bridge daqui.
ament_target_dependencies(receive_camera_node
  rclcpp
  sensor_msgs
  gst_bridge
)


# --- Instalação (MODIFICADO) ---
install(TARGETS 
  send_camera_node
  receive_camera_node  # Adiciona o novo alvo à instalação
  DESTINATION lib/${PROJECT_NAME}
)

ament_package()