#ifndef LOGGER_HPP
#define LOGGER_HPP

#include "controller.hpp" //Includes the Controller class which initialize automatically all the communication with the arduino
#include <fstream>
#include <iostream>

namespace Sailboat {
    class Data_logger : public Controller {
    public:
        Data_logger(std::string name, int looprate) : Controller(name, looprate, 0) {}

        void setup(ros::NodeHandle *n);
        bool loopUnpublished();
        geometry_msgs::Twist control();
        void gps_callback(std_msgs::String msg);

        ros::Subscriber gps_sub_for_real;
    private:
        std::ofstream outfile;
        ros::Publisher arduino_debug;
    };
}
#endif