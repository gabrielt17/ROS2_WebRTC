// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gst_msgs:msg/BufferEvent.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__BUFFER_EVENT__STRUCT_H_
#define GST_MSGS__MSG__DETAIL__BUFFER_EVENT__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in msg/BufferEvent in the package gst_msgs.
typedef struct gst_msgs__msg__BufferEvent
{
  /// presentation time stamp according to the pipeline's internal clock
  uint64_t buffer_pts;
} gst_msgs__msg__BufferEvent;

// Struct for a sequence of gst_msgs__msg__BufferEvent.
typedef struct gst_msgs__msg__BufferEvent__Sequence
{
  gst_msgs__msg__BufferEvent * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gst_msgs__msg__BufferEvent__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GST_MSGS__MSG__DETAIL__BUFFER_EVENT__STRUCT_H_
