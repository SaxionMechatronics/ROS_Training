#include "ros/ros.h"
#include "std_msgs/String.h"
#include "geometry_msgs/Twist.h"

int main(int argc, char **argv)
{
  ros::init(argc, argv, "publisher");
  ros::NodeHandle nh;

  //ros::Publisher chatter_pub = nh.advertise<std_msgs::String>("chatter", 1000);
  ros::Publisher chatter_pub = nh.advertise<geometry_msgs::Twist>("chatter", 1000);

  ros::Rate loop_rate(10);
  while (ros::ok())
  {
    //std_msgs::String msg;
    geometry_msgs::Twist msg;
    msg.linear.x = 0.1;

    chatter_pub.publish(msg);

    ros::spinOnce();

    loop_rate.sleep();
  }

  return 0;
}
