// generated from rosidl_generator_c/resource/idl__functions.h.em
// with input from gst_msgs:msg/MetaMark.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__META_MARK__FUNCTIONS_H_
#define GST_MSGS__MSG__DETAIL__META_MARK__FUNCTIONS_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stdlib.h>

#include "rosidl_runtime_c/visibility_control.h"
#include "gst_msgs/msg/rosidl_generator_c__visibility_control.h"

#include "gst_msgs/msg/detail/meta_mark__struct.h"

/// Initialize msg/MetaMark message.
/**
 * If the init function is called twice for the same message without
 * calling fini inbetween previously allocated memory will be leaked.
 * \param[in,out] msg The previously allocated message pointer.
 * Fields without a default value will not be initialized by this function.
 * You might want to call memset(msg, 0, sizeof(
 * gst_msgs__msg__MetaMark
 * )) before or use
 * gst_msgs__msg__MetaMark__create()
 * to allocate and initialize the message.
 * \return true if initialization was successful, otherwise false
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__MetaMark__init(gst_msgs__msg__MetaMark * msg);

/// Finalize msg/MetaMark message.
/**
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
void
gst_msgs__msg__MetaMark__fini(gst_msgs__msg__MetaMark * msg);

/// Create msg/MetaMark message.
/**
 * It allocates the memory for the message, sets the memory to zero, and
 * calls
 * gst_msgs__msg__MetaMark__init().
 * \return The pointer to the initialized message if successful,
 * otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
gst_msgs__msg__MetaMark *
gst_msgs__msg__MetaMark__create();

/// Destroy msg/MetaMark message.
/**
 * It calls
 * gst_msgs__msg__MetaMark__fini()
 * and frees the memory of the message.
 * \param[in,out] msg The allocated message pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
void
gst_msgs__msg__MetaMark__destroy(gst_msgs__msg__MetaMark * msg);

/// Check for msg/MetaMark message equality.
/**
 * \param[in] lhs The message on the left hand size of the equality operator.
 * \param[in] rhs The message on the right hand size of the equality operator.
 * \return true if messages are equal, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__MetaMark__are_equal(const gst_msgs__msg__MetaMark * lhs, const gst_msgs__msg__MetaMark * rhs);

/// Copy a msg/MetaMark message.
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
gst_msgs__msg__MetaMark__copy(
  const gst_msgs__msg__MetaMark * input,
  gst_msgs__msg__MetaMark * output);

/// Initialize array of msg/MetaMark messages.
/**
 * It allocates the memory for the number of elements and calls
 * gst_msgs__msg__MetaMark__init()
 * for each element of the array.
 * \param[in,out] array The allocated array pointer.
 * \param[in] size The size / capacity of the array.
 * \return true if initialization was successful, otherwise false
 * If the array pointer is valid and the size is zero it is guaranteed
 # to return true.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__MetaMark__Sequence__init(gst_msgs__msg__MetaMark__Sequence * array, size_t size);

/// Finalize array of msg/MetaMark messages.
/**
 * It calls
 * gst_msgs__msg__MetaMark__fini()
 * for each element of the array and frees the memory for the number of
 * elements.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
void
gst_msgs__msg__MetaMark__Sequence__fini(gst_msgs__msg__MetaMark__Sequence * array);

/// Create array of msg/MetaMark messages.
/**
 * It allocates the memory for the array and calls
 * gst_msgs__msg__MetaMark__Sequence__init().
 * \param[in] size The size / capacity of the array.
 * \return The pointer to the initialized array if successful, otherwise NULL
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
gst_msgs__msg__MetaMark__Sequence *
gst_msgs__msg__MetaMark__Sequence__create(size_t size);

/// Destroy array of msg/MetaMark messages.
/**
 * It calls
 * gst_msgs__msg__MetaMark__Sequence__fini()
 * on the array,
 * and frees the memory of the array.
 * \param[in,out] array The initialized array pointer.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
void
gst_msgs__msg__MetaMark__Sequence__destroy(gst_msgs__msg__MetaMark__Sequence * array);

/// Check for msg/MetaMark message array equality.
/**
 * \param[in] lhs The message array on the left hand size of the equality operator.
 * \param[in] rhs The message array on the right hand size of the equality operator.
 * \return true if message arrays are equal in size and content, otherwise false.
 */
ROSIDL_GENERATOR_C_PUBLIC_gst_msgs
bool
gst_msgs__msg__MetaMark__Sequence__are_equal(const gst_msgs__msg__MetaMark__Sequence * lhs, const gst_msgs__msg__MetaMark__Sequence * rhs);

/// Copy an array of msg/MetaMark messages.
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
gst_msgs__msg__MetaMark__Sequence__copy(
  const gst_msgs__msg__MetaMark__Sequence * input,
  gst_msgs__msg__MetaMark__Sequence * output);

#ifdef __cplusplus
}
#endif

#endif  // GST_MSGS__MSG__DETAIL__META_MARK__FUNCTIONS_H_
