// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gst_msgs:msg/MetaMark.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__META_MARK__STRUCT_HPP_
#define GST_MSGS__MSG__DETAIL__META_MARK__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'header'
#include "std_msgs/msg/detail/header__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__gst_msgs__msg__MetaMark __attribute__((deprecated))
#else
# define DEPRECATED__gst_msgs__msg__MetaMark __declspec(deprecated)
#endif

namespace gst_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MetaMark_
{
  using Type = MetaMark_<ContainerAllocator>;

  explicit MetaMark_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->buffer_pts = 0ull;
      this->mark_timestamp = 0ull;
    }
  }

  explicit MetaMark_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->buffer_pts = 0ull;
      this->mark_timestamp = 0ull;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _buffer_pts_type =
    uint64_t;
  _buffer_pts_type buffer_pts;
  using _mark_timestamp_type =
    uint64_t;
  _mark_timestamp_type mark_timestamp;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__buffer_pts(
    const uint64_t & _arg)
  {
    this->buffer_pts = _arg;
    return *this;
  }
  Type & set__mark_timestamp(
    const uint64_t & _arg)
  {
    this->mark_timestamp = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gst_msgs::msg::MetaMark_<ContainerAllocator> *;
  using ConstRawPtr =
    const gst_msgs::msg::MetaMark_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gst_msgs::msg::MetaMark_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gst_msgs::msg::MetaMark_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gst_msgs::msg::MetaMark_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gst_msgs::msg::MetaMark_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gst_msgs::msg::MetaMark_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gst_msgs::msg::MetaMark_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gst_msgs::msg::MetaMark_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gst_msgs::msg::MetaMark_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gst_msgs__msg__MetaMark
    std::shared_ptr<gst_msgs::msg::MetaMark_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gst_msgs__msg__MetaMark
    std::shared_ptr<gst_msgs::msg::MetaMark_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MetaMark_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->buffer_pts != other.buffer_pts) {
      return false;
    }
    if (this->mark_timestamp != other.mark_timestamp) {
      return false;
    }
    return true;
  }
  bool operator!=(const MetaMark_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MetaMark_

// alias to use template instance with default allocator
using MetaMark =
  gst_msgs::msg::MetaMark_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gst_msgs

#endif  // GST_MSGS__MSG__DETAIL__META_MARK__STRUCT_HPP_
