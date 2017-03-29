#include <ros/ros.h>
#include <iostream>

int main(int argc, char** argv) {
  ros::init(argc, argv, "hello_world");
  ros::NodeHandle nh;

  std::cout << "Hello, world." << std::endl;

  ros::spin();

  return 0;
}
