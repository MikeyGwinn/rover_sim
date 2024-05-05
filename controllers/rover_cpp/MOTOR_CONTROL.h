#pragma once

std::array<Motor*, 6> initialize_wheel_motors(Robot* rover);
void drive_forward(Robot* rover, std::array<Motor*, 6> wheel_motors);