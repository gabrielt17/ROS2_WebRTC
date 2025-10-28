cmake_minimum_required(VERSION 3.8)
project(cpp_campub)

# Encontrar pacotes ROS 2 e OpenCV
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(cv_bridge REQUIRED)
find_package(OpenCV REQUIRED)

# Criar executável
add_executable(camera_publisher src/camera_publisher.cpp)

# Declarar dependências do executável
ament_target_dependencies(camera_publisher
  rclcpp
  sensor_msgs
  cv_bridge
  OpenCV
)

# Instalar executável para ros2 run
install(TARGETS camera_publisher
  DESTINATION lib/${PROJECT_NAME}
)

# Registrar pacote ROS 2
ament_package()
