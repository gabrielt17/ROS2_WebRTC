// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gst_msgs:msg/FrameGate.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__FRAME_GATE__BUILDER_HPP_
#define GST_MSGS__MSG__DETAIL__FRAME_GATE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gst_msgs/msg/detail/frame_gate__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gst_msgs
{

namespace msg
{

namespace builder
{

class Init_FrameGate_mode
{
public:
  Init_FrameGate_mode()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gst_msgs::msg::FrameGate mode(::gst_msgs::msg::FrameGate::_mode_type arg)
  {
    msg_.mode = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gst_msgs::msg::FrameGate msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gst_msgs::msg::FrameGate>()
{
  return gst_msgs::msg::builder::Init_FrameGate_mode();
}

}  // namespace gst_msgs

#endif  // GST_MSGS__MSG__DETAIL__FRAME_GATE__BUILDER_HPP_
