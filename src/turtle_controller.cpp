#include <ros/ros.h>
#include <geometry_msgs/Twist.h>
#include "turtlesim/Pose.h"
#include <geometry_msgs/Point.h>

double x_d, y_d; //desired coords
double k_Pf, k_Po; //gains
double forward_control = 0.0;
double orientation_control = 0.0;

void pose_callback(const turtlesim::Pose::ConstPtr& pose_msg){
    double x_error = x_d - pose_msg->x;
    double y_error = y_d - pose_msg->y;
    double theta_error = atan2(y_error, x_error) - pose_msg->theta;
    double distanceBetweenPoints = pow(x_error,2.0) + pow(y_error,2.0);

    if (distanceBetweenPoints > 0.01) {
    orientation_control = k_Po * theta_error;
    forward_control = k_Pf * distanceBetweenPoints;
  } else {
    orientation_control = 0;
    forward_control = 0;
  }

  ROS_INFO_STREAM("x: " << pose_msg->x << "y: " << pose_msg->y << "theta: " << pose_msg->theta);
}

int main(int argc, char** argv)
{
  ros::init(argc, argv, "turtle_controller");
  ros::NodeHandle nh;

  ros::Publisher control_pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
  ros::Subscriber subscriber_pose= nh.subscribe("turtle1/pose", 10, &pose_callback);

  nh.param("goal_x", x_d, 10.0);
  nh.param("goal_y", y_d, 10.0);
  nh.param("surge_gain", k_Pf, 1.0);
  nh.param("orientation_gain", k_Po, 1.0);

  ros::Rate rate(100.0);

  while (ros::ok()) {
    ros::spinOnce();    // we must do it

    geometry_msgs::Twist controls;

    controls.linear.x = forward_control;
    controls.angular.z = orientation_control;

    control_pub.publish(controls);

    rate.sleep();
  }

  return 0;
}



