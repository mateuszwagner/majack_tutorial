#include <ros/ros.h>
#include <iostream>

bool I_am_tired = 0;

ros::Timer timer;

void timercallback(const ros::TimerEvent&);

int main(int argc, char** argv) {
  ros::init(argc, argv, "Pushup");
  ros::NodeHandle nh;

  timer = nh.createTimer(ros::Duration(1), timercallback);

  ros::spin();

  return 0;
}

void timercallback(const ros::TimerEvent&)
{
  static int counter = 0;
  counter = counter+1;
  ROS_INFO_STREAM("I did "<<counter<<" pushup !");

  if(counter>=10)
  {
    ROS_INFO_STREAM("I am so tired...");
    timer.stop();
  }
}
