#include "ros/ros.h"
// %EndTag(ROS_HEADER)%
// %Tag(MSG_HEADER)%
#include "std_msgs/String.h"
#include "std_msgs/Float64.h"

// %EndTag(MSG_HEADER)%

#include <sstream>

/**
 * This tutorial demonstrates simple sending of messages over the ROS system.
 */
int main(int argc, char **argv)
{
 
  ros::init(argc, argv, "pub_hinge");
  ros::NodeHandle n;


  ros::Publisher hinge_publisher = n.advertise<std_msgs::Float64>("simple_model/base_to_second_joint_position_controller/command", 10);

  ros::Rate r(10);

  std_msgs::Float64 h;
  h.data = 0.13;
  int ctrl=0;
  while(ctrl==0){
    int connetctions=hinge_publisher.getNumSubscribers();
    if(connetctions>0){
      hinge_publisher.publish(h);
      ROS_INFO("%f", h.data);
      ctrl=1;
    }
    else{
      r.sleep();
    }
  }
  


  /*
  while (ros::ok()){
    std_msgs::Float64 h;
    h.data = 3.0;
    ROS_INFO("%f", h.data);
    //----rostopic pub /simple_model/base_to_second_joint_position_controller/command std_msgs/Float64 "data: 0.0"---
    hinge_publisher.publish(h);
    ros::spinOnce();
    loop_rate.sleep();
  }
  */

  


  return 0;
}