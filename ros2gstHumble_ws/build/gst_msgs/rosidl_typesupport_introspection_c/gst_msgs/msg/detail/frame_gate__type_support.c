// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from gst_msgs:msg/FrameGate.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "gst_msgs/msg/detail/frame_gate__rosidl_typesupport_introspection_c.h"
#include "gst_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "gst_msgs/msg/detail/frame_gate__functions.h"
#include "gst_msgs/msg/detail/frame_gate__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void gst_msgs__msg__FrameGate__rosidl_typesupport_introspection_c__FrameGate_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  gst_msgs__msg__FrameGate__init(message_memory);
}

void gst_msgs__msg__FrameGate__rosidl_typesupport_introspection_c__FrameGate_fini_function(void * message_memory)
{
  gst_msgs__msg__FrameGate__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember gst_msgs__msg__FrameGate__rosidl_typesupport_introspection_c__FrameGate_message_member_array[1] = {
  {
    "mode",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(gst_msgs__msg__FrameGate, mode),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers gst_msgs__msg__FrameGate__rosidl_typesupport_introspection_c__FrameGate_message_members = {
  "gst_msgs__msg",  // message namespace
  "FrameGate",  // message name
  1,  // number of fields
  sizeof(gst_msgs__msg__FrameGate),
  gst_msgs__msg__FrameGate__rosidl_typesupport_introspection_c__FrameGate_message_member_array,  // message members
  gst_msgs__msg__FrameGate__rosidl_typesupport_introspection_c__FrameGate_init_function,  // function to initialize message memory (memory has to be allocated)
  gst_msgs__msg__FrameGate__rosidl_typesupport_introspection_c__FrameGate_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t gst_msgs__msg__FrameGate__rosidl_typesupport_introspection_c__FrameGate_message_type_support_handle = {
  0,
  &gst_msgs__msg__FrameGate__rosidl_typesupport_introspection_c__FrameGate_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_gst_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, gst_msgs, msg, FrameGate)() {
  if (!gst_msgs__msg__FrameGate__rosidl_typesupport_introspection_c__FrameGate_message_type_support_handle.typesupport_identifier) {
    gst_msgs__msg__FrameGate__rosidl_typesupport_introspection_c__FrameGate_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &gst_msgs__msg__FrameGate__rosidl_typesupport_introspection_c__FrameGate_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
