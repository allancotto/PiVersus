#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <menu.h>
#include <threadManager.h>
#include <wiringPi.h>
#include <instructions.h>

int main()
{
    std::cout << "From the PiVersus team, hello world!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "PiVersus"); //Making the window and giving it a title
    window.setVerticalSyncEnabled(true); //Turning on V-Sync

    enum state
    {
        STATE_MENU,
        STATE_INSTRUCTIONS_GAME_ONE,
        STATE_INSTRUCTIONS_GAME_TWO,
        STATE_INSTRUCTIONS_GAME_THREE,
        STATE_GAME_ONE,
        STATE_GAME_TWO,
        STATE_GAME_THREE
    };
    state state_;
    state_ = STATE_INSTRUCTIONS_GAME_ONE;
    

    //initialise class instances
    Menu menu;
    Driver driver;
    Instructions instructions;
    ThreadManager tManager(&menu, &driver);

    tManager.menuJoystickThread.launch();
    tManager.menuPushButtonThread.launch();
    



    
    

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
        switch (state_){
            case STATE_MENU:
                menu.draw(window);
                break;
            case STATE_INSTRUCTIONS_GAME_ONE:
                instructions.draw(window, 0);
                break;
            case STATE_INSTRUCTIONS_GAME_TWO:
                instructions.draw(window, 1);
                break;
            case STATE_INSTRUCTIONS_GAME_THREE:
                instructions.draw(window, 2);
                break;
            default:
                break;
        }
        window.display();

        //if (soundFlag)
        //welcomeVoiceClip.play();
        //soundFlag = 0;
    }

    return 0;
}