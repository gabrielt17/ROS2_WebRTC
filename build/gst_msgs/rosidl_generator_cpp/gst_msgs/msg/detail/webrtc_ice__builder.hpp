// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gst_msgs:msg/WebrtcIce.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__WEBRTC_ICE__BUILDER_HPP_
#define GST_MSGS__MSG__DETAIL__WEBRTC_ICE__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gst_msgs/msg/detail/webrtc_ice__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gst_msgs
{

namespace msg
{

namespace builder
{

class Init_WebrtcIce_candidate
{
public:
  explicit Init_WebrtcIce_candidate(::gst_msgs::msg::WebrtcIce & msg)
  : msg_(msg)
  {}
  ::gst_msgs::msg::WebrtcIce candidate(::gst_msgs::msg::WebrtcIce::_candidate_type arg)
  {
    msg_.candidate = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gst_msgs::msg::WebrtcIce msg_;
};

class Init_WebrtcIce_mline_index
{
public:
  explicit Init_WebrtcIce_mline_index(::gst_msgs::msg::WebrtcIce & msg)
  : msg_(msg)
  {}
  Init_WebrtcIce_candidate mline_index(::gst_msgs::msg::WebrtcIce::_mline_index_type arg)
  {
    msg_.mline_index = std::move(arg);
    return Init_WebrtcIce_candidate(msg_);
  }

private:
  ::gst_msgs::msg::WebrtcIce msg_;
};

class Init_WebrtcIce_header
{
public:
  Init_WebrtcIce_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_WebrtcIce_mline_index header(::gst_msgs::msg::WebrtcIce::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_WebrtcIce_mline_index(msg_);
  }

private:
  ::gst_msgs::msg::WebrtcIce msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gst_msgs::msg::WebrtcIce>()
{
  return gst_msgs::msg::builder::Init_WebrtcIce_header();
}

}  // namespace gst_msgs

#endif  // GST_MSGS__MSG__DETAIL__WEBRTC_ICE__BUILDER_HPP_
