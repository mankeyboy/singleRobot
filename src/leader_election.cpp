
#include <sstream>
#include <string>
#include "leader_election.h"
#include "singlerobot/message.h"

using namespace std;

// void LeaderElection::ElectionByIDCallback(singlerobot::message msg)
// {
// 	int r_id = msg.id;
// 	leader_id = (r_id<leader_id)?r_id:leader_id; //Updates leader_id if received ID is less
// }

// LeaderElection::LeaderElection(int id, int n)
// {
// 	leader_id = id; //Thinks itself is the leader
// 	n_agents = n;
// 	for(int i=0;i<n;i++){
// 		if(i!=id){
// 			stringstream sstm;
// 			sstm<<"/swarm_"<<i<<"/message";
// 			ros::Subscriber leader_sub = nh.subscribe<singlerobot::message>(sstm.str().c_str(),100,&LeaderElection::ElectionByIDCallback, this);
// 		}
// 	}
// }


int LeaderElection::ElectionByID()
{
	ros::Rate r(10); //Listen for messages every 100 ms

	for(int i = 0; i < 20;i++)
	{	
		//Wait for 2 seconds' worth of messages
		ros::spinOnce();
		r.sleep();
	}

	return leader_id; //Lowest ID till now is leader
}