// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gst_msgs:msg/ClockObservation.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__CLOCK_OBSERVATION__STRUCT_H_
#define GST_MSGS__MSG__DETAIL__CLOCK_OBSERVATION__STRUCT_H_

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

/// Struct defined in msg/ClockObservation in the package gst_msgs.
typedef struct gst_msgs__msg__ClockObservation
{
  /// header containing the ros time and the frame_id the clock is tied to.
  std_msgs__msg__Header header;
  /// presentation time stamp according to the pipeline's internal clock
  uint64_t pipeline_time;
} gst_msgs__msg__ClockObservation;

// Struct for a sequence of gst_msgs__msg__ClockObservation.
typedef struct gst_msgs__msg__ClockObservation__Sequence
{
  gst_msgs__msg__ClockObservation * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gst_msgs__msg__ClockObservation__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GST_MSGS__MSG__DETAIL__CLOCK_OBSERVATION__STRUCT_H_
