///////////////////////////////////////////////////////////////////////////////
//      Title     : test_preview_moveit_trajectory.cpp
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

// To use this test:
// catkin build --make-args tests -- preview_moveit_trajectory  (BUILD IT)
// catkin build --make-args test -- preview_moveit_trajectory   (RUN IT)
// catkin_test_results build   (SEE OUTPUT)

#include "gtest/gtest.h"
#include "moveit_msgs/RobotTrajectory.h"
#include "preview_moveit_trajectory.h"
#include "ros/ros.h"

TEST(myTester, test_traj_display){
  ros::NodeHandle n;

  // Build a trajectory
  moveit_msgs::RobotTrajectory robot_traj;

  trajectory_msgs::JointTrajectoryPoint pt0;
  pt0.positions.push_back(1.);
  pt0.time_from_start = ros::Duration(0.1);

  robot_traj.joint_trajectory.header.stamp = ros::Time::now();
  robot_traj.joint_trajectory.header.frame_id = "base_link";
  robot_traj.joint_trajectory.joint_names.push_back("right_ur5_shoulder_pan_joint");
  robot_traj.joint_trajectory.points.push_back(pt0);

  // Call the function that should display the trajectory in RViz and trigger a popup
  preview_traj(robot_traj, n);

  // Return true (test passes) if the user clicks any button (any string is returned)

  EXPECT_TRUE(true);
}

int main(int argc, char **argv)
{
  ros::init(argc, argv, "test_preview_moveit_trajectory");
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}