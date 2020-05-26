#include "user_friendly_test_node/user_friendly_test.hpp"
#include "math.h"
#include <fstream>
#include <iostream>
#include <utilities.hpp>
#include <ros/package.h>

using namespace Sailboat;
using namespace glm;

void UserTest::setup(ros::NodeHandle* n){
    std::cout << "setup run" << std::endl;
}

bool UserTest::loopUnpublished(){
    float lat = gpsMsg.latitude;
    float lon = gpsMsg.longitude;
    float alt = gpsMsg.altitude;

    //std::cout << "data : " << std::endl;
    //std::cout << "gps (lat,long,alt) : (" << lat << ", " << lon << ", " << alt << ")" << std::endl;

    geometry_msgs::Twist cmd;
    vec3 heading;
    dvec2 cmdv = Utility::StandardCommand(heading,0, 0.1, 3.14/3.0);
    cmd.angular.x = cmdv.x;
    cmd.angular.y = cmdv.y;

    return false;
}


geometry_msgs::Twist UserTest::control(){
    geometry_msgs::Twist cmd;
    std::cout << "Node Control loop" << std::endl;

    float input_x;
    std::cin >> input_x;
    cmd.angular.x = input_x;

    //std::cout << "set position" << std::endl;
    float input_y = 0;
    std::cin >> input_y;
    cmd.angular.y = input_y;
    //
    //std::cout << "angular (x, y) : " << angular_x << ", " << angular_y << std::endl;
    return cmd;
}

