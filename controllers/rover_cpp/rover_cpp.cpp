//this is a test

// c++ imports
#include<iostream>
#include<array>
#include<string>

// webots imports
#include <webots/Robot.hpp>
#include <webots/Motor.hpp>

// source header files


// constant definitions
#define TIME_STEP 64
#define MAX_SPEED 6.28

// All the webots classes are defined in the "webots" namespace
using namespace webots;

// functions that will be moved when i can figure out how that works
std::array<Motor*, 6> initialize_wheel_motors(Robot* rover) {
	std::array<std::string, 6> wheel_motor_names = { "front left wheel motor", "front right wheel motor",
													 "mid left wheel motor", "mid right wheel motor",
													 "back left wheel motor", "back right wheel motor"};
		std::array<Motor*, 6> initialized_wheels;
		for (int i = 0; i < 6; ++i) {
		initialized_wheels[i] = rover->getMotor(wheel_motor_names[i]);
	}
	return initialized_wheels;
}

void drive_forward(Robot* rover, std::array<Motor*, 6> wheel_motors) {
	for (int i = 0; i < 6; ++i) {
		wheel_motors[i]->setPosition(INFINITY);
		wheel_motors[i]->setVelocity(0.25 * MAX_SPEED);
	}
}

int main(int argc, char** argv) {
	Robot* rover = new Robot();

	std::array<Motor*, 6> wheel_motors = initialize_wheel_motors(rover);
	drive_forward(rover, wheel_motors);

	while (rover->step(TIME_STEP) != -1);

	
	delete rover;
	return 0;
}