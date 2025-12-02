// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gst_msgs:srv/Seek.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__SRV__DETAIL__SEEK__BUILDER_HPP_
#define GST_MSGS__SRV__DETAIL__SEEK__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gst_msgs/srv/detail/seek__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gst_msgs
{

namespace srv
{

namespace builder
{

class Init_Seek_Request_flags
{
public:
  explicit Init_Seek_Request_flags(::gst_msgs::srv::Seek_Request & msg)
  : msg_(msg)
  {}
  ::gst_msgs::srv::Seek_Request flags(::gst_msgs::srv::Seek_Request::_flags_type arg)
  {
    msg_.flags = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gst_msgs::srv::Seek_Request msg_;
};

class Init_Seek_Request_seek_time
{
public:
  Init_Seek_Request_seek_time()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Seek_Request_flags seek_time(::gst_msgs::srv::Seek_Request::_seek_time_type arg)
  {
    msg_.seek_time = std::move(arg);
    return Init_Seek_Request_flags(msg_);
  }

private:
  ::gst_msgs::srv::Seek_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gst_msgs::srv::Seek_Request>()
{
  return gst_msgs::srv::builder::Init_Seek_Request_seek_time();
}

}  // namespace gst_msgs


namespace gst_msgs
{

namespace srv
{

namespace builder
{

class Init_Seek_Response_message
{
public:
  explicit Init_Seek_Response_message(::gst_msgs::srv::Seek_Response & msg)
  : msg_(msg)
  {}
  ::gst_msgs::srv::Seek_Response message(::gst_msgs::srv::Seek_Response::_message_type arg)
  {
    msg_.message = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gst_msgs::srv::Seek_Response msg_;
};

class Init_Seek_Response_success
{
public:
  Init_Seek_Response_success()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Seek_Response_message success(::gst_msgs::srv::Seek_Response::_success_type arg)
  {
    msg_.success = std::move(arg);
    return Init_Seek_Response_message(msg_);
  }

private:
  ::gst_msgs::srv::Seek_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::gst_msgs::srv::Seek_Response>()
{
  return gst_msgs::srv::builder::Init_Seek_Response_success();
}

}  // namespace gst_msgs

#endif  // GST_MSGS__SRV__DETAIL__SEEK__BUILDER_HPP_
