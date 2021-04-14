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

        if(LR == 1 || LR == -1) {

        switch (state)
        {

        case 0:
            menuMove(LR);
            sf::sleep(sf::milliseconds(300));  

            break;

        case 1 ... 3:
            instructionMove(LR);
            sf::sleep(sf::milliseconds(300));

            break;
        
        default:
            joystickThreadAlive = false;    //kill the thread if the current state doesn't need the joystick
        }
        }
        
    }
}

void ThreadManager::checkPushButton() {

    while (pushButtonThreadAlive)
    {
    if(driver->getPushButton() == 1) {
            switch (state)
            {
            case 0:
                menuSelection();
                break;
                
            case 1 ... 3:
                instructionSelection();
                break;

            default:
                pushButtonThreadAlive = false;
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

void ThreadManager::menuSelection() {

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

}

void ThreadManager::instructionSelection() {

    switch (instructions->instructionState)
                {
                case 0:
                    std::cout << "Play game selected" << std::endl;
                    break;
                
                case 1:
                    state = 0; //go back to main menu
                    instructions->moveLeft();
                    break;
    }
                
}

void ThreadManager::menuMove(int LR) {
    
    if(LR == 1) {
            menu->MoveRight();

        } else if (LR == -1) {
            menu->MoveLeft();
            
    }    
  
}

void ThreadManager::instructionMove(int LR) {

    if(LR == 1) {
            instructions->moveRight();
            

        } else if (LR == -1) {
            instructions->moveLeft();
            
        }    
}

