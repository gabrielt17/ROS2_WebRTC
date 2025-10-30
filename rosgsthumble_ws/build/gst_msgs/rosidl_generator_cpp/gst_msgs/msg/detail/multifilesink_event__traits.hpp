// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gst_msgs:msg/MultifilesinkEvent.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__TRAITS_HPP_
#define GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gst_msgs/msg/detail/multifilesink_event__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__traits.hpp"

namespace gst_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const MultifilesinkEvent & msg,
  std::ostream & out)
{
  out << "{";
  // member: header
  {
    out << "header: ";
    to_flow_style_yaml(msg.header, out);
    out << ", ";
  }

  // member: filename
  {
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
    out << ", ";
  }

  // member: index
  {
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << ", ";
  }

  // member: timestamp
  {
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << ", ";
  }

  // member: stream_time
  {
    out << "stream_time: ";
    rosidl_generator_traits::value_to_yaml(msg.stream_time, out);
    out << ", ";
  }

  // member: running_time
  {
    out << "running_time: ";
    rosidl_generator_traits::value_to_yaml(msg.running_time, out);
    out << ", ";
  }

  // member: duration
  {
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << ", ";
  }

  // member: offset
  {
    out << "offset: ";
    rosidl_generator_traits::value_to_yaml(msg.offset, out);
    out << ", ";
  }

  // member: offset_end
  {
    out << "offset_end: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_end, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const MultifilesinkEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: header
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "header:\n";
    to_block_style_yaml(msg.header, out, indentation + 2);
  }

  // member: filename
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "filename: ";
    rosidl_generator_traits::value_to_yaml(msg.filename, out);
    out << "\n";
  }

  // member: index
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "index: ";
    rosidl_generator_traits::value_to_yaml(msg.index, out);
    out << "\n";
  }

  // member: timestamp
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "timestamp: ";
    rosidl_generator_traits::value_to_yaml(msg.timestamp, out);
    out << "\n";
  }

  // member: stream_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "stream_time: ";
    rosidl_generator_traits::value_to_yaml(msg.stream_time, out);
    out << "\n";
  }

  // member: running_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "running_time: ";
    rosidl_generator_traits::value_to_yaml(msg.running_time, out);
    out << "\n";
  }

  // member: duration
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "duration: ";
    rosidl_generator_traits::value_to_yaml(msg.duration, out);
    out << "\n";
  }

  // member: offset
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset: ";
    rosidl_generator_traits::value_to_yaml(msg.offset, out);
    out << "\n";
  }

  // member: offset_end
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "offset_end: ";
    rosidl_generator_traits::value_to_yaml(msg.offset_end, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const MultifilesinkEvent & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace gst_msgs

namespace rosidl_generator_traits
{

[[deprecated("use gst_msgs::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gst_msgs::msg::MultifilesinkEvent & msg,
  std::ostream & out, size_t indentation = 0)
{
  gst_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gst_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const gst_msgs::msg::MultifilesinkEvent & msg)
{
  return gst_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gst_msgs::msg::MultifilesinkEvent>()
{
  return "gst_msgs::msg::MultifilesinkEvent";
}

template<>
inline const char * name<gst_msgs::msg::MultifilesinkEvent>()
{
  return "gst_msgs/msg/MultifilesinkEvent";
}

template<>
struct has_fixed_size<gst_msgs::msg::MultifilesinkEvent>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gst_msgs::msg::MultifilesinkEvent>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gst_msgs::msg::MultifilesinkEvent>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__TRAITS_HPP_
