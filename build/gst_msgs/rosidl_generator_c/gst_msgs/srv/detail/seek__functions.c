// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from gst_msgs:srv/Seek.idl
// generated code does not contain a copyright notice
#include "gst_msgs/srv/detail/seek__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"

bool
gst_msgs__srv__Seek_Request__init(gst_msgs__srv__Seek_Request * msg)
{
  if (!msg) {
    return false;
  }
  // seek_time
  // flags
  return true;
}

void
gst_msgs__srv__Seek_Request__fini(gst_msgs__srv__Seek_Request * msg)
{
  if (!msg) {
    return;
  }
  // seek_time
  // flags
}

bool
gst_msgs__srv__Seek_Request__are_equal(const gst_msgs__srv__Seek_Request * lhs, const gst_msgs__srv__Seek_Request * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // seek_time
  if (lhs->seek_time != rhs->seek_time) {
    return false;
  }
  // flags
  if (lhs->flags != rhs->flags) {
    return false;
  }
  return true;
}

bool
gst_msgs__srv__Seek_Request__copy(
  const gst_msgs__srv__Seek_Request * input,
  gst_msgs__srv__Seek_Request * output)
{
  if (!input || !output) {
    return false;
  }
  // seek_time
  output->seek_time = input->seek_time;
  // flags
  output->flags = input->flags;
  return true;
}

gst_msgs__srv__Seek_Request *
gst_msgs__srv__Seek_Request__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__srv__Seek_Request * msg = (gst_msgs__srv__Seek_Request *)allocator.allocate(sizeof(gst_msgs__srv__Seek_Request), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gst_msgs__srv__Seek_Request));
  bool success = gst_msgs__srv__Seek_Request__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gst_msgs__srv__Seek_Request__destroy(gst_msgs__srv__Seek_Request * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gst_msgs__srv__Seek_Request__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gst_msgs__srv__Seek_Request__Sequence__init(gst_msgs__srv__Seek_Request__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__srv__Seek_Request * data = NULL;

  if (size) {
    data = (gst_msgs__srv__Seek_Request *)allocator.zero_allocate(size, sizeof(gst_msgs__srv__Seek_Request), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gst_msgs__srv__Seek_Request__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gst_msgs__srv__Seek_Request__fini(&data[i - 1]);
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
gst_msgs__srv__Seek_Request__Sequence__fini(gst_msgs__srv__Seek_Request__Sequence * array)
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
      gst_msgs__srv__Seek_Request__fini(&array->data[i]);
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

gst_msgs__srv__Seek_Request__Sequence *
gst_msgs__srv__Seek_Request__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__srv__Seek_Request__Sequence * array = (gst_msgs__srv__Seek_Request__Sequence *)allocator.allocate(sizeof(gst_msgs__srv__Seek_Request__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gst_msgs__srv__Seek_Request__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gst_msgs__srv__Seek_Request__Sequence__destroy(gst_msgs__srv__Seek_Request__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gst_msgs__srv__Seek_Request__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gst_msgs__srv__Seek_Request__Sequence__are_equal(const gst_msgs__srv__Seek_Request__Sequence * lhs, const gst_msgs__srv__Seek_Request__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gst_msgs__srv__Seek_Request__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gst_msgs__srv__Seek_Request__Sequence__copy(
  const gst_msgs__srv__Seek_Request__Sequence * input,
  gst_msgs__srv__Seek_Request__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gst_msgs__srv__Seek_Request);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gst_msgs__srv__Seek_Request * data =
      (gst_msgs__srv__Seek_Request *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gst_msgs__srv__Seek_Request__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gst_msgs__srv__Seek_Request__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gst_msgs__srv__Seek_Request__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}


// Include directives for member types
// Member `message`
#include "rosidl_runtime_c/string_functions.h"

bool
gst_msgs__srv__Seek_Response__init(gst_msgs__srv__Seek_Response * msg)
{
  if (!msg) {
    return false;
  }
  // success
  // message
  if (!rosidl_runtime_c__String__init(&msg->message)) {
    gst_msgs__srv__Seek_Response__fini(msg);
    return false;
  }
  return true;
}

void
gst_msgs__srv__Seek_Response__fini(gst_msgs__srv__Seek_Response * msg)
{
  if (!msg) {
    return;
  }
  // success
  // message
  rosidl_runtime_c__String__fini(&msg->message);
}

bool
gst_msgs__srv__Seek_Response__are_equal(const gst_msgs__srv__Seek_Response * lhs, const gst_msgs__srv__Seek_Response * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // success
  if (lhs->success != rhs->success) {
    return false;
  }
  // message
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->message), &(rhs->message)))
  {
    return false;
  }
  return true;
}

bool
gst_msgs__srv__Seek_Response__copy(
  const gst_msgs__srv__Seek_Response * input,
  gst_msgs__srv__Seek_Response * output)
{
  if (!input || !output) {
    return false;
  }
  // success
  output->success = input->success;
  // message
  if (!rosidl_runtime_c__String__copy(
      &(input->message), &(output->message)))
  {
    return false;
  }
  return true;
}

gst_msgs__srv__Seek_Response *
gst_msgs__srv__Seek_Response__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__srv__Seek_Response * msg = (gst_msgs__srv__Seek_Response *)allocator.allocate(sizeof(gst_msgs__srv__Seek_Response), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(gst_msgs__srv__Seek_Response));
  bool success = gst_msgs__srv__Seek_Response__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
gst_msgs__srv__Seek_Response__destroy(gst_msgs__srv__Seek_Response * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    gst_msgs__srv__Seek_Response__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
gst_msgs__srv__Seek_Response__Sequence__init(gst_msgs__srv__Seek_Response__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__srv__Seek_Response * data = NULL;

  if (size) {
    data = (gst_msgs__srv__Seek_Response *)allocator.zero_allocate(size, sizeof(gst_msgs__srv__Seek_Response), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = gst_msgs__srv__Seek_Response__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        gst_msgs__srv__Seek_Response__fini(&data[i - 1]);
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
gst_msgs__srv__Seek_Response__Sequence__fini(gst_msgs__srv__Seek_Response__Sequence * array)
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
      gst_msgs__srv__Seek_Response__fini(&array->data[i]);
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

gst_msgs__srv__Seek_Response__Sequence *
gst_msgs__srv__Seek_Response__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  gst_msgs__srv__Seek_Response__Sequence * array = (gst_msgs__srv__Seek_Response__Sequence *)allocator.allocate(sizeof(gst_msgs__srv__Seek_Response__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = gst_msgs__srv__Seek_Response__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
gst_msgs__srv__Seek_Response__Sequence__destroy(gst_msgs__srv__Seek_Response__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    gst_msgs__srv__Seek_Response__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
gst_msgs__srv__Seek_Response__Sequence__are_equal(const gst_msgs__srv__Seek_Response__Sequence * lhs, const gst_msgs__srv__Seek_Response__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!gst_msgs__srv__Seek_Response__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
gst_msgs__srv__Seek_Response__Sequence__copy(
  const gst_msgs__srv__Seek_Response__Sequence * input,
  gst_msgs__srv__Seek_Response__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(gst_msgs__srv__Seek_Response);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    gst_msgs__srv__Seek_Response * data =
      (gst_msgs__srv__Seek_Response *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!gst_msgs__srv__Seek_Response__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          gst_msgs__srv__Seek_Response__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!gst_msgs__srv__Seek_Response__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
