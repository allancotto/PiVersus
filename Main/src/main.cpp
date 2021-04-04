#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <menu.h>
#include <threadManager.h>
#include <stateMachine.h>

int main()
{
    std::cout << "From the PiVersus team, hello world!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "PiVersus"); //Making the window and giving it a title
    window.setVerticalSyncEnabled(true); //Turning on V-Sync

    //initialise class instances
    Menu menu;
    Driver driver;
    ThreadManager tManager(&menu, &driver);
    StateManager StateManager;


    tManager.menuJoystickThread.launch();

    

    
    
    //bool soundFlag = true;
    //sf::SoundBuffer buffer;     //Starting the sound buffer for voice clips.
    //sf::Sound welcomeVoiceClip; //Variable that plays the welcome sound clip
    // buffer.loadFromFile("../src/Resources/Audio/Welcome.wav");  //Load the welcome sound effect into the sound buffer
    // welcomeVoiceClip.setBuffer(buffer);


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
                tManager.setAllFalse(); //allows all thread functions to return.
                break;


            //key released code no longer necessarry, joystick now controls menu movement.
            case sf::Event::KeyReleased:
                switch (event.key.code)
                {
                case sf::Keyboard::D:
                    menu.MoveRight();
                    break;
                
                case sf::Keyboard::A:
                    menu.MoveLeft();
                    break;
                }
            }
        }

        window.clear(sf::Color::Black);
        menu.draw(window);
        window.display();

        //if (soundFlag)
        //welcomeVoiceClip.play();
        //soundFlag = 0;
    }

    return 0;
}