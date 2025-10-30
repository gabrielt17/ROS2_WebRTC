// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gst_msgs:msg/WebrtcIce.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__WEBRTC_ICE__STRUCT_HPP_
#define GST_MSGS__MSG__DETAIL__WEBRTC_ICE__STRUCT_HPP_

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
# define DEPRECATED__gst_msgs__msg__WebrtcIce __attribute__((deprecated))
#else
# define DEPRECATED__gst_msgs__msg__WebrtcIce __declspec(deprecated)
#endif

namespace gst_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct WebrtcIce_
{
  using Type = WebrtcIce_<ContainerAllocator>;

  explicit WebrtcIce_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mline_index = 0ll;
      this->candidate = "";
    }
  }

  explicit WebrtcIce_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    candidate(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->mline_index = 0ll;
      this->candidate = "";
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _mline_index_type =
    int64_t;
  _mline_index_type mline_index;
  using _candidate_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _candidate_type candidate;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__mline_index(
    const int64_t & _arg)
  {
    this->mline_index = _arg;
    return *this;
  }
  Type & set__candidate(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->candidate = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gst_msgs::msg::WebrtcIce_<ContainerAllocator> *;
  using ConstRawPtr =
    const gst_msgs::msg::WebrtcIce_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gst_msgs::msg::WebrtcIce_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gst_msgs::msg::WebrtcIce_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gst_msgs::msg::WebrtcIce_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gst_msgs::msg::WebrtcIce_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gst_msgs::msg::WebrtcIce_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gst_msgs::msg::WebrtcIce_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gst_msgs::msg::WebrtcIce_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gst_msgs::msg::WebrtcIce_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gst_msgs__msg__WebrtcIce
    std::shared_ptr<gst_msgs::msg::WebrtcIce_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gst_msgs__msg__WebrtcIce
    std::shared_ptr<gst_msgs::msg::WebrtcIce_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const WebrtcIce_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->mline_index != other.mline_index) {
      return false;
    }
    if (this->candidate != other.candidate) {
      return false;
    }
    return true;
  }
  bool operator!=(const WebrtcIce_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct WebrtcIce_

// alias to use template instance with default allocator
using WebrtcIce =
  gst_msgs::msg::WebrtcIce_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gst_msgs

#endif  // GST_MSGS__MSG__DETAIL__WEBRTC_ICE__STRUCT_HPP_
