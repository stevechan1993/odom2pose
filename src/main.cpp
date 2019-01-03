#include <iostream>
#include <string>

#include <message_filters/subscriber.h>
#include <message_filters/synchronizer.h>
#include <message_filters/sync_policies/exact_time.h>
#include <message_filters/sync_policies/approximate_time.h>

#include <ros/ros.h>
#include <ros/console.h>
#include <sensor_msgs/Image.h>
#include <geometry_msgs/PoseStamped.h>
#include <nav_msgs/Odometry.h>
// #include <Eigen/Eigen>

using namespace std;
// using namespace Eigen;
ros::Publisher pub_posestamped;

void odom_callback(const nav_msgs::OdometryConstPtr &odometry_input)
{
    geometry_msgs::PoseStamped new_pose;
    new_pose.header.stamp = odometry_input->header.stamp;
    new_pose.pose = odometry_input->pose.pose;
    pub_posestamped.publish(new_pose);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "odom2pose");
    ros::NodeHandle n("~");

    ros::Subscriber sub_odom = n.subscribe("odom", 5000, odom_callback);

    pub_posestamped = n.advertise<geometry_msgs::PoseStamped>("PoseStamped", 1000);

    while(ros::ok())
        ros::spinOnce();
}
