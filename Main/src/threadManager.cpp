//threadManager class
#include "threadManager.h"
#include "iostream"
#include "menu.h"

ThreadManager::ThreadManager(Menu* menu, Driver* driver, Instructions* instructions)
: menuJoystickThread(&ThreadManager::checkJoystick, this), menuPushButtonThread(&ThreadManager::checkPushButton, this) {
    
    std::cout << "Initialising thread manager";

    joystickThreadAlive = true;
    pushButtonThreadAlive = true;

    this->menu = menu;
    this->driver = driver; 
    this->instructions = instructions;

    state = 0; //initially set state to 0 for menu
    

}

void ThreadManager::checkJoystick() {

    while(joystickThreadAlive)
    {
        int LR = driver->getJoystickLR();

        switch (state)
        {

        case 0:

        if(LR == 1) {
            menu->MoveRight();
            sf::sleep(sf::milliseconds(300));

        } else if (LR == -1) {
            menu->MoveLeft();
            sf::sleep(sf::milliseconds(300));
        }    

        case 1 ... 3:

        if(LR == 1) {
            instructions->moveRight();
            sf::sleep(sf::milliseconds(300));

        } else if (LR == -1) {
            instructions->moveLeft();
            sf::sleep(sf::milliseconds(300));
        }    

        break;
        
        default:
            joystickThreadAlive = false;    //kill the thread if the current state doesn't need the joystick
        }
        
    }
}

void ThreadManager::checkPushButton() {

    while (pushButtonThreadAlive)
    {
        if(driver->getPushButton() == 1) {
            switch (menu->menuState)
            {
            case 0:
                std::cout << "Game 1 selected" << std::endl;
                state = 1;
                break;
            case 1:
                std::cout << "Game 2 selected" << std::endl;
                state = 2;
                break;

            case 2:
                state = 3;
                std::cout << "Game 3 selected" << std::endl;
                break;
            }
            sf::sleep(sf::milliseconds(500)); 
        }
    }
    
}


void ThreadManager::setAllFalse() {
    pushButtonThreadAlive = false;
    joystickThreadAlive = false;
}

void ThreadManager::launchMenuThreads() {

    menuJoystickThread.launch();
    menuJoystickThread.launch();
    
}


