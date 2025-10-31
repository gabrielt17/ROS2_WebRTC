// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gst_msgs:msg/FrameGate.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__FRAME_GATE__TRAITS_HPP_
#define GST_MSGS__MSG__DETAIL__FRAME_GATE__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gst_msgs/msg/detail/frame_gate__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace gst_msgs
{

namespace msg
{

inline void to_flow_style_yaml(
  const FrameGate & msg,
  std::ostream & out)
{
  out << "{";
  // member: mode
  {
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const FrameGate & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: mode
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "mode: ";
    rosidl_generator_traits::value_to_yaml(msg.mode, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const FrameGate & msg, bool use_flow_style = false)
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
  const gst_msgs::msg::FrameGate & msg,
  std::ostream & out, size_t indentation = 0)
{
  gst_msgs::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gst_msgs::msg::to_yaml() instead")]]
inline std::string to_yaml(const gst_msgs::msg::FrameGate & msg)
{
  return gst_msgs::msg::to_yaml(msg);
}

template<>
inline const char * data_type<gst_msgs::msg::FrameGate>()
{
  return "gst_msgs::msg::FrameGate";
}

template<>
inline const char * name<gst_msgs::msg::FrameGate>()
{
  return "gst_msgs/msg/FrameGate";
}

template<>
struct has_fixed_size<gst_msgs::msg::FrameGate>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gst_msgs::msg::FrameGate>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gst_msgs::msg::FrameGate>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // GST_MSGS__MSG__DETAIL__FRAME_GATE__TRAITS_HPP_
