// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gst_msgs:msg/MultifilesinkEvent.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__BUILDER_HPP_
#define GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gst_msgs/msg/detail/multifilesink_event__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gst_msgs
{

namespace msg
{

namespace builder
{

class Init_MultifilesinkEvent_offset_end
{
public:
  explicit Init_MultifilesinkEvent_offset_end(::gst_msgs::msg::MultifilesinkEvent & msg)
  : msg_(msg)
  {}
  ::gst_msgs::msg::MultifilesinkEvent offset_end(::gst_msgs::msg::MultifilesinkEvent::_offset_end_type arg)
  {
    msg_.offset_end = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gst_msgs::msg::MultifilesinkEvent msg_;
};

class Init_MultifilesinkEvent_offset
{
public:
  explicit Init_MultifilesinkEvent_offset(::gst_msgs::msg::MultifilesinkEvent & msg)
  : msg_(msg)
  {}
  Init_MultifilesinkEvent_offset_end offset(::gst_msgs::msg::MultifilesinkEvent::_offset_type arg)
  {
    msg_.offset = std::move(arg);
    return Init_MultifilesinkEvent_offset_end(msg_);
  }

private:
  ::gst_msgs::msg::MultifilesinkEvent msg_;
};

class Init_MultifilesinkEvent_duration
{
public:
  explicit Init_MultifilesinkEvent_duration(::gst_msgs::msg::MultifilesinkEvent & msg)
  : msg_(msg)
  {}
  Init_MultifilesinkEvent_offset duration(::gst_msgs::msg::MultifilesinkEvent::_duration_type arg)
  {
    msg_.duration = std::move(arg);
    return Init_MultifilesinkEvent_offset(msg_);
  }

private:
  ::gst_msgs::msg::MultifilesinkEvent msg_;
};

class Init_MultifilesinkEvent_running_time
{
public:
  explicit Init_MultifilesinkEvent_running_time(::gst_msgs::msg::MultifilesinkEvent & msg)
  : msg_(msg)
  {}
  Init_MultifilesinkEvent_duration running_time(::gst_msgs::msg::MultifilesinkEvent::_running_time_type arg)
  {
    msg_.running_time = std::move(arg);
    return Init_MultifilesinkEvent_duration(msg_);
  }

private:
  ::gst_msgs::msg::MultifilesinkEvent msg_;
};

class Init_MultifilesinkEvent_stream_time
{
public:
  explicit Init_MultifilesinkEvent_stream_time(::gst_msgs::msg::MultifilesinkEvent & msg)
  : msg_(msg)
  {}
  Init_MultifilesinkEvent_running_time stream_time(::gst_msgs::msg::MultifilesinkEvent::_stream_time_type arg)
  {
    msg_.stream_time = std::move(arg);
    return Init_MultifilesinkEvent_running_time(msg_);
  }

private:
  ::gst_msgs::msg::MultifilesinkEvent msg_;
};

class Init_MultifilesinkEvent_timestamp
{
public:
  explicit Init_MultifilesinkEvent_timestamp(::gst_msgs::msg::MultifilesinkEvent & msg)
  : msg_(msg)
  {}
  Init_MultifilesinkEvent_stream_time timestamp(::gst_msgs::msg::MultifilesinkEvent::_timestamp_type arg)
  {
    msg_.timestamp = std::move(arg);
    return Init_MultifilesinkEvent_stream_time(msg_);
  }

private:
  ::gst_msgs::msg::MultifilesinkEvent msg_;
};

class Init_MultifilesinkEvent_index
{
public:
  explicit Init_MultifilesinkEvent_index(::gst_msgs::msg::MultifilesinkEvent & msg)
  : msg_(msg)
  {}
  Init_MultifilesinkEvent_timestamp index(::gst_msgs::msg::MultifilesinkEvent::_index_type arg)
  {
    msg_.index = std::move(arg);
    return Init_MultifilesinkEvent_timestamp(msg_);
  }

private:
  ::gst_msgs::msg::MultifilesinkEvent msg_;
};

class Init_MultifilesinkEvent_filename
{
public:
  explicit Init_MultifilesinkEvent_filename(::gst_msgs::msg::MultifilesinkEvent & msg)
  : msg_(msg)
  {}
  Init_MultifilesinkEvent_index filename(::gst_msgs::msg::MultifilesinkEvent::_filename_type arg)
  {
    msg_.filename = std::move(arg);
    return Init_MultifilesinkEvent_index(msg_);
  }

private:
  ::gst_msgs::msg::MultifilesinkEvent msg_;
};

class Init_MultifilesinkEvent_header
{
public:
  Init_MultifilesinkEvent_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_MultifilesinkEvent_filename header(::gst_msgs::msg::MultifilesinkEvent::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_MultifilesinkEvent_filename(msg_);
  }

private:
  ::gst_msgs::msg::MultifilesinkEvent msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gst_msgs::msg::MultifilesinkEvent>()
{
  return gst_msgs::msg::builder::Init_MultifilesinkEvent_header();
}

}  // namespace gst_msgs

#endif  // GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__BUILDER_HPP_
