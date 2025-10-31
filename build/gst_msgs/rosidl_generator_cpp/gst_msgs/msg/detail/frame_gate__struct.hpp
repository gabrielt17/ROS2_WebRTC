// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gst_msgs:msg/FrameGate.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__FRAME_GATE__STRUCT_HPP_
#define GST_MSGS__MSG__DETAIL__FRAME_GATE__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__gst_msgs__msg__FrameGate __attribute__((deprecated))
#else
# define DEPRECATED__gst_msgs__msg__FrameGate __declspec(deprecated)
#endif

namespace gst_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct FrameGate_
{
  using Type = FrameGate_<ContainerAllocator>;

  explicit FrameGate_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  explicit FrameGate_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mode = 0;
    }
  }

  // field types and members
  using _mode_type =
    int8_t;
  _mode_type mode;

  // setters for named parameter idiom
  Type & set__mode(
    const int8_t & _arg)
  {
    this->mode = _arg;
    return *this;
  }

  // constant declarations
  static constexpr int8_t DROP_ALL =
    0;
  static constexpr int8_t PASS_ALL =
    1;
  static constexpr int8_t PASS_ONE =
    2;

  // pointer types
  using RawPtr =
    gst_msgs::msg::FrameGate_<ContainerAllocator> *;
  using ConstRawPtr =
    const gst_msgs::msg::FrameGate_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gst_msgs::msg::FrameGate_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gst_msgs::msg::FrameGate_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gst_msgs::msg::FrameGate_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gst_msgs::msg::FrameGate_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gst_msgs::msg::FrameGate_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gst_msgs::msg::FrameGate_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gst_msgs::msg::FrameGate_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gst_msgs::msg::FrameGate_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gst_msgs__msg__FrameGate
    std::shared_ptr<gst_msgs::msg::FrameGate_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gst_msgs__msg__FrameGate
    std::shared_ptr<gst_msgs::msg::FrameGate_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const FrameGate_ & other) const
  {
    if (this->mode != other.mode) {
      return false;
    }
    return true;
  }
  bool operator!=(const FrameGate_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct FrameGate_

// alias to use template instance with default allocator
using FrameGate =
  gst_msgs::msg::FrameGate_<std::allocator<void>>;

// constant definitions
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t FrameGate_<ContainerAllocator>::DROP_ALL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t FrameGate_<ContainerAllocator>::PASS_ALL;
#endif  // __cplusplus < 201703L
#if __cplusplus < 201703L
// static constexpr member variable definitions are only needed in C++14 and below, deprecated in C++17
template<typename ContainerAllocator>
constexpr int8_t FrameGate_<ContainerAllocator>::PASS_ONE;
#endif  // __cplusplus < 201703L

}  // namespace msg

}  // namespace gst_msgs

#endif  // GST_MSGS__MSG__DETAIL__FRAME_GATE__STRUCT_HPP_
