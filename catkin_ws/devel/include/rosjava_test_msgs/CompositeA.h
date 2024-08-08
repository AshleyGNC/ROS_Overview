// Generated by gencpp from file rosjava_test_msgs/CompositeA.msg
// DO NOT EDIT!


#ifndef ROSJAVA_TEST_MSGS_MESSAGE_COMPOSITEA_H
#define ROSJAVA_TEST_MSGS_MESSAGE_COMPOSITEA_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace rosjava_test_msgs
{
template <class ContainerAllocator>
struct CompositeA_
{
  typedef CompositeA_<ContainerAllocator> Type;

  CompositeA_()
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , w(0.0)  {
    }
  CompositeA_(const ContainerAllocator& _alloc)
    : x(0.0)
    , y(0.0)
    , z(0.0)
    , w(0.0)  {
  (void)_alloc;
    }



   typedef double _x_type;
  _x_type x;

   typedef double _y_type;
  _y_type y;

   typedef double _z_type;
  _z_type z;

   typedef double _w_type;
  _w_type w;





  typedef boost::shared_ptr< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> const> ConstPtr;

}; // struct CompositeA_

typedef ::rosjava_test_msgs::CompositeA_<std::allocator<void> > CompositeA;

typedef boost::shared_ptr< ::rosjava_test_msgs::CompositeA > CompositeAPtr;
typedef boost::shared_ptr< ::rosjava_test_msgs::CompositeA const> CompositeAConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::rosjava_test_msgs::CompositeA_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::rosjava_test_msgs::CompositeA_<ContainerAllocator1> & lhs, const ::rosjava_test_msgs::CompositeA_<ContainerAllocator2> & rhs)
{
  return lhs.x == rhs.x &&
    lhs.y == rhs.y &&
    lhs.z == rhs.z &&
    lhs.w == rhs.w;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::rosjava_test_msgs::CompositeA_<ContainerAllocator1> & lhs, const ::rosjava_test_msgs::CompositeA_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace rosjava_test_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> >
{
  static const char* value()
  {
    return "a779879fadf0160734f906b8c19c7004";
  }

  static const char* value(const ::rosjava_test_msgs::CompositeA_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xa779879fadf01607ULL;
  static const uint64_t static_value2 = 0x34f906b8c19c7004ULL;
};

template<class ContainerAllocator>
struct DataType< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> >
{
  static const char* value()
  {
    return "rosjava_test_msgs/CompositeA";
  }

  static const char* value(const ::rosjava_test_msgs::CompositeA_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# This represents an orientation in free space in quaternion form.\n"
"\n"
"float64 x\n"
"float64 y\n"
"float64 z\n"
"float64 w\n"
;
  }

  static const char* value(const ::rosjava_test_msgs::CompositeA_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.x);
      stream.next(m.y);
      stream.next(m.z);
      stream.next(m.w);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct CompositeA_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::rosjava_test_msgs::CompositeA_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::rosjava_test_msgs::CompositeA_<ContainerAllocator>& v)
  {
    s << indent << "x: ";
    Printer<double>::stream(s, indent + "  ", v.x);
    s << indent << "y: ";
    Printer<double>::stream(s, indent + "  ", v.y);
    s << indent << "z: ";
    Printer<double>::stream(s, indent + "  ", v.z);
    s << indent << "w: ";
    Printer<double>::stream(s, indent + "  ", v.w);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROSJAVA_TEST_MSGS_MESSAGE_COMPOSITEA_H