#include "ros/ros.h"
#include "turtlesim/Pose.h"
#include<iostream>

void showpoint(turtlesim::Pose p){
    
    std::cout<<"x:"<<p.x<<std::endl;
    std::cout<<"y:"<<p.y<<std::endl;
    std::cout<<"------------------\n";
    
}

int main(int argc, char **argv){

    ros::init(argc, argv, "point");
    ros::NodeHandle n;
    ros::Subscriber pose= n.subscribe<turtlesim::Pose>("/turtle1/pose", 10,showpoint);

    ros::spin();
        
     
     return 0;
}


