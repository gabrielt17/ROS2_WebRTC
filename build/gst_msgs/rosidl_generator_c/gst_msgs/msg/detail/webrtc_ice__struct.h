// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gst_msgs:msg/WebrtcIce.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__WEBRTC_ICE__STRUCT_H_
#define GST_MSGS__MSG__DETAIL__WEBRTC_ICE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.h"
// Member 'candidate'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/WebrtcIce in the package gst_msgs.
typedef struct gst_msgs__msg__WebrtcIce
{
  std_msgs__msg__Header header;
  /// ouptut of the webrtc ice candidates signal
  int64_t mline_index;
  rosidl_runtime_c__String candidate;
} gst_msgs__msg__WebrtcIce;

// Struct for a sequence of gst_msgs__msg__WebrtcIce.
typedef struct gst_msgs__msg__WebrtcIce__Sequence
{
  gst_msgs__msg__WebrtcIce * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gst_msgs__msg__WebrtcIce__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GST_MSGS__MSG__DETAIL__WEBRTC_ICE__STRUCT_H_
