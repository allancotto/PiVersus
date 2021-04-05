//threadManager class
#include "threadManager.h"
#include "iostream"
#include "menu.h"

ThreadManager::ThreadManager(Menu* menu, Driver* driver)
: menuJoystickThread(&ThreadManager::checkJoystick, this), menuPushButtonThread(&ThreadManager::checkPushbutton, this) {
    
    std::cout << "Initialising thread manager";
    menuOpen = true;
    this->menu = menu;
    this->driver = driver; 
    

}

void ThreadManager::checkJoystick() {

    while (menuOpen)
    {

        if(driver->getJoystickLR() == 1) {
            menu->MoveRight();
            sf::sleep(sf::milliseconds(500));

        } else if (driver->getJoystickLR() == -1) {
            menu->MoveLeft();
            sf::sleep(sf::milliseconds(300));

        }  
    }
}

void ThreadManager::checkPushbutton() {

    while (menuOpen)
    {
        if(driver->getPushButton() == 1) {
            switch (menu->menuState)
            {
            case 0:
                std::cout << "Game 1 selected" << std::endl;
                break;
            case 1:
                std::cout << "Game 2 selected" << std::endl;
                break;

            case 2:
                std::cout << "Game 3 selected" << std::endl;
                break;
            }
            sf::sleep(sf::milliseconds(500)); 
        }
    }
    
}


void ThreadManager::setAllFalse() {

    menuOpen = false;
}
