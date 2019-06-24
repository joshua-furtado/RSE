#!/bin/sh
xterm  -e "cd $(pwd)/../..; source devel/setup.bash ; roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../turtlebot_simulator/turtlebot_gazebo/worlds/UdacityOffice.world " &
sleep 5
xterm  -e "cd $(pwd)/../..; source devel/setup.bash ; roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(pwd)/../turtlebot_simulator/turtlebot_gazebo/maps/my_map7.yaml " &
sleep 5
xterm  -e "cd $(pwd)/../..; source devel/setup.bash ; roslaunch turtlebot_rviz_launchers view_navigation.launch " &
sleep 10
xterm  -e "cd $(pwd)/../..; source devel/setup.bash ; rosrun pick_objects pick_objects "
