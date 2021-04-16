#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <menu.h>
#include <threadManager.h>
#include <wiringPi.h>
#include <instructions.h>
#include <gameScreen.h>

int main()
{
    std::cout << "From the PiVersus team, hello world!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "PiVersus"); //Making the window and giving it a title
    window.setVerticalSyncEnabled(true); //Turning on V-Sync


    //initialise class instances and state variable
    Menu menu;
    Driver driver;
    Instructions instructions;
    GameScreen gameScreen;
    ThreadManager threadManager(&menu, &driver, &instructions, &gameScreen);

    //launch main menu threads initially
    threadManager.launchMenuThreads();

    //Run the program while the window is open. This is the Main loop
    while (window.isOpen())
    {   
        // Check window events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            // "Close" event, closes window
            // DO NOT DELETE THIS CASE! DOING SO MEANS THAT THE WINDOW WILL NOT BE ABLE TO CLOSE!
            case sf::Event::Closed:
                window.close();
                threadManager.setAllFalse(); //allows all thread functions to return.
                break;
            }
        }

        window.clear(sf::Color::Black);
        switch (threadManager.state){
            case 0:
                menu.draw(window);
                break;
            case 1:
                instructions.draw(window, 0);
                break;
            case 2:
                instructions.draw(window, 1);
                break;
            case 3:
                instructions.draw(window, 2);
                break;
            case 4:
                gameScreen.draw(window, 0);
                threadManager.startGame();
                break;
            case 5:
                gameScreen.draw(window, 1);
                threadManager.startGame();
                break;
            case 6:
                gameScreen.draw(window, 2);
                threadManager.startGame();
                break;

        }
        window.display();

    }

    return 0;
}


