#include "logger_node/logger.hpp"
#include "math.h"
#include <fstream>
#include <iostream>
#include <utilities.hpp>
#include <ros/package.h>
#include <ctime>

using namespace Sailboat;
using namespace glm;

void Data_logger::setup(ros::NodeHandle *n) {
    std::cout << "setup run logger" << std::endl;

    outfile.open("/home/sailboat/catkin_ws/src/SailBoatROS/sailrobot/data/gps_data.log", std::ios_base::app);
    outfile.close();

    arduino_debug = n->advertise<std_msgs::String>("/arduino_debug", 10);


    gps_sub_for_real = n->subscribe("/sailboat/gps", 100, &Data_logger::gps_callback, this);


}

bool Data_logger::loopUnpublished() {
    /*
    float lat = gpsMsg.latitude;
    float lon = gpsMsg.longitude;
    float alt = gpsMsg.altitude;
    float speed = gpsMsg.speed;
    float time = gpsMsg.time;

    std::string str = std::to_string(time);

    std::string hours = str.substr(0, 2);
    std::string minutes = str.substr(2, 2);
    std::string seconds = str.substr(4, 4);
    std::string time_formatted = hours + ":" + minutes;

    outfile.open("/home/sailboat/catkin_ws/src/SailBoatROS/sailrobot/data/gps_data.log", std::ios_base::app);

    time_t curr_time;
    curr_time = std::time(NULL);
    char *tm = ctime(&curr_time);
    std::cout << "Current time : " << tm;

    outfile << lat << ", " << lon << ", " << alt << ", " << speed << ", " << time << ", " << tm;
    outfile.close();

     */

    return false;
}

geometry_msgs::Twist Data_logger::control() {
    geometry_msgs::Twist cmd;
	int input;
    return cmd;
}

void Data_logger::gps_callback(std_msgs::String msg){
    std::cout << "gpsCallback\n" << msg << std::endl;
    outfile.open("/home/sailboat/catkin_ws/gps22-04.log", std::ios_base::app);
    outfile << msg;
    outfile.close();

}


