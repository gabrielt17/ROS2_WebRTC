// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gst_msgs:msg/BufferEvent.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__BUFFER_EVENT__STRUCT_HPP_
#define GST_MSGS__MSG__DETAIL__BUFFER_EVENT__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gst_msgs__msg__BufferEvent __attribute__((deprecated))
#else
# define DEPRECATED__gst_msgs__msg__BufferEvent __declspec(deprecated)
#endif

namespace gst_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct BufferEvent_
{
  using Type = BufferEvent_<ContainerAllocator>;

  explicit BufferEvent_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->buffer_pts = 0ull;
    }
  }

  explicit BufferEvent_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->buffer_pts = 0ull;
    }
  }

  // field types and members
  using _buffer_pts_type =
    uint64_t;
  _buffer_pts_type buffer_pts;

  // setters for named parameter idiom
  Type & set__buffer_pts(
    const uint64_t & _arg)
  {
    this->buffer_pts = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gst_msgs::msg::BufferEvent_<ContainerAllocator> *;
  using ConstRawPtr =
    const gst_msgs::msg::BufferEvent_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gst_msgs::msg::BufferEvent_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gst_msgs::msg::BufferEvent_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gst_msgs::msg::BufferEvent_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gst_msgs::msg::BufferEvent_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gst_msgs::msg::BufferEvent_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gst_msgs::msg::BufferEvent_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gst_msgs::msg::BufferEvent_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gst_msgs::msg::BufferEvent_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gst_msgs__msg__BufferEvent
    std::shared_ptr<gst_msgs::msg::BufferEvent_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gst_msgs__msg__BufferEvent
    std::shared_ptr<gst_msgs::msg::BufferEvent_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BufferEvent_ & other) const
  {
    if (this->buffer_pts != other.buffer_pts) {
      return false;
    }
    return true;
  }
  bool operator!=(const BufferEvent_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BufferEvent_

// alias to use template instance with default allocator
using BufferEvent =
  gst_msgs::msg::BufferEvent_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gst_msgs

#endif  // GST_MSGS__MSG__DETAIL__BUFFER_EVENT__STRUCT_HPP_
