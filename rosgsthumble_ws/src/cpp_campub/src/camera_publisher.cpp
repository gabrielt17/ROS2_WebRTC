#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include "cv_bridge/cv_bridge.h"
#include <opencv2/opencv.hpp>

class CameraPublisher : public rclcpp::Node
{
public:
  CameraPublisher()
  : Node("camera_publisher")
  {
    // Declara parâmetros
    this->declare_parameter<std::string>("device", "/dev/video0");
    this->declare_parameter<std::string>("topic", "camera/image_raw");
    this->declare_parameter<int>("width", 800);
    this->declare_parameter<int>("height", 480);
    this->declare_parameter<double>("fps", 30.0);

    device_ = this->get_parameter("device").as_string();
    topic_ = this->get_parameter("topic").as_string();
    width_ = this->get_parameter("width").as_int();
    height_ = this->get_parameter("height").as_int();
    fps_ = this->get_parameter("fps").as_double();

    // Inicializa câmera
    cap_.open(device_, cv::CAP_V4L2);
    if (!cap_.isOpened()) {
      RCLCPP_ERROR(this->get_logger(), "Falha ao abrir dispositivo: %s", device_.c_str());
      rclcpp::shutdown();
      return;
    }

    cap_.set(cv::CAP_PROP_FRAME_WIDTH, width_);
    cap_.set(cv::CAP_PROP_FRAME_HEIGHT, height_);
    cap_.set(cv::CAP_PROP_FPS, fps_);

    publisher_ = this->create_publisher<sensor_msgs::msg::Image>(topic_, 10);
    timer_ = this->create_wall_timer(
      std::chrono::milliseconds(static_cast<int>(1000.0 / fps_)),
      std::bind(&CameraPublisher::publish_frame, this)
    );

    RCLCPP_INFO(this->get_logger(), "Publicando %s em %s (%.0fx%.0f @ %.1f FPS)",
      device_.c_str(), topic_.c_str(), (double)width_, (double)height_, fps_);
  }

private:
  void publish_frame()
  {
    cv::Mat frame;
    cap_ >> frame;
    if (frame.empty()) {
      RCLCPP_WARN(this->get_logger(), "Frame vazio recebido da câmera.");
      return;
    }

    std_msgs::msg::Header header;
    header.stamp = this->now();
    header.frame_id = "camera_frame";

    cv_bridge::CvImage cv_image(header, "bgr8", frame);
    publisher_->publish(*cv_image.toImageMsg());
  }

  std::string device_;
  std::string topic_;
  int width_;
  int height_;
  double fps_;

  cv::VideoCapture cap_;
  rclcpp::Publisher<sensor_msgs::msg::Image>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char *argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CameraPublisher>());
  rclcpp::shutdown();
  return 0;
}