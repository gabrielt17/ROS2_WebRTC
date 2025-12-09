// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from gst_msgs:msg/FrameGate.idl
// generated code does not contain a copyright notice
#include "gst_msgs/msg/detail/frame_gate__rosidl_typesupport_fastrtps_cpp.hpp"
#include "gst_msgs/msg/detail/frame_gate__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions

namespace gst_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gst_msgs
cdr_serialize(
  const gst_msgs::msg::FrameGate & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: mode
  cdr << ros_message.mode;
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gst_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  gst_msgs::msg::FrameGate & ros_message)
{
  // Member: mode
  cdr >> ros_message.mode;

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gst_msgs
get_serialized_size(
  const gst_msgs::msg::FrameGate & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: mode
  {
    size_t item_size = sizeof(ros_message.mode);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_gst_msgs
max_serialized_size_FrameGate(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: mode
  {
    size_t array_size = 1;

    current_alignment += array_size * sizeof(uint8_t);
  }

  return current_alignment - initial_alignment;
}

static bool _FrameGate__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const gst_msgs::msg::FrameGate *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _FrameGate__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<gst_msgs::msg::FrameGate *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _FrameGate__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const gst_msgs::msg::FrameGate *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _FrameGate__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_FrameGate(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _FrameGate__callbacks = {
  "gst_msgs::msg",
  "FrameGate",
  _FrameGate__cdr_serialize,
  _FrameGate__cdr_deserialize,
  _FrameGate__get_serialized_size,
  _FrameGate__max_serialized_size
};

static rosidl_message_type_support_t _FrameGate__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_FrameGate__callbacks,
  get_message_typesupport_handle_function,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace gst_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_gst_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<gst_msgs::msg::FrameGate>()
{
  return &gst_msgs::msg::typesupport_fastrtps_cpp::_FrameGate__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, gst_msgs, msg, FrameGate)() {
  return &gst_msgs::msg::typesupport_fastrtps_cpp::_FrameGate__handle;
}

#ifdef __cplusplus
}
#endif
