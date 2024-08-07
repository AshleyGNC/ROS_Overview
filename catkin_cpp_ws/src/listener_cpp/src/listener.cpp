#include "ros/ros.h"
#include "std_msgs/String.h"

// Callback function that will be called when a new message arrives on the "chatter" topic
void chatterCallback(const std_msgs::String::ConstPtr& msg)
{
  ROS_INFO("I heard: [%s]", msg->data.c_str());
}

int main(int argc, char **argv)
{
  // Initialize the ROS system
  ros::init(argc, argv, "listener");

  // Establish this program as a ROS node
  ros::NodeHandle n;

  // Subscribe to the "chatter" topic
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);

  // Enter a loop, pumping callbacks
  ros::spin();

  return 0;
}
