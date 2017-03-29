#include <ros/ros.h>
#include <iostream>
#include <geometry_msgs/Point.h>

int main(int argc, char** argv) {
  ros::init(argc, argv, "publisher");
  ros::NodeHandle nh;

  ros::Publisher our_pub = nh.advertise<geometry_msgs::Point>("point", 10);

  ros::Rate rate(1.0);

  while(ros::ok()) {
    geometry_msgs::Point point;
    point.x = 6.0;
    point.y = 18.0;
    point.z = -21.5;

    our_pub.publish(point);

    rate.sleep();
  }

  return 0;
}
