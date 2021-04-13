#include <SFML/System.hpp>
#include <driver.h>
#include <menu.h>

#ifndef threadManager_h
#define threadManager_h

//thread manager also controls the state machine

//state mapping, 0 = menu, 1 = instructionsGame1, 2 = instructionsGame2, 3 = instructionsGame3
        


class ThreadManager {

public:
    ThreadManager(Menu* menu, Driver* driver); 

    int state; //allow thread manager to access the state

    void checkJoystick(); //function to check the joystick
    void checkPushButtonMenu(); // function to check pushbutton


    void setAllFalse(); // sets all thread variables to false to allow them to self terminate

    void checkPushButtonInstructions();
    void checkJoystickInstructions();
    void switchToInstructionMenu(); 

    // menu threads
    void launchMenuThreads();
    sf::Thread menuJoystickThread; //this thread will check for joystick inputs
    sf::Thread menuPushButtonThread; //this thread will check for pushbutton inputs
    
    bool menuOpen;
    bool instructionsOpen;

private:
    Menu* menu; //instance in the class will allow thread functions to access menu functions.
    Driver* driver; //again to allow threads to access driver functions
    

    
    

};

#endif



