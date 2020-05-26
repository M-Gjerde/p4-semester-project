#ifndef AREASCANNING_HPP
#define AREASCANNING_HPP

#include "controller.hpp"
#include <glm/glm.hpp>

namespace Sailboat{
    class AreaScanning : public Controller{
	public:
        AreaScanning(std::string name) : Controller(name,10, MODE::HEADING), tackingStart(NULL), rmax(20), q(1){}
        ~AreaScanning(){}
		void setup(ros::NodeHandle* n);
		virtual geometry_msgs::Twist control();

	private:
		int currentWaypoint;
		int nbWaypoints;
		glm::dvec2* waypoints;
		int* waypointsOrder;
		glm::dvec2* tackingStart;
		float rmax;
		float closeHauled;
		int q;

		void buildLKHFiles();
		void readResults();
	};
}

#endif
