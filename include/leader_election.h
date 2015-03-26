/* The header file for the leader election
protocol. This class will implement various
different methods of leader election among
the swarm robots */


// #ifndef LEADERELECTION
// #define LEADERELECTION

#include <sstream>

#include "ros/ros.h"
#include <string>
#include <vector>
#include "singlerobot/message.h"

using namespace std;


class LeaderElection
{
public:
	void ElectionByIDCallback(singlerobot::message msg){
		int r_id = msg.id;
		leader_id = (r_id<leader_id)?r_id:leader_id;
	}
	LeaderElection(int id, int n){
		leader_id = id; //Thinks itself is the leader
		n_agents = n;
		for(int i=0;i<n;i++){
			if(i!=id){
				stringstream sstm;
				sstm<<"/swarmbot"<<i<<"/message";
				leader_sub = nh.subscribe<singlerobot::message>(sstm.str(),100,&LeaderElection::ElectionByIDCallback, this);
			}
		}
	}
	// ~LeaderElection();
	int ElectionByID();


protected:
	// vector<ros::Subscriber> leader_subs; //To subscribe to topic for election
	ros::NodeHandle nh;
	int leader_id;
	int n_agents;
	ros::Subscriber leader_sub;

};