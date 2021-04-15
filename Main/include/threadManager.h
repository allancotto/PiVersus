#include <SFML/System.hpp>
#include <driver.h>
#include <menu.h>
#include <instructions.h>
#include <gameScreen.h>

#ifndef threadManager_h
#define threadManager_h

//thread manager also controls the state machine

//state mapping, 0 = menu, 1 = instructionsGame1, 2 = instructionsGame2, 3 = instructionsGame3
        


class ThreadManager {

public:
    ThreadManager(Menu* menu, Driver* driver, Instructions* instructions, GameScreen* gameScreen ); 

    int state; //allow thread manager to access the state
    bool gameRunning; // needed for thread management

    void checkJoystick(); //function to check the joystick
    void checkPushButton(); // function to check pushbutton

    void setAllFalse(); // sets all thread variables to false to allow them to self terminate

    void checkPushButtonInstructions();
    void checkJoystickInstructions();
    void switchToInstructionMenu(); 

    // menu threads
    void launchMenuThreads();
    void endMenuThreads();

    sf::Thread menuJoystickThread; //this thread will check for joystick inputs
    sf::Thread menuPushButtonThread; //this thread will check for pushbutton inputs

    // game threads
    void launchGameThreads();
    void endGameThreads();
    void startGame();
    
    void updateAccelerometer();
    void updateTime();

    sf::Thread accelerometerUpdateThread;
    //sf::Thread gameScoreUpdate;
    sf::Thread gameTimeUpdateThread;

    
    // booleans used to terminate threads
    bool joystickThreadAlive;   
    bool pushButtonThreadAlive;

    bool accelerometerThreadAlive;
    bool gameScoreUpdate;
    bool gameTimeThreadAlive;

private:
    Menu* menu; //instance in the class will allow thread functions to access menu functions.
    Driver* driver; //again to allow threads to access driver functions
    Instructions* instructions; // access instruction functions
    GameScreen* gameScreen; // access game screen

    void menuSelection(); // function to check what selection has been made when in the menu state
    void instructionSelection(); // function to check what selection has been made when in instruction state

    void menuMove(int LR); //when joystick triggers a menu movement
    void instructionMove(int LR); //when joystick triggers a movement in the instructions menu
    

    
    

};

#endif



