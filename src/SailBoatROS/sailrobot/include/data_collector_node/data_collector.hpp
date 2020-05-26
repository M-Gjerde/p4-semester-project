#ifndef DATACOLLECTOR_HPP
#define DATACOLLECTOR_HPP

#include "controller.hpp" //Includes the Controller class which initialize automatically all the communication with the arduino
#include <fstream>
#include <iostream>

namespace Sailboat{
    class DataCollector : public Controller{
        public:
        DataCollector(std::string name, int looprate) : Controller(name,looprate, MODE::STANDBY){}

        void printIMU();

	    void setup(ros::NodeHandle* n);
	    geometry_msgs::Twist control();
    };
}
#endif