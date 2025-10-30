// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gst_msgs:msg/MultifilesinkEvent.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__STRUCT_H_
#define GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__STRUCT_H_

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
// Member 'filename'
#include "rosidl_runtime_c/string.h"

/// Struct defined in msg/MultifilesinkEvent in the package gst_msgs.
/**
  * ROS2 Analogue of GstMultiFileSink
  * https://gstreamer.freedesktop.org/documentation/multifile/multifilesink.html?gi-language=c
 */
typedef struct gst_msgs__msg__MultifilesinkEvent
{
  std_msgs__msg__Header header;
  /// the filename where the buffer was written.
  rosidl_runtime_c__String filename;
  /// index of the buffer.
  int32_t index;
  /// the timestamp of the buffer.
  uint64_t timestamp;
  /// the stream time of the buffer.
  uint64_t stream_time;
  /// the running_time of the buffer.
  uint64_t running_time;
  /// the duration of the buffer.
  uint64_t duration;
  /// the offset of the buffer that triggered the message.
  uint64_t offset;
  /// the offset-end of the buffer that triggered the message.
  uint64_t offset_end;
} gst_msgs__msg__MultifilesinkEvent;

// Struct for a sequence of gst_msgs__msg__MultifilesinkEvent.
typedef struct gst_msgs__msg__MultifilesinkEvent__Sequence
{
  gst_msgs__msg__MultifilesinkEvent * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gst_msgs__msg__MultifilesinkEvent__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__STRUCT_H_
