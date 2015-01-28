#include "ros/ros.h"
#include <math.h>
#include "geometry_msgs/Twist.h"
#include "std_msgs/String.h"
#include <stdio.h>
#include "ros/ros.h"
#include "std_msgs/String.h"
#include "nav_msgs/Odometry.h"

// This file will subscribe to IR data, Obstacle Sensor data and encoder data from Simulator and then plan the path and send the global data + bot data to coverage followed by receiving data from coverage.
//N Instances of this file will be run for each robot

class swarmRobot
{
public:
    swarmRobot(): posX(0.0),posY(0.0),posZ(0.0)
    {
	odomSub = n.subscribe<nav_msgs::Odometry>("/swarm_0/odom",1000,&swarmRobot::robotCallback,this);
    }
    void robotCallback(nav_msgs::Odometry msg)
    {
	posX = msg.pose.pose.position.x;
	posY= msg.pose.pose.position.y;
	posZ = msg.pose.pose.position.z;
    }
    void printPositions(void)
    {
	printf("%lf %lf %lf\n",posX,posY,posZ);
    }
    void run()
    {
	ros::spinOnce();
	printPositions();
    }	    
protected:
    ros::Subscriber odomSub;
    ros::NodeHandle n;
    double posX,posY,posZ;
    char name[10];

};

int main(int argc, char **argv)
{

  ros::init(argc, argv, "singlerobot");
  swarmRobot bot;
  while(ros::ok())
      bot.run();
  
  return 0;
}
