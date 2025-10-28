// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gst_msgs:msg/FrameGate.idl
// generated code does not contain a copyright notice
#include "gst_msgs/msg/detail/frame_gate__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


bool
gst_msgs__msg__FrameGate__init(gst_msgs__msg__FrameGate * msg)
{
  if (!msg) {
    return false;
  }
  // mode
  return true;
}

void
gst_msgs__msg__FrameGate__fini(gst_msgs__msg__FrameGate * msg)
{
  if (!msg) {
    return;
  }
  // mode
}

bool
gst_msgs__msg__FrameGate__are_equal(const gst_msgs__msg__FrameGate * lhs, const gst_msgs__msg__FrameGate * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // mode
  if (lhs->mode != rhs->mode) {
    return false;
  }
  return true;
}

bool
gst_msgs__msg__FrameGate__copy(
  const gst_msgs__msg__FrameGate * input,
  gst_msgs__msg__FrameGate * output)
{
  if (!input || !output) {
    return false;
  }
  // mode
  output->mode = input->mode;
  return true;
}

gst_msgs__msg__FrameGate *
gst_msgs__msg__FrameGate__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__msg__FrameGate * msg = (gst_msgs__msg__FrameGate *)allocator.allocate(sizeof(gst_msgs__msg__FrameGate), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gst_msgs__msg__FrameGate));
  bool success = gst_msgs__msg__FrameGate__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gst_msgs__msg__FrameGate__destroy(gst_msgs__msg__FrameGate * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gst_msgs__msg__FrameGate__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gst_msgs__msg__FrameGate__Sequence__init(gst_msgs__msg__FrameGate__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__msg__FrameGate * data = NULL;

  if (size) {
    data = (gst_msgs__msg__FrameGate *)allocator.zero_allocate(size, sizeof(gst_msgs__msg__FrameGate), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gst_msgs__msg__FrameGate__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gst_msgs__msg__FrameGate__fini(&data[i - 1]);
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
gst_msgs__msg__FrameGate__Sequence__fini(gst_msgs__msg__FrameGate__Sequence * array)
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
      gst_msgs__msg__FrameGate__fini(&array->data[i]);
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

gst_msgs__msg__FrameGate__Sequence *
gst_msgs__msg__FrameGate__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__msg__FrameGate__Sequence * array = (gst_msgs__msg__FrameGate__Sequence *)allocator.allocate(sizeof(gst_msgs__msg__FrameGate__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gst_msgs__msg__FrameGate__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gst_msgs__msg__FrameGate__Sequence__destroy(gst_msgs__msg__FrameGate__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gst_msgs__msg__FrameGate__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gst_msgs__msg__FrameGate__Sequence__are_equal(const gst_msgs__msg__FrameGate__Sequence * lhs, const gst_msgs__msg__FrameGate__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gst_msgs__msg__FrameGate__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gst_msgs__msg__FrameGate__Sequence__copy(
  const gst_msgs__msg__FrameGate__Sequence * input,
  gst_msgs__msg__FrameGate__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gst_msgs__msg__FrameGate);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gst_msgs__msg__FrameGate * data =
      (gst_msgs__msg__FrameGate *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gst_msgs__msg__FrameGate__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gst_msgs__msg__FrameGate__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gst_msgs__msg__FrameGate__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
