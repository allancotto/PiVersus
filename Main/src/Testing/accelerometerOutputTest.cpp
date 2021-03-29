#include <iostream>
#include "driver.h"
#include <chrono>
#include <thread>



// This is a test file for a program displays real time data from the accelerometer.

// To compile code use command commented below, (no real need to use -Wall etc) to run use "./accelerometerOutput" when in the bin directory
// g++ -Wall -Wextra -std=c++17 -ggdb -Iinclude -Llib src/driver.cpp src/Testing/accelerometerOutputTest.cpp -o bin/accelerometerOutput -l wiringPi

int main() {

    //create an instance of Driver
    Driver driver;

    //variable to store sensor values
    accel values;

    while (1)
    {
        values = driver.getAccelValues();
        std::cout << "x: " << values.x << ", y: " << values.y << ", z: " << values.z << "\n";
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    
    return 0;
}