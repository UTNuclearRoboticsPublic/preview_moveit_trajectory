///////////////////////////////////////////////////////////////////////////////
//      Title     : preview_moveit_trajectory.cpp
//      Project   : preview_moveit_trajectory
//      Created   : 3/15/2018
//      Author    : Andy Zelenak
//      Platforms : Ubuntu 64-bit
//      Copyright : Copyright© The University of Texas at Austin, 2018. All rights reserved.
//                 
//          All files within this directory are subject to the following, unless an alternative
//          license is explicitly included within the text of each file.
//
//          This software and documentation constitute an unpublished work
//          and contain valuable trade secrets and proprietary information
//          belonging to the University. None of the foregoing material may be
//          copied or duplicated or disclosed without the express, written
//          permission of the University. THE UNIVERSITY EXPRESSLY DISCLAIMS ANY
//          AND ALL WARRANTIES CONCERNING THIS SOFTWARE AND DOCUMENTATION,
//          INCLUDING ANY WARRANTIES OF MERCHANTABILITY AND/OR FITNESS FOR A
//          PARTICULAR PURPOSE, AND WARRANTIES OF PERFORMANCE, AND ANY WARRANTY
//          THAT MIGHT OTHERWISE ARISE FROM COURSE OF DEALING OR USAGE OF TRADE.
//          NO WARRANTY IS EITHER EXPRESS OR IMPLIED WITH RESPECT TO THE USE OF
//          THE SOFTWARE OR DOCUMENTATION. Under no circumstances shall the
//          University be liable for incidental, special, indirect, direct or
//          consequential damages or loss of profits, interruption of business,
//          or related expenses which may arise from use of software or documentation,
//          including but not limited to those resulting from defects in software
//          and/or documentation, or loss or inaccuracy of data of any kind.
//
///////////////////////////////////////////////////////////////////////////////

#include "preview_moveit_trajectory.h"

std::string preview_traj( moveit_msgs::RobotState& start_state, moveit_msgs::RobotTrajectory& robot_traj, ros::NodeHandle& n )
{
  // Convert the incoming moveit_msgs::RobotTrajectory to moveit_msgs::DisplayTrajectory
  // The main difference is a start state definition
  moveit_msgs::DisplayTrajectory traj_display;
  traj_display.trajectory.push_back(robot_traj);

  traj_display.trajectory_start = start_state;

  // Publish the traj to RViz. Latch it
  ros::Publisher traj_pub = n.advertise<moveit_msgs::DisplayTrajectory>("/move_group/display_planned_path", 1, true);

  // Preview in RViz several times
  for( int i=0; i<5; i++ )
    traj_pub.publish(traj_display);

  // Launch the popup via service call
  ros::ServiceClient client = n.serviceClient<gui_server::trigger_gui_server>("/gui_server/trigger");
  gui_server::trigger_gui_server srv;
  //rosservice call /gui_server/trigger "graphic_type: 'push_button' text_to_display: 'Thank you come again'"
  srv.request.graphic_type = "push_button";
  srv.request.text_to_display = "Accept";
  if (!client.call(srv))
  {
    ROS_ERROR("Failed to call /gui_server/trigger");
    return "error";
  }


  // Return a string based on the user's selection

  return srv.response.response;
}