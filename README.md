# Single Robot
Description: Controls N agents by deploying the same code N times using ROS for Swarm behavior simulation.

Dependencies: ROS, Gazebo, Swarm Simulator

Usage:

1. Clone this Repository.

2. Run the Swarm Simulator. [Swarm Simulator Repository should be in the system]
	roslaunch swarm_simulator swarm.launch

3. Run roslaunch singlerobot robotcontrol.launch to run this node.
	Use --screen to print the position of the current robot in x,y,z

TODO:

1. Edit Roslaunch to deploy same code N times.

2. Implement a naive path planner to take robot from Point A to Point B.

3. Subscribe to encoder data for sibgle robot and generate path from that.
