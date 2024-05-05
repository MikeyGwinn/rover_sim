// c++ imports
#include<iostream>
#include<array>
#include<string>

// webots imports
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

// source header files
#include "MOTOR_CONTROL.h"

// constant definitions
#define TIME_STEP 64
#define MAX_SPEED 6.28

// All the webots classes are defined in the "webots" namespace
using namespace webots;

int main(int argc, char** argv) {
	Robot* rover = new Robot();

	std::array<Motor*, 6> wheel_motors = initialize_wheel_motors(rover);
	drive_forward(rover, wheel_motors);

	while (rover->step(TIME_STEP) != -1);

	
	delete rover;
	return 0;
}