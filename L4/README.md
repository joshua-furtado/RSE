# L4
Lab: gmapping

## Terminal 1
Launch the turtlebot in a Willow Garage environment
```
$ cd /home/workspace/catkin_ws
$ source devel/setup.bash
$ roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=worlds/willowgarage.world 
```
Turtlebot should now appear in a Willow Garage environment.

## Terminal 2
Launch the keyboard teleop node
```
$ cd /home/workspace/catkin_ws
$ source devel/setup.bash
$ roslaunch turtlebot_teleop keyboard_teleop.launch
```
Don’t move your robot yet!

## Terminal 3
Run the slam_gmapping node
```
$ cd /home/workspace/catkin_ws
$ source devel/setup.bash
$ rosrun gmapping slam_gmapping
```
The node should start registering your first scan.

## Terminal 4
Run rviz and subscribe to different published topics to visualize the map
```
$ rosrun rviz rviz
```
Edit the rviz configuration as follows:
  - Change the **Fixed Frame** to map
  - Keep **Reference Frame** as default
  - Add a **RobotModel**
  - Add a **camera** and select the /camera/rgb/image_raw topic
  - Add a **map** and select the /map topic
Now, map the environment by driving your robot using keyboard commands.

## Terminal 5
Save a map of the environment and share it with your classmates
```
$ cd /home/workspace/
$ rosrun map_server map_saver -f myMap
```
