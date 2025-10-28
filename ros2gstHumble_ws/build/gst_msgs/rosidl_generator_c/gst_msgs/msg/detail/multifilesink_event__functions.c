// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gst_msgs:msg/MultifilesinkEvent.idl
// generated code does not contain a copyright notice
#include "gst_msgs/msg/detail/multifilesink_event__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `header`
#include "std_msgs/msg/detail/header__functions.h"
// Member `filename`
#include "rosidl_runtime_c/string_functions.h"

bool
gst_msgs__msg__MultifilesinkEvent__init(gst_msgs__msg__MultifilesinkEvent * msg)
{
  if (!msg) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__init(&msg->header)) {
    gst_msgs__msg__MultifilesinkEvent__fini(msg);
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__init(&msg->filename)) {
    gst_msgs__msg__MultifilesinkEvent__fini(msg);
    return false;
  }
  // index
  // timestamp
  // stream_time
  // running_time
  // duration
  // offset
  // offset_end
  return true;
}

void
gst_msgs__msg__MultifilesinkEvent__fini(gst_msgs__msg__MultifilesinkEvent * msg)
{
  if (!msg) {
    return;
  }
  // header
  std_msgs__msg__Header__fini(&msg->header);
  // filename
  rosidl_runtime_c__String__fini(&msg->filename);
  // index
  // timestamp
  // stream_time
  // running_time
  // duration
  // offset
  // offset_end
}

bool
gst_msgs__msg__MultifilesinkEvent__are_equal(const gst_msgs__msg__MultifilesinkEvent * lhs, const gst_msgs__msg__MultifilesinkEvent * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__are_equal(
      &(lhs->header), &(rhs->header)))
  {
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->filename), &(rhs->filename)))
  {
    return false;
  }
  // index
  if (lhs->index != rhs->index) {
    return false;
  }
  // timestamp
  if (lhs->timestamp != rhs->timestamp) {
    return false;
  }
  // stream_time
  if (lhs->stream_time != rhs->stream_time) {
    return false;
  }
  // running_time
  if (lhs->running_time != rhs->running_time) {
    return false;
  }
  // duration
  if (lhs->duration != rhs->duration) {
    return false;
  }
  // offset
  if (lhs->offset != rhs->offset) {
    return false;
  }
  // offset_end
  if (lhs->offset_end != rhs->offset_end) {
    return false;
  }
  return true;
}

bool
gst_msgs__msg__MultifilesinkEvent__copy(
  const gst_msgs__msg__MultifilesinkEvent * input,
  gst_msgs__msg__MultifilesinkEvent * output)
{
  if (!input || !output) {
    return false;
  }
  // header
  if (!std_msgs__msg__Header__copy(
      &(input->header), &(output->header)))
  {
    return false;
  }
  // filename
  if (!rosidl_runtime_c__String__copy(
      &(input->filename), &(output->filename)))
  {
    return false;
  }
  // index
  output->index = input->index;
  // timestamp
  output->timestamp = input->timestamp;
  // stream_time
  output->stream_time = input->stream_time;
  // running_time
  output->running_time = input->running_time;
  // duration
  output->duration = input->duration;
  // offset
  output->offset = input->offset;
  // offset_end
  output->offset_end = input->offset_end;
  return true;
}

gst_msgs__msg__MultifilesinkEvent *
gst_msgs__msg__MultifilesinkEvent__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__msg__MultifilesinkEvent * msg = (gst_msgs__msg__MultifilesinkEvent *)allocator.allocate(sizeof(gst_msgs__msg__MultifilesinkEvent), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gst_msgs__msg__MultifilesinkEvent));
  bool success = gst_msgs__msg__MultifilesinkEvent__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gst_msgs__msg__MultifilesinkEvent__destroy(gst_msgs__msg__MultifilesinkEvent * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gst_msgs__msg__MultifilesinkEvent__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gst_msgs__msg__MultifilesinkEvent__Sequence__init(gst_msgs__msg__MultifilesinkEvent__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__msg__MultifilesinkEvent * data = NULL;

  if (size) {
    data = (gst_msgs__msg__MultifilesinkEvent *)allocator.zero_allocate(size, sizeof(gst_msgs__msg__MultifilesinkEvent), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gst_msgs__msg__MultifilesinkEvent__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gst_msgs__msg__MultifilesinkEvent__fini(&data[i - 1]);
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
gst_msgs__msg__MultifilesinkEvent__Sequence__fini(gst_msgs__msg__MultifilesinkEvent__Sequence * array)
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
      gst_msgs__msg__MultifilesinkEvent__fini(&array->data[i]);
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

gst_msgs__msg__MultifilesinkEvent__Sequence *
gst_msgs__msg__MultifilesinkEvent__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__msg__MultifilesinkEvent__Sequence * array = (gst_msgs__msg__MultifilesinkEvent__Sequence *)allocator.allocate(sizeof(gst_msgs__msg__MultifilesinkEvent__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gst_msgs__msg__MultifilesinkEvent__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gst_msgs__msg__MultifilesinkEvent__Sequence__destroy(gst_msgs__msg__MultifilesinkEvent__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gst_msgs__msg__MultifilesinkEvent__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gst_msgs__msg__MultifilesinkEvent__Sequence__are_equal(const gst_msgs__msg__MultifilesinkEvent__Sequence * lhs, const gst_msgs__msg__MultifilesinkEvent__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gst_msgs__msg__MultifilesinkEvent__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gst_msgs__msg__MultifilesinkEvent__Sequence__copy(
  const gst_msgs__msg__MultifilesinkEvent__Sequence * input,
  gst_msgs__msg__MultifilesinkEvent__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gst_msgs__msg__MultifilesinkEvent);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gst_msgs__msg__MultifilesinkEvent * data =
      (gst_msgs__msg__MultifilesinkEvent *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gst_msgs__msg__MultifilesinkEvent__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gst_msgs__msg__MultifilesinkEvent__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gst_msgs__msg__MultifilesinkEvent__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
