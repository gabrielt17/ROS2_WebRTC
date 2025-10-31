// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from gst_msgs:msg/MultifilesinkEvent.idl
// generated code does not contain a copyright notice

#ifndef GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__STRUCT_HPP_
#define GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__STRUCT_HPP_

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
# define DEPRECATED__gst_msgs__msg__MultifilesinkEvent __attribute__((deprecated))
#else
# define DEPRECATED__gst_msgs__msg__MultifilesinkEvent __declspec(deprecated)
#endif

namespace gst_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct MultifilesinkEvent_
{
  using Type = MultifilesinkEvent_<ContainerAllocator>;

  explicit MultifilesinkEvent_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filename = "";
      this->index = 0l;
      this->timestamp = 0ull;
      this->stream_time = 0ull;
      this->running_time = 0ull;
      this->duration = 0ull;
      this->offset = 0ull;
      this->offset_end = 0ull;
    }
  }

  explicit MultifilesinkEvent_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : header(_alloc, _init),
    filename(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->filename = "";
      this->index = 0l;
      this->timestamp = 0ull;
      this->stream_time = 0ull;
      this->running_time = 0ull;
      this->duration = 0ull;
      this->offset = 0ull;
      this->offset_end = 0ull;
    }
  }

  // field types and members
  using _header_type =
    std_msgs::msg::Header_<ContainerAllocator>;
  _header_type header;
  using _filename_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _filename_type filename;
  using _index_type =
    int32_t;
  _index_type index;
  using _timestamp_type =
    uint64_t;
  _timestamp_type timestamp;
  using _stream_time_type =
    uint64_t;
  _stream_time_type stream_time;
  using _running_time_type =
    uint64_t;
  _running_time_type running_time;
  using _duration_type =
    uint64_t;
  _duration_type duration;
  using _offset_type =
    uint64_t;
  _offset_type offset;
  using _offset_end_type =
    uint64_t;
  _offset_end_type offset_end;

  // setters for named parameter idiom
  Type & set__header(
    const std_msgs::msg::Header_<ContainerAllocator> & _arg)
  {
    this->header = _arg;
    return *this;
  }
  Type & set__filename(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->filename = _arg;
    return *this;
  }
  Type & set__index(
    const int32_t & _arg)
  {
    this->index = _arg;
    return *this;
  }
  Type & set__timestamp(
    const uint64_t & _arg)
  {
    this->timestamp = _arg;
    return *this;
  }
  Type & set__stream_time(
    const uint64_t & _arg)
  {
    this->stream_time = _arg;
    return *this;
  }
  Type & set__running_time(
    const uint64_t & _arg)
  {
    this->running_time = _arg;
    return *this;
  }
  Type & set__duration(
    const uint64_t & _arg)
  {
    this->duration = _arg;
    return *this;
  }
  Type & set__offset(
    const uint64_t & _arg)
  {
    this->offset = _arg;
    return *this;
  }
  Type & set__offset_end(
    const uint64_t & _arg)
  {
    this->offset_end = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    gst_msgs::msg::MultifilesinkEvent_<ContainerAllocator> *;
  using ConstRawPtr =
    const gst_msgs::msg::MultifilesinkEvent_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<gst_msgs::msg::MultifilesinkEvent_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<gst_msgs::msg::MultifilesinkEvent_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      gst_msgs::msg::MultifilesinkEvent_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<gst_msgs::msg::MultifilesinkEvent_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      gst_msgs::msg::MultifilesinkEvent_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<gst_msgs::msg::MultifilesinkEvent_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<gst_msgs::msg::MultifilesinkEvent_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<gst_msgs::msg::MultifilesinkEvent_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__gst_msgs__msg__MultifilesinkEvent
    std::shared_ptr<gst_msgs::msg::MultifilesinkEvent_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__gst_msgs__msg__MultifilesinkEvent
    std::shared_ptr<gst_msgs::msg::MultifilesinkEvent_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const MultifilesinkEvent_ & other) const
  {
    if (this->header != other.header) {
      return false;
    }
    if (this->filename != other.filename) {
      return false;
    }
    if (this->index != other.index) {
      return false;
    }
    if (this->timestamp != other.timestamp) {
      return false;
    }
    if (this->stream_time != other.stream_time) {
      return false;
    }
    if (this->running_time != other.running_time) {
      return false;
    }
    if (this->duration != other.duration) {
      return false;
    }
    if (this->offset != other.offset) {
      return false;
    }
    if (this->offset_end != other.offset_end) {
      return false;
    }
    return true;
  }
  bool operator!=(const MultifilesinkEvent_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct MultifilesinkEvent_

// alias to use template instance with default allocator
using MultifilesinkEvent =
  gst_msgs::msg::MultifilesinkEvent_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace gst_msgs

#endif  // GST_MSGS__MSG__DETAIL__MULTIFILESINK_EVENT__STRUCT_HPP_
