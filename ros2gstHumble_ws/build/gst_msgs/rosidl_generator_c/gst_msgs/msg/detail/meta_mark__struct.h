// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gst_msgs:msg/MetaMark.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__META_MARK__STRUCT_H_
#define GST_MSGS__MSG__DETAIL__META_MARK__STRUCT_H_

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

/// Struct defined in msg/MetaMark in the package gst_msgs.
typedef struct gst_msgs__msg__MetaMark
{
  /// header containing the ros time and the frame_id the clock is tied to.
  std_msgs__msg__Header header;
  /// presentation time stamp on the buffer
  uint64_t buffer_pts;
  /// buffer pts from earlier in the pipeline
  uint64_t mark_timestamp;
} gst_msgs__msg__MetaMark;

// Struct for a sequence of gst_msgs__msg__MetaMark.
typedef struct gst_msgs__msg__MetaMark__Sequence
{
  gst_msgs__msg__MetaMark * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gst_msgs__msg__MetaMark__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GST_MSGS__MSG__DETAIL__META_MARK__STRUCT_H_
