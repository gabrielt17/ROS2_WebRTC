// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gst_msgs:msg/BufferEvent.idl
// generated code does not contain a copyright notice
#include "gst_msgs/msg/detail/buffer_event__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
gst_msgs__msg__BufferEvent__init(gst_msgs__msg__BufferEvent * msg)
{
  if (!msg) {
    return false;
  }
  // buffer_pts
  return true;
}

void
gst_msgs__msg__BufferEvent__fini(gst_msgs__msg__BufferEvent * msg)
{
  if (!msg) {
    return;
  }
  // buffer_pts
}

bool
gst_msgs__msg__BufferEvent__are_equal(const gst_msgs__msg__BufferEvent * lhs, const gst_msgs__msg__BufferEvent * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // buffer_pts
  if (lhs->buffer_pts != rhs->buffer_pts) {
    return false;
  }
  return true;
}

bool
gst_msgs__msg__BufferEvent__copy(
  const gst_msgs__msg__BufferEvent * input,
  gst_msgs__msg__BufferEvent * output)
{
  if (!input || !output) {
    return false;
  }
  // buffer_pts
  output->buffer_pts = input->buffer_pts;
  return true;
}

gst_msgs__msg__BufferEvent *
gst_msgs__msg__BufferEvent__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__msg__BufferEvent * msg = (gst_msgs__msg__BufferEvent *)allocator.allocate(sizeof(gst_msgs__msg__BufferEvent), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gst_msgs__msg__BufferEvent));
  bool success = gst_msgs__msg__BufferEvent__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gst_msgs__msg__BufferEvent__destroy(gst_msgs__msg__BufferEvent * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gst_msgs__msg__BufferEvent__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gst_msgs__msg__BufferEvent__Sequence__init(gst_msgs__msg__BufferEvent__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__msg__BufferEvent * data = NULL;

  if (size) {
    data = (gst_msgs__msg__BufferEvent *)allocator.zero_allocate(size, sizeof(gst_msgs__msg__BufferEvent), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gst_msgs__msg__BufferEvent__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gst_msgs__msg__BufferEvent__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
gst_msgs__msg__BufferEvent__Sequence__fini(gst_msgs__msg__BufferEvent__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      gst_msgs__msg__BufferEvent__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

gst_msgs__msg__BufferEvent__Sequence *
gst_msgs__msg__BufferEvent__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__msg__BufferEvent__Sequence * array = (gst_msgs__msg__BufferEvent__Sequence *)allocator.allocate(sizeof(gst_msgs__msg__BufferEvent__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gst_msgs__msg__BufferEvent__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gst_msgs__msg__BufferEvent__Sequence__destroy(gst_msgs__msg__BufferEvent__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gst_msgs__msg__BufferEvent__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gst_msgs__msg__BufferEvent__Sequence__are_equal(const gst_msgs__msg__BufferEvent__Sequence * lhs, const gst_msgs__msg__BufferEvent__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gst_msgs__msg__BufferEvent__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gst_msgs__msg__BufferEvent__Sequence__copy(
  const gst_msgs__msg__BufferEvent__Sequence * input,
  gst_msgs__msg__BufferEvent__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gst_msgs__msg__BufferEvent);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gst_msgs__msg__BufferEvent * data =
      (gst_msgs__msg__BufferEvent *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gst_msgs__msg__BufferEvent__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gst_msgs__msg__BufferEvent__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gst_msgs__msg__BufferEvent__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
