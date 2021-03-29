#include <iostream>
#include "driver.h"
#include <chrono>
#include <thread>

// This file just loops and polls the driver for joystick events, not the most efficient but a simple way to test the joystick is connected and working.

// To compile code use command commented below, (no real need to -Wall etc) to run use "./joystickTest" when in the bin directory
// g++ -Wall -Wextra -std=c++17 -ggdb -Iinclude -Llib src/driver.cpp src/Testing/joystickOutputTest.cpp -o bin/joystickTest -l wiringPi

int main() {

    //create an instance of Driver
    Driver driver;

    while (1)
    {
        if (driver.getJoystickUD() == 1) {
            std::cout << "UP" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            
        } else if (driver.getJoystickUD() == -1) {
            std::cout << "DOWN" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }

        if (driver.getJoystickLR() == 1) {
            std::cout << "RIGHT" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
            
        } else if (driver.getJoystickLR() == -1) {
            std::cout << "LEFT" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(500));
        }
    }

    return 0;
}