//threadManager class
#include "threadManager.h"
#include "iostream"
#include "menu.h"

ThreadManager::ThreadManager(Menu* menu, Driver* driver)
: menuJoystickThread(&ThreadManager::checkJoystick, this) {
    
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
            sf::sleep(sf::milliseconds(500));

        }  
    }
}


void ThreadManager::setAllFalse() {

    menuOpen = false;
}
