cmake_minimum_required(VERSION 3.22)
project(webrtc_camera_node)

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

# --- Dependências via FetchContent ---

# nlohmann/json
FetchContent_Declare(
  nlohmann_json GIT_REPOSITORY https://github.com/nlohmann/json.git GIT_TAG v3.11.3
)
FetchContent_MakeAvailable(nlohmann_json) 

# ixwebsocket (substitui cpp-httplib)
FetchContent_Declare(
  ixwebsocket GIT_REPOSITORY https://github.com/machinezone/IXWebSocket.git GIT_TAG v11.4.6
)
FetchContent_MakeAvailable(ixwebsocket)

add_executable(camera_webrtc_node src/camera_webrtc_node.cpp)

# Include directories
include_directories(
  ${GST_INCLUDE_DIRS}
)

# Link libraries
target_link_libraries(camera_webrtc_node
  ${GST_LIBRARIES}
  nlohmann_json::nlohmann_json # JSON
  ixwebsocket                  # WebSocket client
  Threads::Threads             # Threads
  OpenSSL::SSL                 # SSL para WSS
  OpenSSL::Crypto              # Crypto para WSS
)

# Dependências ROS2
ament_target_dependencies(camera_webrtc_node
  rclcpp
  sensor_msgs
  gst_bridge
)

install(TARGETS camera_webrtc_node
  DESTINATION lib/${PROJECT_NAME})

ament_package()
