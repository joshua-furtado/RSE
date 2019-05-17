#include "ros/ros.h"
#include "ball_chaser/DriveToTarget.h"
#include <sensor_msgs/Image.h>
#include <algorithm>

// Define a global client that can request services
ros::ServiceClient client;

// This function calls the command_robot service to drive the robot in the specified direction
void drive_robot(float lin_x, float ang_z)
{
    // Requests a service and passes the velocities to it to drive the robot
    ROS_INFO_STREAM("Moving the robot");

    ball_chaser::DriveToTarget srv;
    srv.request.linear_x = lin_x;
    srv.request.angular_z = ang_z;

    if (!client.call(srv))
        ROS_ERROR("Failed to call service command_robot");
}

// This callback function continuously executes and reads the image data
void process_image_callback(const sensor_msgs::Image img)
{
    int adjust = 0;
    int white_pixel = 255;
    int lower_white_pixel = 255 - adjust;

    int left_count = 0;
    int mid_count = 0; 
    int right_count = 0;
    int idx = 0;
    int left_thresh = img.step / 3;
    int mid_thresh = 2 * img.step / 3;

    for (int i = 0; i < img.height * img.step; i++) {
        if ((img.data[i] <= white_pixel) && (img.data[i] >= lower_white_pixel)) {
            idx = i % img.step;
            if (idx < left_thresh) {
                left_count += 1;
            }
            else if (idx < mid_thresh) {
                mid_count += 1;
            }
            else {
                right_count += 1;
            }
        }
    }

    if (left_count || mid_count || right_count){
        if ((right_count > mid_count) && (right_count > left_count)){
            drive_robot(0.2, -0.4);
        }
        else if (mid_count > left_count){
            drive_robot(0.3, 0);
        }
        else {
            drive_robot(0.2, 0.4);
        }
    }
    else {
        drive_robot(0, 0);
    }

}

int main(int argc, char** argv)
{
    // Initialize the process_image node and create a handle to it
    ros::init(argc, argv, "process_image");
    ros::NodeHandle n;

    // Define a client service capable of requesting services from command_robot
    client = n.serviceClient<ball_chaser::DriveToTarget>("/ball_chaser/command_robot");

    // Subscribe to /camera/rgb/image_raw topic to read the image data inside the process_image_callback function
    ros::Subscriber sub1 = n.subscribe("/camera/rgb/image_raw", 10, process_image_callback);

    // Handle ROS communication events
    ros::spin();

    return 0;
}
