# AirSim_3D_Bridge_Meshes

#### Create a Pointcloud of the Environment
```
roslaunch airsim_ros_pkgs airsim_node.launch
roslaunch airsim_tutorial_pkgs front_stereo_and_center_mono.launch
```
#### Create an Octomap and Other Neccesary Components
```
roslaunch pcl_filter cloud_pub.launch
rosrun octomap_server octomap_server_node _resolution:=1 _frame_id:="world_enu" _sensor_model/max_range:=-1 cloud_in:=/airsim_node/PX4/lidar/LidarCustom
rosrun octomap_server zFilter
rosrun gtsp gtsp_solver
rosrun octomap_server visitedPoints_Publisher
rosrun octomap_server baseline
```
#### Get PX4 and Run the Algorithim
PX4 - https://microsoft.github.io/AirSim/airsim_tutorial_pkgs/
```
cd PX4/PX4-Autopilot
make px4_sitl_default none_iris
rosrun octomap_server kevin
```
