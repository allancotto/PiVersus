//threadManager class
#include "threadManager.h"
#include "iostream"
#include "menu.h"


ThreadManager::ThreadManager(Menu* menu, Driver* driver, Instructions* instructions, GameScreen* gameScreen)
: menuJoystickThread(&ThreadManager::checkJoystick, this), menuPushButtonThread(&ThreadManager::checkPushButton, this),
     accelerometerUpdateThread(&ThreadManager::updateAccelerometer, this), gameTimeUpdateThread(&ThreadManager::updateTime, this)  {
    
    std::cout << "Initialising thread manager";

    joystickThreadAlive = true;
    pushButtonThreadAlive = true;
    accelerometerThreadAlive = false;
    gameTimeThreadAlive = false;
    

    gameRunning = false; // extra boolean needed otherwise thread keeps running after game closed, (if closed in game state thread re-launches)

    this->menu = menu;
    this->driver = driver; 
    this->instructions = instructions;
    this->gameScreen = gameScreen;

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

void ThreadManager::updateAccelerometer() {

    while (accelerometerThreadAlive)
    {
    
    accel readings = driver->getAccelValues();
    gameScreen->updateReadings(readings.x/1000,readings.y/1000,readings.z/1000); 
    sf::sleep(sf::milliseconds(100));   
    }

}

void ThreadManager::updateTime() {
    while (gameTimeThreadAlive)
    {
        
        gameScreen->countdownTime();
        sf::sleep(sf::milliseconds(1000)); 
        
        
    }
}


void ThreadManager::setAllFalse() {

    endMenuThreads();
    endGameThreads();
}


void ThreadManager::launchMenuThreads() {

    menuJoystickThread.launch();
    menuPushButtonThread.launch();
    
}

void ThreadManager::launchGameThreads() {
    accelerometerThreadAlive = true;
    gameTimeThreadAlive = true;
    

    gameRunning = true;

    gameTimeUpdateThread.launch();
    accelerometerUpdateThread.launch();
    
}

void ThreadManager::endMenuThreads() {

    pushButtonThreadAlive = false;
    joystickThreadAlive = false;

}

void ThreadManager::endGameThreads() {

    accelerometerThreadAlive = false;
    gameTimeThreadAlive = false;
    

}

void ThreadManager::startGame() {
    if(!gameRunning) {
        endMenuThreads();
        launchGameThreads();

    }
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
                case 0: // enter a game
                    switch (state)
                    {
                    case 1:
                        state = 4; //currently in instruction state 1 which leads to game 1 (state 3...)
                        break;
                    
                    case 2:
                        state = 5;
                        break;
                    case 3:
                        state = 6;
                    }
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

