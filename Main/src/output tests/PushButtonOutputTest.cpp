#include <iostream>
#include "driver.h"
#include <chrono>
#include <thread>



// This is a test file for a program displays the real time output of the push button.

// To compile code use command commented below, (no real need to use -Wall etc) to run use "./pushbuttonOutput" when in the bin directory
// g++ -Wall -Wextra -std=c++17 -ggdb -Iinclude -Llib src/driver.cpp src/Testing/PushButtonOutputTest.cpp -o bin/pushButton -l wiringPi

//comment out else statement if you only want to see an output when the button is pressed, and feel free to play with the sleep times.

int main() {

    //create an instance of Driver
    Driver driver;
    while (1)
    {

        if(driver.getPushButton() == 1) {
            std::cout << "PushButton Pressed" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            
        } else {
            std::cout << "PushButton Not Pressed" << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
            
        }
        
    }
    
    return 0;
}