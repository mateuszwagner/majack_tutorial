#include <ros/ros.h>
#include <iostream>
#include "turtlesim/Pose.h"


void pose_callback(const turtlesim::Pose& msgIn){

ROS_INFO_STREAM(std::setprecision(2) << std::fixed << "position=(" << msgIn.x << "," << msgIn.y << ")" << "direction=" << msgIn.theta); 
  
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtle_subscriber");
  ros::NodeHandle nh;

  ros::Subscriber subscriber_pose=nh.subscribe("turtle1/pose", 1000, &pose_callback);

  ros::spin();

  return 0;
}
