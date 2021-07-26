#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include<iostream>

const double PI = 3.14159265359;


int main(int argc, char **argv){
  ros::init(argc, argv, "circle");
  
  ros::NodeHandle n;
  ros::Publisher cmdVelPub = n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 1);
 
  ros::Rate loopRate(2);

  ROS_INFO("circle cpp start...");//輸出顯示信息

    std::cout << "enter the key to move the turtle\n";
    char c;
    std::cin >> c;

    int count=0;


        while (ros::ok()){
           
            geometry_msgs::Twist speed;

            if(c=='s'){             //square
            std::cout<<"square\n";
            speed.linear.y = 1.5;
            count++;
            while(count==5){
                speed.linear.y=0;
                speed.angular.z= PI; 
                count=0;
            }
            }
            else if(c=='t'){         //triangle
            std::cout<<"triangle\n";
            speed.linear.x=2;
            count++;
            while(count==5){
                speed.angular.z= PI/3*4;
                speed.linear.x=0;
                count =0;
            }
            }
            else{
                std::cout<<"you muffinhead,try again\n";
                std::cin>>c;
            }
            cmdVelPub.publish(speed); 
            ros::spinOnce();
            loopRate.sleep();   
        }
    
    
  return 0;
}