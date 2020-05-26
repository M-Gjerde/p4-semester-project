#ifndef DATACOLLECTOR_HPP
#define DATACOLLECTOR_HPP

#include "controller.hpp" //Includes the Controller class which initialize automatically all the communication with the arduino

namespace Sailboat{
    class DataCollector : public Controller{
            DataCollector(std::string name, int looprate) 
                : Controller(name,looprate, CONTROLLER::STANDBY){}
        
            public:
		    void setup(ros::NodeHandle* n);
		    geometry_msgs::Twist control();

            ...
    };
}
#endif