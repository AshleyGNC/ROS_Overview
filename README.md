# ROS_Noetic_Overview
Exploring ROS and its applications on robotics projects


Day 1 
	
 	- Getting familiar with ROS
	- Installing ROS Pre-requisites (Ubuntu Linux, WSL, etc.)
		○ Installation/Ubuntu - ROS Wiki
		○ How to Use Linux Terminal in Windows 11 (allthings.how)
		○ Also, can have a virtual machine with Ubuntu running
	- Installing ROS1
		○ ROS/Tutorials/InstallingandConfiguringROSEnvironment - ROS Wiki
		
Day 2 
	
 	- Creating Workspace
 
	- Creating Python package
		○ Creating Node 1
		○ Creating Node 2
		○ Communicating amongst nodes
	
	- Creating Python pkg 2
		○ Creating Node 1 
	- Communicating amongst python packages (Node 1 from pkg1 ->  Node 1 from pkg 2)

Day 3 
	
 	- Communication amongst python & java packages
		○ Created Java package manually in catkin workspace
				§ Inside catkin_ws I copied rosjava_core
				§ ISSUE: catkin_make_isolated results in errors not compiling the Java pkg
					□ Potential Solution 1: Move Java pkg into a rosjava_ws 
					□ Potential Solution 2: Move the rosjava_ws files to the catkin_ws??
					□ Solution 1 	Can pkgs from different workspaces communicate with each other? 	Yes!
						® Try Solution 1
							◊ Not able to create_make_isolated, rosjava not installed propertly idk why
Day 4 

	□ Successful communication amongst packages in different workspaces + languages
		Workspaces	Catkin_ws	Catkin_cpp_ws
		Packages	Talker_pkg	Listener_cpp
		Nodes	Talker.py	Listener.cpp
	□ roscpp_tutorials/Tutorials/WritingPublisherSubscriber - ROS Wiki

RUN COMMANDS:
	
 	In a terminal run, roscore 
	
	In another terminal, rosrun talker_pkg talker.py
	
	In another terminal, source ~/catkin_cpp_ws/devel/setup.bash   #sourcing your new workspace
				   ~/.bashrc #modify the file to include the line above and automatically source your workspace with ROS
				    rosrun listener_cpp listener 

![image](https://github.com/user-attachments/assets/b01649d6-3409-4a8f-baf0-08bed1e7ae5d)
