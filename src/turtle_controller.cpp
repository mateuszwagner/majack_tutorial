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

    controls.linear.x =(double)(rand() % 10 +1)/4.0;
    controls.angular.z =(double)(rand() % 10 - 5)/2.0;

    control_pub.publish(controls);

    rate.sleep();
  }

  return 0;
}
