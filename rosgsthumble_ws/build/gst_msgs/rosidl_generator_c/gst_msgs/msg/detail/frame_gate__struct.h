// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gst_msgs:msg/FrameGate.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__FRAME_GATE__STRUCT_H_
#define GST_MSGS__MSG__DETAIL__FRAME_GATE__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Constant 'DROP_ALL'.
enum
{
  gst_msgs__msg__FrameGate__DROP_ALL = 0
};

/// Constant 'PASS_ALL'.
enum
{
  gst_msgs__msg__FrameGate__PASS_ALL = 1
};

/// Constant 'PASS_ONE'.
enum
{
  gst_msgs__msg__FrameGate__PASS_ONE = 2
};

/// Struct defined in msg/FrameGate in the package gst_msgs.
/**
  * FrameGate.msg
 */
typedef struct gst_msgs__msg__FrameGate
{
  /// Gate Mode
  int8_t mode;
} gst_msgs__msg__FrameGate;

// Struct for a sequence of gst_msgs__msg__FrameGate.
typedef struct gst_msgs__msg__FrameGate__Sequence
{
  gst_msgs__msg__FrameGate * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gst_msgs__msg__FrameGate__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GST_MSGS__MSG__DETAIL__FRAME_GATE__STRUCT_H_
