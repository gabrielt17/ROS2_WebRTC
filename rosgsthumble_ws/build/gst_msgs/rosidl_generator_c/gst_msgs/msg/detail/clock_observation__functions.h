// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gst_msgs:msg/ClockObservation.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__CLOCK_OBSERVATION__FUNCTIONS_H_
#define GST_MSGS__MSG__DETAIL__CLOCK_OBSERVATION__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gst_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "gst_msgs/msg/detail/clock_observation__struct.h"

/// Initialize msg/ClockObservation message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gst_msgs__msg__ClockObservation
 * )) before or use
 * gst_msgs__msg__ClockObservation__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__ClockObservation__init(gst_msgs__msg__ClockObservation * msg);

/// Finalize msg/ClockObservation message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
void
gst_msgs__msg__ClockObservation__fini(gst_msgs__msg__ClockObservation * msg);

/// Create msg/ClockObservation message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gst_msgs__msg__ClockObservation__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
gst_msgs__msg__ClockObservation *
gst_msgs__msg__ClockObservation__create();

/// Destroy msg/ClockObservation message.
/**
 * It calls
 * gst_msgs__msg__ClockObservation__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
void
gst_msgs__msg__ClockObservation__destroy(gst_msgs__msg__ClockObservation * msg);

/// Check for msg/ClockObservation message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__ClockObservation__are_equal(const gst_msgs__msg__ClockObservation * lhs, const gst_msgs__msg__ClockObservation * rhs);

/// Copy a msg/ClockObservation message.
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
gst_msgs__msg__ClockObservation__copy(
  const gst_msgs__msg__ClockObservation * input,
  gst_msgs__msg__ClockObservation * output);

/// Initialize array of msg/ClockObservation messages.
/**
 * It allocates the memory for the number of elements and calls
 * gst_msgs__msg__ClockObservation__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__ClockObservation__Sequence__init(gst_msgs__msg__ClockObservation__Sequence * array, size_t size);

/// Finalize array of msg/ClockObservation messages.
/**
 * It calls
 * gst_msgs__msg__ClockObservation__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
void
gst_msgs__msg__ClockObservation__Sequence__fini(gst_msgs__msg__ClockObservation__Sequence * array);

/// Create array of msg/ClockObservation messages.
/**
 * It allocates the memory for the array and calls
 * gst_msgs__msg__ClockObservation__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
gst_msgs__msg__ClockObservation__Sequence *
gst_msgs__msg__ClockObservation__Sequence__create(size_t size);

/// Destroy array of msg/ClockObservation messages.
/**
 * It calls
 * gst_msgs__msg__ClockObservation__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
void
gst_msgs__msg__ClockObservation__Sequence__destroy(gst_msgs__msg__ClockObservation__Sequence * array);

/// Check for msg/ClockObservation message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__ClockObservation__Sequence__are_equal(const gst_msgs__msg__ClockObservation__Sequence * lhs, const gst_msgs__msg__ClockObservation__Sequence * rhs);

/// Copy an array of msg/ClockObservation messages.
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
gst_msgs__msg__ClockObservation__Sequence__copy(
  const gst_msgs__msg__ClockObservation__Sequence * input,
  gst_msgs__msg__ClockObservation__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GST_MSGS__MSG__DETAIL__CLOCK_OBSERVATION__FUNCTIONS_H_
