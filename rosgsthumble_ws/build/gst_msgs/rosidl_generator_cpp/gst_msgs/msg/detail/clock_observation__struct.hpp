// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gst_msgs:msg/ClockObservation.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__CLOCK_OBSERVATION__STRUCT_HPP_
#define GST_MSGS__MSG__DETAIL__CLOCK_OBSERVATION__STRUCT_HPP_

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
# define DEPRECATED__gst_msgs__msg__ClockObservation __attribute__((deprecated))
#else
# define DEPRECATED__gst_msgs__msg__ClockObservation __declspec(deprecated)
#endif

namespace gst_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ClockObservation_
{
  using Type = ClockObservation_<ContainerAllocator>;

  explicit ClockObservation_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pipeline_time = 0ull;
    }
  }

  explicit ClockObservation_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->pipeline_time = 0ull;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _pipeline_time_type =
    uint64_t;
  _pipeline_time_type pipeline_time;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__pipeline_time(
    const uint64_t & _arg)
  {
    this->pipeline_time = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gst_msgs::msg::ClockObservation_<ContainerAllocator> *;
  using ConstRawPtr =
    const gst_msgs::msg::ClockObservation_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gst_msgs::msg::ClockObservation_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gst_msgs::msg::ClockObservation_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gst_msgs::msg::ClockObservation_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gst_msgs::msg::ClockObservation_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gst_msgs::msg::ClockObservation_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gst_msgs::msg::ClockObservation_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gst_msgs::msg::ClockObservation_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gst_msgs::msg::ClockObservation_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gst_msgs__msg__ClockObservation
    std::shared_ptr<gst_msgs::msg::ClockObservation_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gst_msgs__msg__ClockObservation
    std::shared_ptr<gst_msgs::msg::ClockObservation_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ClockObservation_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->pipeline_time != other.pipeline_time) {
      return false;
    }
    return true;
  }
  bool operator!=(const ClockObservation_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ClockObservation_

// alias to use template instance with default allocator
using ClockObservation =
  gst_msgs::msg::ClockObservation_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gst_msgs

#endif  // GST_MSGS__MSG__DETAIL__CLOCK_OBSERVATION__STRUCT_HPP_
