// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gst_msgs:msg/MetaMark.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__META_MARK__BUILDER_HPP_
#define GST_MSGS__MSG__DETAIL__META_MARK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gst_msgs/msg/detail/meta_mark__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gst_msgs
{

namespace msg
{

namespace builder
{

class Init_MetaMark_mark_timestamp
{
public:
  explicit Init_MetaMark_mark_timestamp(::gst_msgs::msg::MetaMark & msg)
  : msg_(msg)
  {}
  ::gst_msgs::msg::MetaMark mark_timestamp(::gst_msgs::msg::MetaMark::_mark_timestamp_type arg)
  {
    msg_.mark_timestamp = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gst_msgs::msg::MetaMark msg_;
};

class Init_MetaMark_buffer_pts
{
public:
  explicit Init_MetaMark_buffer_pts(::gst_msgs::msg::MetaMark & msg)
  : msg_(msg)
  {}
  Init_MetaMark_mark_timestamp buffer_pts(::gst_msgs::msg::MetaMark::_buffer_pts_type arg)
  {
    msg_.buffer_pts = std::move(arg);
    return Init_MetaMark_mark_timestamp(msg_);
  }

private:
  ::gst_msgs::msg::MetaMark msg_;
};

class Init_MetaMark_header
{
public:
  Init_MetaMark_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MetaMark_buffer_pts header(::gst_msgs::msg::MetaMark::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MetaMark_buffer_pts(msg_);
  }

private:
  ::gst_msgs::msg::MetaMark msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gst_msgs::msg::MetaMark>()
{
  return gst_msgs::msg::builder::Init_MetaMark_header();
}

}  // namespace gst_msgs

#endif  // GST_MSGS__MSG__DETAIL__META_MARK__BUILDER_HPP_
