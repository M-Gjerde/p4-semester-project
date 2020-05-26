#include "data_collector_node/data_collector.hpp"

int main(int argc, char **argv) {
    Sailboat::DataCollector controller("DataCollector", 10);
    controller.init(argc, argv);

    std::cout << "Started data_collector_node" << std::endl;

    while (ros::ok()) {
	    controller.loop();
    }
    
    return 0;
}