// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gst_msgs:msg/MultifilesinkEvent.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__FUNCTIONS_H_
#define GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gst_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "gst_msgs/msg/detail/multifilesink_event__struct.h"

/// Initialize msg/MultifilesinkEvent message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gst_msgs__msg__MultifilesinkEvent
 * )) before or use
 * gst_msgs__msg__MultifilesinkEvent__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__MultifilesinkEvent__init(gst_msgs__msg__MultifilesinkEvent * msg);

/// Finalize msg/MultifilesinkEvent message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
void
gst_msgs__msg__MultifilesinkEvent__fini(gst_msgs__msg__MultifilesinkEvent * msg);

/// Create msg/MultifilesinkEvent message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gst_msgs__msg__MultifilesinkEvent__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
gst_msgs__msg__MultifilesinkEvent *
gst_msgs__msg__MultifilesinkEvent__create();

/// Destroy msg/MultifilesinkEvent message.
/**
 * It calls
 * gst_msgs__msg__MultifilesinkEvent__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
void
gst_msgs__msg__MultifilesinkEvent__destroy(gst_msgs__msg__MultifilesinkEvent * msg);

/// Check for msg/MultifilesinkEvent message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__MultifilesinkEvent__are_equal(const gst_msgs__msg__MultifilesinkEvent * lhs, const gst_msgs__msg__MultifilesinkEvent * rhs);

/// Copy a msg/MultifilesinkEvent message.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source message pointer.
 * \param[out] output The target message pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer is null
 *   or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__MultifilesinkEvent__copy(
  const gst_msgs__msg__MultifilesinkEvent * input,
  gst_msgs__msg__MultifilesinkEvent * output);

/// Initialize array of msg/MultifilesinkEvent messages.
/**
 * It allocates the memory for the number of elements and calls
 * gst_msgs__msg__MultifilesinkEvent__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__MultifilesinkEvent__Sequence__init(gst_msgs__msg__MultifilesinkEvent__Sequence * array, size_t size);

/// Finalize array of msg/MultifilesinkEvent messages.
/**
 * It calls
 * gst_msgs__msg__MultifilesinkEvent__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
void
gst_msgs__msg__MultifilesinkEvent__Sequence__fini(gst_msgs__msg__MultifilesinkEvent__Sequence * array);

/// Create array of msg/MultifilesinkEvent messages.
/**
 * It allocates the memory for the array and calls
 * gst_msgs__msg__MultifilesinkEvent__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
gst_msgs__msg__MultifilesinkEvent__Sequence *
gst_msgs__msg__MultifilesinkEvent__Sequence__create(size_t size);

/// Destroy array of msg/MultifilesinkEvent messages.
/**
 * It calls
 * gst_msgs__msg__MultifilesinkEvent__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
void
gst_msgs__msg__MultifilesinkEvent__Sequence__destroy(gst_msgs__msg__MultifilesinkEvent__Sequence * array);

/// Check for msg/MultifilesinkEvent message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__MultifilesinkEvent__Sequence__are_equal(const gst_msgs__msg__MultifilesinkEvent__Sequence * lhs, const gst_msgs__msg__MultifilesinkEvent__Sequence * rhs);

/// Copy an array of msg/MultifilesinkEvent messages.
/**
 * This functions performs a deep copy, as opposed to the shallow copy that
 * plain assignment yields.
 *
 * \param[in] input The source array pointer.
 * \param[out] output The target array pointer, which must
 *   have been initialized before calling this function.
 * \return true if successful, or false if either pointer
 *   is null or memory allocation fails.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__MultifilesinkEvent__Sequence__copy(
  const gst_msgs__msg__MultifilesinkEvent__Sequence * input,
  gst_msgs__msg__MultifilesinkEvent__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__FUNCTIONS_H_
