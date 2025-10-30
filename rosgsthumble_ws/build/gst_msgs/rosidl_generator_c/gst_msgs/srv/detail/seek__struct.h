// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from gst_msgs:srv/Seek.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__SRV__DETAIL__SEEK__STRUCT_H_
#define GST_MSGS__SRV__DETAIL__SEEK__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

/// Struct defined in srv/Seek in the package gst_msgs.
typedef struct gst_msgs__srv__Seek_Request
{
  /// nanoseconds from beginning of media
  int64_t seek_time;
  /// not yet implemented (nearest keyframe, flush data, etc)
  int32_t flags;
} gst_msgs__srv__Seek_Request;

// Struct for a sequence of gst_msgs__srv__Seek_Request.
typedef struct gst_msgs__srv__Seek_Request__Sequence
{
  gst_msgs__srv__Seek_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gst_msgs__srv__Seek_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'message'
#include "rosidl_runtime_c/string.h"

/// Struct defined in srv/Seek in the package gst_msgs.
typedef struct gst_msgs__srv__Seek_Response
{
  /// indicate successful run of triggered service
  bool success;
  /// informational, e.g. for error messages
  rosidl_runtime_c__String message;
} gst_msgs__srv__Seek_Response;

// Struct for a sequence of gst_msgs__srv__Seek_Response.
typedef struct gst_msgs__srv__Seek_Response__Sequence
{
  gst_msgs__srv__Seek_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} gst_msgs__srv__Seek_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // GST_MSGS__SRV__DETAIL__SEEK__STRUCT_H_
