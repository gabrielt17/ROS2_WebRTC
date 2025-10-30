// generated from rosidl_typesupport_introspection_cpp/resource/idl__type_support.cpp.em
// with input from gst_msgs:msg/WebrtcIce.idl
// generated code does not contain a copyright notice

#include "array"
#include "cstddef"
#include "string"
#include "vector"
#include "rosidl_runtime_c/message_type_support_struct.h"
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_interface/macros.h"
#include "gst_msgs/msg/detail/webrtc_ice__struct.hpp"
#include "rosidl_typesupport_introspection_cpp/field_types.hpp"
#include "rosidl_typesupport_introspection_cpp/identifier.hpp"
#include "rosidl_typesupport_introspection_cpp/message_introspection.hpp"
#include "rosidl_typesupport_introspection_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_introspection_cpp/visibility_control.h"

namespace gst_msgs
{

namespace msg
{

namespace rosidl_typesupport_introspection_cpp
{

void WebrtcIce_init_function(
  void * message_memory, rosidl_runtime_cpp::MessageInitialization _init)
{
  new (message_memory) gst_msgs::msg::WebrtcIce(_init);
}

void WebrtcIce_fini_function(void * message_memory)
{
  auto typed_message = static_cast<gst_msgs::msg::WebrtcIce *>(message_memory);
  typed_message->~WebrtcIce();
}

static const ::rosidl_typesupport_introspection_cpp::MessageMember WebrtcIce_message_member_array[3] = {
  {
    "header",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    ::rosidl_typesupport_introspection_cpp::get_message_type_support_handle<std_msgs::msg::Header>(),  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gst_msgs::msg::WebrtcIce, header),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "mline_index",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_INT64,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gst_msgs::msg::WebrtcIce, mline_index),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  },
  {
    "candidate",  // name
    ::rosidl_typesupport_introspection_cpp::ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    nullptr,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gst_msgs::msg::WebrtcIce, candidate),  // bytes offset in struct
    nullptr,  // default value
    nullptr,  // size() function pointer
    nullptr,  // get_const(index) function pointer
    nullptr,  // get(index) function pointer
    nullptr,  // fetch(index, &value) function pointer
    nullptr,  // assign(index, value) function pointer
    nullptr  // resize(index) function pointer
  }
};

static const ::rosidl_typesupport_introspection_cpp::MessageMembers WebrtcIce_message_members = {
  "gst_msgs::msg",  // message namespace
  "WebrtcIce",  // message name
  3,  // number of fields
  sizeof(gst_msgs::msg::WebrtcIce),
  WebrtcIce_message_member_array,  // message members
  WebrtcIce_init_function,  // function to initialize message memory (memory has to be allocated)
  WebrtcIce_fini_function  // function to terminate message instance (will not free memory)
};

static const rosidl_message_type_support_t WebrtcIce_message_type_support_handle = {
  ::rosidl_typesupport_introspection_cpp::typesupport_identifier,
  &WebrtcIce_message_members,
  get_message_typesupport_handle_function,
};

}  // namespace rosidl_typesupport_introspection_cpp

}  // namespace msg

}  // namespace gst_msgs


namespace rosidl_typesupport_introspection_cpp
{

template<>
ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
get_message_type_support_handle<gst_msgs::msg::WebrtcIce>()
{
  return &::gst_msgs::msg::rosidl_typesupport_introspection_cpp::WebrtcIce_message_type_support_handle;
}

}  // namespace rosidl_typesupport_introspection_cpp

#ifdef __cplusplus
extern "C"
{
#endif

ROSIDL_TYPESUPPORT_INTROSPECTION_CPP_PUBLIC
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_cpp, gst_msgs, msg, WebrtcIce)() {
  return &::gst_msgs::msg::rosidl_typesupport_introspection_cpp::WebrtcIce_message_type_support_handle;
}

#ifdef __cplusplus
}
#endif
