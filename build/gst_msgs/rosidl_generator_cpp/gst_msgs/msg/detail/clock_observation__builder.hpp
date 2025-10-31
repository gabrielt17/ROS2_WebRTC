// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from gst_msgs:msg/ClockObservation.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__CLOCK_OBSERVATION__BUILDER_HPP_
#define GST_MSGS__MSG__DETAIL__CLOCK_OBSERVATION__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "gst_msgs/msg/detail/clock_observation__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace gst_msgs
{

namespace msg
{

namespace builder
{

class Init_ClockObservation_pipeline_time
{
public:
  explicit Init_ClockObservation_pipeline_time(::gst_msgs::msg::ClockObservation & msg)
  : msg_(msg)
  {}
  ::gst_msgs::msg::ClockObservation pipeline_time(::gst_msgs::msg::ClockObservation::_pipeline_time_type arg)
  {
    msg_.pipeline_time = std::move(arg);
    return std::move(msg_);
  }

private:
  ::gst_msgs::msg::ClockObservation msg_;
};

class Init_ClockObservation_header
{
public:
  Init_ClockObservation_header()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_ClockObservation_pipeline_time header(::gst_msgs::msg::ClockObservation::_header_type arg)
  {
    msg_.header = std::move(arg);
    return Init_ClockObservation_pipeline_time(msg_);
  }

private:
  ::gst_msgs::msg::ClockObservation msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::gst_msgs::msg::ClockObservation>()
{
  return gst_msgs::msg::builder::Init_ClockObservation_header();
}

}  // namespace gst_msgs

#endif  // GST_MSGS__MSG__DETAIL__CLOCK_OBSERVATION__BUILDER_HPP_
