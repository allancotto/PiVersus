#include <SFML/System.hpp>
#include <driver.h>
#include <menu.h>

#ifndef threadManager_h
#define threadManager_h

class ThreadManager {



public:
    ThreadManager(Menu* menu, Driver* driver); 
    void checkJoystick(); //function to check the joystick
    void checkPushbutton(); // function to check pushbutton
    void setAllFalse(); // sets all thread variables to false to allow them to self terminate

    //threads
    sf::Thread menuJoystickThread; //this thread will check for joystick inputs
    sf::Thread menuPushButtonThread; //this thread will check for pushbutton inputs
    
    bool menuOpen;

private:
    Menu* menu; //instance in the class will allow thread functions to access menu functions.
    Driver* driver; //again to allow threads to access driver functions
    

    
    

};

#endif



