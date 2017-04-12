#include <ros/ros.h>
#include <geometry_msgs/Twist.h>


int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtle_controller");
  ros::NodeHandle nh;

  ros::Publisher control_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);

  ros::Rate rate(100.0);

  while (ros::ok()) {
    geometry_msgs::Twist controls;

    controls.linear.x = 1.0; // [1 m/s]
    controls.angular.z = 1.0; // [1 rad/s]

    control_pub.publish(controls);

    rate.sleep();
  }

  return 0;
}
