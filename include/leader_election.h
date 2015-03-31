/* The header file for the leader election
protocol. This class will implement various
different methods of leader election among
the swarm robots */


#ifndef LEADERELECTION
#define LEADERELECTION

#include "ros/ros.h"
#include <string>
#include <vector>


class LeaderElection
{
public:
	LeaderElection(int id, int n)
	~LeaderElection();

	int ElectionByID();


protected:
	vector<ros::Subscriber> leader_subs; //To subscribe to topic for election
	ros::NodeHandle nh;
	int leader_id;
	int n_agents;
}