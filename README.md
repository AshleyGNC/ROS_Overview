# JS-Python Pub/Sub Demo in ROS Noetic

## Main Objective

Facilitating Communication Between JavaScript and Python Files for Component Interaction

By the end of this guide, you should have the following four terminals working on your device:

![image](https://github.com/user-attachments/assets/eec55286-6d02-42c2-a8a4-ad762d26bdcc)


## Starting with ROS
- Get familiar with the framework
	- Installing ROS Pre-requisites (Ubuntu Linux, WSL, etc.)
   
		○ [Installation/Ubuntu - ROS Wiki](https://wiki.ros.org/Installation/Ubuntu)

		○ [How to Use Linux Terminal in Windows 11 (allthings.how)](https://allthings.how/how-to-use-linux-terminal-in-windows-11/)

		○ Also you can have a virtual machine with Ubuntu running (preferred)

	- Installing ROS1
   
		○ [ROS/Tutorials/InstallingandConfiguringROSEnvironment - ROS Wiki](https://wiki.ros.org/ROS/Tutorials/InstallingandConfiguringROSEnvironment)
		
## Workspace Setup
- Create a Workspace 
	1. Run the following commands
			
   			$ mkdir -p ~/catkin_ws/src
			$ cd ~/catkin_ws/
			$ catkin_make
			$ source devel/setup.bash
			$ source ~/catkin_ws/devel/setup.bash

	2. IMPORTANT so that you don't have to source your workspace every time you run a file from it, add the last command at the bottom of the 'bashrc' file:
			
   			$ nano ~/.bashrc

![image](https://github.com/user-attachments/assets/273134b5-71d2-447b-a756-3045ac7bae24)


**_Note:_** After you successfully build your workspace in ROS using catkin_make, ROS will automatically generate a CMakeLists.txt file in your workspace’s src directory (i.e., workspace/src/CMakeLists.txt).


## ROS Package Creation 
		
- Creating my ROS Package. Follow the following tutorial: [ROS/Tutorials/WritingPublisherSubscriber(python) - ROS Wiki](https://wiki.ros.org/ROS/Tutorials/WritingPublisherSubscriber%28python%29)
	- Run the following commands
		
			# You should have created this in the Creating a Workspace Tutorial
			$ cd ~/catkin_ws/src
			$ catkin_create_pkg talker_pkg std_msgs rospy roscpp  
			#std_msgs is the messages dependency, this means we can send/receive string messages in this workspace
			#rospy is the python dependency & roscpp is the C++ dependency, this means that both types of files/node can be created in this workspace
			$ cd ~/catkin_ws
			$ catkin_make

## ROS Node Creation & Communication 

- Creating Node 1: talker.py
	
			#!/usr/bin/env python
			
			import rospy
			from std_msgs.msg import String
			
			def talker():
			    pub = rospy.Publisher('chatter', String, queue_size=10) #"chatter" is the topic, any package subscribed to this topic will receive "hello world"
			    rospy.init_node('talker', anonymous=True)
			    rate = rospy.Rate(1)  # 1 Hz
			    while not rospy.is_shutdown():
			        hello_str = "hello world %s" % rospy.get_time()
			        rospy.loginfo(hello_str)
			        pub.publish(hello_str)
			        rate.sleep()
			
			if __name__ == '__main__':
			    try:
			        talker()
			    except rospy.ROSInterruptException:
			        pass
			
- Creating Node 2: listener.py
	
			#!/usr/bin/env python
			import rospy
			from std_msgs.msg import String
			
			def callback(data):
			    rospy.loginfo(rospy.get_caller_id() + "I heard %s", data.data)
			    
			def listener():
			
			    # In ROS, nodes are uniquely named. If two nodes with the same
			    # name are launched, the previous one is kicked off. The
			    # anonymous=True flag means that rospy will choose a unique
			    # name for our 'listener' node so that multiple listeners can
			    # run simultaneously.
			    rospy.init_node('listener', anonymous=True)
			
			    rospy.Subscriber("chatter", String, callback) #subscribed to the topic "chatter", can receive information from any node publishing to that topic
			
			    # spin() simply keeps python from exiting until this node is stopped
			    rospy.spin()
			
			if __name__ == '__main__':
			    listener()
			
- Communicate
	1. Build Nodes 
	  
				$ cd ~/catkin_ws
				$ catkin_make
				

  	2. In a terminal run:
  		
    		roscore

  	3. In another terminal run:
  	
   			rosrun talker_pkg talker.py
			
   	4. In another terminal run:
  		
    		rosrun talker_pkg listener.py

### Distinct Package Communication 

The following is supplementary workflow to proof that nodes from different packages can communicate too:
		- Creating Python pkg 2
			○ Creating Node 1 
		- Communicating amongst python packages (Node 1 from pkg1 ->  Node 1 from pkg 2)
  

## Distinct Workspaces + Languages Communication

	Workspaces	catkin_ws	catkin_cpp_ws
	Packages	talker_pkg	listener_cpp
	Nodes		talker.py	listener.cpp

Follow the previous steps to create catkin_ws_cpp & the listener_cpp package insiden the new workspace.
For code and guidance on building the listener.cpp node go to: [roscpp_tutorials/Tutorials/WritingPublisherSubscriber - ROS Wiki](https://wiki.ros.org/roscpp_tutorials/Tutorials/WritingPublisherSubscriber)
	
RUN COMMANDS:

In a terminal run 
	
 	roscore 
	
In another terminal run 

	rosrun talker_pkg talker.py
	
In another terminal run
	
 	source ~/catkin_cpp_ws/devel/setup.bash   #sourcing your new workspace
	~/.bashrc #modify the file to include the line above to freely use workspace with ROS
	rosrun listener_cpp listener 
				
	

## Standard ROS JavaScript Library Integration 

- Standard ROS JavaScript Library, roslibjs: [roslibjs - ROS Wiki, RobotWebTools/roslibjs: The Standard ROS JavaScript Library (github.com)](https://github.com/RobotWebTools/roslibjs)
	- Steps to run a JavaScript Node:
		1. Follow the guide in the github to install roslibjs, basically just run the command bellow & install npm if you don't have it already:

     			npm install roslib

		2. Install the rosbridge_suit, this is a server to communicate javascript packages with ROS
			
   				sudo apt-get install ros-noetic-rosbridge-suite
	
  		3. In the terminal run

   				roscore
       
		5. In a separate terminal run the rosbridge server

     			roslaunch rosbridge_server rosbridge_websocket.launch
     
		7. In another terminal create, in the same workspace you installed roslibjs, a listener.js file:

     			nano listener.js
     
			a. The following is a modified code from: [roslibjs/Tutorials/BasicRosFunctionality - ROS Wiki](https://wiki.ros.org/roslibjs/Tutorials/BasicRosFunctionality)

				// Import the roslibjs library
				const ROSLIB = require('roslib');
			
				// Create a ROS connection instance
				const ros = new ROSLIB.Ros({
				  url: 'ws://localhost:9090' // URL of the ROS bridge server
				});
				
				// Handle connection events
				ros.on('connection', function() {
				  console.log('Connected to websocket server.');
				});
				
				ros.on('error', function(error) {
				  console.log('Error connecting to websocket server: ', error);
				});
				
				ros.on('close', function() {
				  console.log('Connection to websocket server closed.');
				});
				
				// Create a ROS topic subscriber for the "chatter" topic
				const chatterListener = new ROSLIB.Topic({
				  ros: ros,
				  name: '/chatter', // Subscriber to the "chatter" topic, this means that it will receive messages from any node publishing into that same topic.
				  messageType: 'std_msgs/String'
				});
				
				// Define a callback function to handle incoming messages
				chatterListener.subscribe(function(message) {
				  console.log('Received message on /chatter: ', message.data);
				});
		
	
	6. Run JavaScript Node
 
    		node listener.js

	7. Now, in a different terminal, run the created python script for a publisher in the "chatter" topic -> talker.py

    		rosrun talker_pkg talker.py
    
	8. Your javascript terminal should receive and show the message "hello world" that your python node is sending.

