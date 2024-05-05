#include <array>
#include "MOTOR_CONTROL.h"


// functions that will be moved when i can figure out how that works
std::array<Motor*, 6> initialize_wheel_motors(Robot* rover) {
	std::array<std::string, 6> wheel_motor_names = { "front left wheel motor", "front right wheel motor",
													 "mid left wheel motor", "mid right wheel motor",
													 "back left wheel motor", "back right wheel motor" };
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