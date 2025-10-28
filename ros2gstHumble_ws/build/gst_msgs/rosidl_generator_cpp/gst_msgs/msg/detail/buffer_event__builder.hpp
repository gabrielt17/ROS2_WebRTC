// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gst_msgs:msg/BufferEvent.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__BUFFER_EVENT__BUILDER_HPP_
#define GST_MSGS__MSG__DETAIL__BUFFER_EVENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gst_msgs/msg/detail/buffer_event__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gst_msgs
{

namespace msg
{

namespace builder
{

class Init_BufferEvent_buffer_pts
{
public:
  Init_BufferEvent_buffer_pts()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::gst_msgs::msg::BufferEvent buffer_pts(::gst_msgs::msg::BufferEvent::_buffer_pts_type arg)
  {
    msg_.buffer_pts = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gst_msgs::msg::BufferEvent msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gst_msgs::msg::BufferEvent>()
{
  return gst_msgs::msg::builder::Init_BufferEvent_buffer_pts();
}

}  // namespace gst_msgs

#endif  // GST_MSGS__MSG__DETAIL__BUFFER_EVENT__BUILDER_HPP_
