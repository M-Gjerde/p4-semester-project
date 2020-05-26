#include "data_collector_node/data_collector.hpp"
#include "math.h"
#include <fstream>
#include <iostream>
#include <utilities.hpp>
#include <ros/package.h>
#include <ctime>

using namespace Sailboat;
using namespace glm;

double PI = 3.141592653589793238462643383279502884;

void DataCollector::setup(ros::NodeHandle* n){
    
}

geometry_msgs::Twist DataCollector::control(){
    printIMU();

    geometry_msgs::Twist cmd;
    return cmd;
}

void DataCollector::printIMU() {
    vec3 heading = Utility::QuaternionToEuler(imuMsg.orientation);
    std::string ex =  std::to_string(heading[0]*10*(180/PI));
    std::string ey =  std::to_string(heading[1]*10*(180/PI));
    std::string ez =  std::to_string(heading[2]*10*(180/PI));
    std::cout << "X: " << ex << ",  Y: " << ey << ",  Z: " << ez << std::endl;
}