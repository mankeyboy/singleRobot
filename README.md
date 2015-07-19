# Single Robot
Description: Controls N agents by deploying the same code N times using ROS for Swarm behavior simulation.

Dependencies: ROS, Gazebo, [Swarm Simulator](https://github.com/Swarm-IITKgp/swarm_simulator)

======Usage:======

1. Clone this Repository.

2. Run the Swarm Simulator. [Swarm Simulator Repository should be in the system]
	
```sh
$ roslaunch swarm_simulator swarm.launch ''
```

3. Generate the launch file for the singlerobot package for n-agents

```sh
roscd singlerobot
bash scripts/generator.sh <number of agents>
```

4. Launch the singlerobot nodes.

```sh
roslaunch singlerobot singlerobot.launch 
```

The messages are published at /swarmbot0/message and similarly for others.

======TODO:======

1. Subscribe to encoder data for single robot and generate path from that.



