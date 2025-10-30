// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from gst_msgs:srv/Seek.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__SRV__DETAIL__SEEK__TRAITS_HPP_
#define GST_MSGS__SRV__DETAIL__SEEK__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "gst_msgs/srv/detail/seek__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace gst_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Seek_Request & msg,
  std::ostream & out)
{
  out << "{";
  // member: seek_time
  {
    out << "seek_time: ";
    rosidl_generator_traits::value_to_yaml(msg.seek_time, out);
    out << ", ";
  }

  // member: flags
  {
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Seek_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: seek_time
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "seek_time: ";
    rosidl_generator_traits::value_to_yaml(msg.seek_time, out);
    out << "\n";
  }

  // member: flags
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "flags: ";
    rosidl_generator_traits::value_to_yaml(msg.flags, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Seek_Request & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace gst_msgs

namespace rosidl_generator_traits
{

[[deprecated("use gst_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gst_msgs::srv::Seek_Request & msg,
  std::ostream & out, size_t indentation = 0)
{
  gst_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gst_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const gst_msgs::srv::Seek_Request & msg)
{
  return gst_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gst_msgs::srv::Seek_Request>()
{
  return "gst_msgs::srv::Seek_Request";
}

template<>
inline const char * name<gst_msgs::srv::Seek_Request>()
{
  return "gst_msgs/srv/Seek_Request";
}

template<>
struct has_fixed_size<gst_msgs::srv::Seek_Request>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<gst_msgs::srv::Seek_Request>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<gst_msgs::srv::Seek_Request>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace gst_msgs
{

namespace srv
{

inline void to_flow_style_yaml(
  const Seek_Response & msg,
  std::ostream & out)
{
  out << "{";
  // member: success
  {
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << ", ";
  }

  // member: message
  {
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Seek_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: success
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "success: ";
    rosidl_generator_traits::value_to_yaml(msg.success, out);
    out << "\n";
  }

  // member: message
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    out << "message: ";
    rosidl_generator_traits::value_to_yaml(msg.message, out);
    out << "\n";
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Seek_Response & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace srv

}  // namespace gst_msgs

namespace rosidl_generator_traits
{

[[deprecated("use gst_msgs::srv::to_block_style_yaml() instead")]]
inline void to_yaml(
  const gst_msgs::srv::Seek_Response & msg,
  std::ostream & out, size_t indentation = 0)
{
  gst_msgs::srv::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use gst_msgs::srv::to_yaml() instead")]]
inline std::string to_yaml(const gst_msgs::srv::Seek_Response & msg)
{
  return gst_msgs::srv::to_yaml(msg);
}

template<>
inline const char * data_type<gst_msgs::srv::Seek_Response>()
{
  return "gst_msgs::srv::Seek_Response";
}

template<>
inline const char * name<gst_msgs::srv::Seek_Response>()
{
  return "gst_msgs/srv/Seek_Response";
}

template<>
struct has_fixed_size<gst_msgs::srv::Seek_Response>
  : std::integral_constant<bool, false> {};

template<>
struct has_bounded_size<gst_msgs::srv::Seek_Response>
  : std::integral_constant<bool, false> {};

template<>
struct is_message<gst_msgs::srv::Seek_Response>
  : std::true_type {};

}  // namespace rosidl_generator_traits

namespace rosidl_generator_traits
{

template<>
inline const char * data_type<gst_msgs::srv::Seek>()
{
  return "gst_msgs::srv::Seek";
}

template<>
inline const char * name<gst_msgs::srv::Seek>()
{
  return "gst_msgs/srv/Seek";
}

template<>
struct has_fixed_size<gst_msgs::srv::Seek>
  : std::integral_constant<
    bool,
    has_fixed_size<gst_msgs::srv::Seek_Request>::value &&
    has_fixed_size<gst_msgs::srv::Seek_Response>::value
  >
{
};

template<>
struct has_bounded_size<gst_msgs::srv::Seek>
  : std::integral_constant<
    bool,
    has_bounded_size<gst_msgs::srv::Seek_Request>::value &&
    has_bounded_size<gst_msgs::srv::Seek_Response>::value
  >
{
};

template<>
struct is_service<gst_msgs::srv::Seek>
  : std::true_type
{
};

template<>
struct is_service_request<gst_msgs::srv::Seek_Request>
  : std::true_type
{
};

template<>
struct is_service_response<gst_msgs::srv::Seek_Response>
  : std::true_type
{
};

}  // namespace rosidl_generator_traits

#endif  // GST_MSGS__SRV__DETAIL__SEEK__TRAITS_HPP_
