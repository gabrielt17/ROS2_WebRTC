# generated from rosidl_generator_py/resource/_idl.py.em
# with input from gst_msgs:msg/MultifilesinkEvent.idl
# generated code does not contain a copyright notice


# Import statements for member types

import builtins  # noqa: E402, I100

import rosidl_parser.definition  # noqa: E402, I100


class Metaclass_MultifilesinkEvent(type):
    """Metaclass of message 'MultifilesinkEvent'."""

    _CREATE_ROS_MESSAGE = None
    _CONVERT_FROM_PY = None
    _CONVERT_TO_PY = None
    _DESTROY_ROS_MESSAGE = None
    _TYPE_SUPPORT = None

    __constants = {
    }

    @classmethod
    def __import_type_support__(cls):
        try:
            from rosidl_generator_py import import_type_support
            module = import_type_support('gst_msgs')
        except ImportError:
            import logging
            import traceback
            logger = logging.getLogger(
                'gst_msgs.msg.MultifilesinkEvent')
            logger.debug(
                'Failed to import needed modules for type support:\n' +
                traceback.format_exc())
        else:
            cls._CREATE_ROS_MESSAGE = module.create_ros_message_msg__msg__multifilesink_event
            cls._CONVERT_FROM_PY = module.convert_from_py_msg__msg__multifilesink_event
            cls._CONVERT_TO_PY = module.convert_to_py_msg__msg__multifilesink_event
            cls._TYPE_SUPPORT = module.type_support_msg__msg__multifilesink_event
            cls._DESTROY_ROS_MESSAGE = module.destroy_ros_message_msg__msg__multifilesink_event

            from std_msgs.msg import Header
            if Header.__class__._TYPE_SUPPORT is None:
                Header.__class__.__import_type_support__()

    @classmethod
    def __prepare__(cls, name, bases, **kwargs):
        # list constant names here so that they appear in the help text of
        # the message class under "Data and other attributes defined here:"
        # as well as populate each message instance
        return {
        }


class MultifilesinkEvent(metaclass=Metaclass_MultifilesinkEvent):
    """Message class 'MultifilesinkEvent'."""

    __slots__ = [
        '_header',
        '_filename',
        '_index',
        '_timestamp',
        '_stream_time',
        '_running_time',
        '_duration',
        '_offset',
        '_offset_end',
    ]

    _fields_and_field_types = {
        'header': 'std_msgs/Header',
        'filename': 'string',
        'index': 'int32',
        'timestamp': 'uint64',
        'stream_time': 'uint64',
        'running_time': 'uint64',
        'duration': 'uint64',
        'offset': 'uint64',
        'offset_end': 'uint64',
    }

    SLOT_TYPES = (
        rosidl_parser.definition.NamespacedType(['std_msgs', 'msg'], 'Header'),  # noqa: E501
        rosidl_parser.definition.UnboundedString(),  # noqa: E501
        rosidl_parser.definition.BasicType('int32'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
        rosidl_parser.definition.BasicType('uint64'),  # noqa: E501
    )

    def __init__(self, **kwargs):
        assert all('_' + key in self.__slots__ for key in kwargs.keys()), \
            'Invalid arguments passed to constructor: %s' % \
            ', '.join(sorted(k for k in kwargs.keys() if '_' + k not in self.__slots__))
        from std_msgs.msg import Header
        self.header = kwargs.get('header', Header())
        self.filename = kwargs.get('filename', str())
        self.index = kwargs.get('index', int())
        self.timestamp = kwargs.get('timestamp', int())
        self.stream_time = kwargs.get('stream_time', int())
        self.running_time = kwargs.get('running_time', int())
        self.duration = kwargs.get('duration', int())
        self.offset = kwargs.get('offset', int())
        self.offset_end = kwargs.get('offset_end', int())

    def __repr__(self):
        typename = self.__class__.__module__.split('.')
        typename.pop()
        typename.append(self.__class__.__name__)
        args = []
        for s, t in zip(self.__slots__, self.SLOT_TYPES):
            field = getattr(self, s)
            fieldstr = repr(field)
            # We use Python array type for fields that can be directly stored
            # in them, and "normal" sequences for everything else.  If it is
            # a type that we store in an array, strip off the 'array' portion.
            if (
                isinstance(t, rosidl_parser.definition.AbstractSequence) and
                isinstance(t.value_type, rosidl_parser.definition.BasicType) and
                t.value_type.typename in ['float', 'double', 'int8', 'uint8', 'int16', 'uint16', 'int32', 'uint32', 'int64', 'uint64']
            ):
                if len(field) == 0:
                    fieldstr = '[]'
                else:
                    assert fieldstr.startswith('array(')
                    prefix = "array('X', "
                    suffix = ')'
                    fieldstr = fieldstr[len(prefix):-len(suffix)]
            args.append(s[1:] + '=' + fieldstr)
        return '%s(%s)' % ('.'.join(typename), ', '.join(args))

    def __eq__(self, other):
        if not isinstance(other, self.__class__):
            return False
        if self.header != other.header:
            return False
        if self.filename != other.filename:
            return False
        if self.index != other.index:
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.stream_time != other.stream_time:
            return False
        if self.running_time != other.running_time:
            return False
        if self.duration != other.duration:
            return False
        if self.offset != other.offset:
            return False
        if self.offset_end != other.offset_end:
            return False
        return True

    @classmethod
    def get_fields_and_field_types(cls):
        from copy import copy
        return copy(cls._fields_and_field_types)

    @builtins.property
    def header(self):
        """Message field 'header'."""
        return self._header

    @header.setter
    def header(self, value):
        if __debug__:
            from std_msgs.msg import Header
            assert \
                isinstance(value, Header), \
                "The 'header' field must be a sub message of type 'Header'"
        self._header = value

    @builtins.property
    def filename(self):
        """Message field 'filename'."""
        return self._filename

    @filename.setter
    def filename(self, value):
        if __debug__:
            assert \
                isinstance(value, str), \
                "The 'filename' field must be of type 'str'"
        self._filename = value

    @builtins.property
    def index(self):
        """Message field 'index'."""
        return self._index

    @index.setter
    def index(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'index' field must be of type 'int'"
            assert value >= -2147483648 and value < 2147483648, \
                "The 'index' field must be an integer in [-2147483648, 2147483647]"
        self._index = value

    @builtins.property
    def timestamp(self):
        """Message field 'timestamp'."""
        return self._timestamp

    @timestamp.setter
    def timestamp(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'timestamp' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'timestamp' field must be an unsigned integer in [0, 18446744073709551615]"
        self._timestamp = value

    @builtins.property
    def stream_time(self):
        """Message field 'stream_time'."""
        return self._stream_time

    @stream_time.setter
    def stream_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'stream_time' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'stream_time' field must be an unsigned integer in [0, 18446744073709551615]"
        self._stream_time = value

    @builtins.property
    def running_time(self):
        """Message field 'running_time'."""
        return self._running_time

    @running_time.setter
    def running_time(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'running_time' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'running_time' field must be an unsigned integer in [0, 18446744073709551615]"
        self._running_time = value

    @builtins.property
    def duration(self):
        """Message field 'duration'."""
        return self._duration

    @duration.setter
    def duration(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'duration' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'duration' field must be an unsigned integer in [0, 18446744073709551615]"
        self._duration = value

    @builtins.property
    def offset(self):
        """Message field 'offset'."""
        return self._offset

    @offset.setter
    def offset(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'offset' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'offset' field must be an unsigned integer in [0, 18446744073709551615]"
        self._offset = value

    @builtins.property
    def offset_end(self):
        """Message field 'offset_end'."""
        return self._offset_end

    @offset_end.setter
    def offset_end(self, value):
        if __debug__:
            assert \
                isinstance(value, int), \
                "The 'offset_end' field must be of type 'int'"
            assert value >= 0 and value < 18446744073709551616, \
                "The 'offset_end' field must be an unsigned integer in [0, 18446744073709551615]"
        self._offset_end = value
