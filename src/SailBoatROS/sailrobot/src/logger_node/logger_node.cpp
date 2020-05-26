#include "logger_node/logger.hpp"

int main(int argc, char **argv) {
    Sailboat::Data_logger controller("Logger", 1);
    controller.init(argc, argv);

    std::cout << "Started logging node" << std::endl;

    while (ros::ok()) {
        controller.loop();
    }
    return 0;
}
