#ifndef LINEFOLLOWINGLONG_HPP
#define LINEFOLLOWINGLONG_HPP

#include "controller.hpp"
#include <glm/glm.hpp>

namespace Sailboat{
    class LineFollowingLong : public Controller{
	public:
        	LineFollowingLong(std::string name) : Controller(name,2, MODE::RUDDER_SAIL), r(10.0), currentWaypoint(0), nbWaypoints(0), q(1){}
        	~LineFollowingLong(){}
		void setup(ros::NodeHandle* n);
		virtual geometry_msgs::Twist control();
	private:
		int currentWaypoint;
		int nbWaypoints;

		glm::dvec2* waypoints;
		float r;
		int q;
    };
}

#endif
