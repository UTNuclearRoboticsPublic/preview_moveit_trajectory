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

#ifndef PREVIEW_MOVEIT_TRAJECTORY_H
#define PREVIEW_MOVEIT_TRAJECTORY_H

#include "gui_server/trigger_gui_server.h"
#include "moveit_msgs/DisplayTrajectory.h"
#include "moveit_msgs/RobotTrajectory.h"
#include <ros/ros.h>
#include <string>

std::string preview_traj( moveit_msgs::RobotTrajectory& traj, ros::NodeHandle& n );

#endif // PREVIEW_MOVEIT_TRAJECTORY_H