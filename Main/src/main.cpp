#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <menumanager.hpp>

int main()
{
    std::cout << "From the PiVersus team, hello world!" << std::endl;

    menuMgr menuMgr;
    menuMgr.startUp();

    //Run the program while the window is open. This is the Main loop
    while (menuMgr.window.isOpen())
    {
        // Check window events that were triggered since the last iteration of the loop
        sf::Event event;
        while (menuMgr.window.pollEvent(event))
        {
            switch (event.type)
            {
            // "Close" event, closes window
            // DO NOT DELETE THIS CASE! DOING SO MEANS THAT THE WINDOW WILL NOT BE ABLE TO CLOSE!
            case sf::Event::Closed:
                menuMgr.window.close();
                break;

            case sf::Event::KeyPressed:
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
                {
                    /* Code block for menuing to the left */
                    if (menuMgr.menuState > 0)
                    {
                        menuMgr.menuState--;
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
                {
                    /* code block for menuing to the right */
                    if (menuMgr.menuState < 2)
                    {
                        menuMgr.menuState++;
                    }
                }
                else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
                {
                    /* code block that should be equivalent to that of a click on the right spot */
                }

                break;

            // Mouse Button Press event
            case sf::Event::MouseButtonPressed:
                switch (event.mouseButton.button)
                {

                case sf::Mouse::Left:
                    menuMgr.leftClickManager();
                    break;

                default:
                    break;
                }
                break;

            case sf::Event::MouseButtonReleased:
                switch (event.mouseButton.button)
                {
                case sf::Mouse::Left:
                    break;

                default:
                    break;
                }

            default:
                break;
            }
        }

        menuMgr.menuGraphics();

        switch (menuMgr.menuState)
        {
        case 0:
            menuMgr.outline.setPosition(90.f, 410.f);
            break;

        case 1:
            menuMgr.outline.setPosition(480.f, 410.f);
            break;

        case 2:
            menuMgr.outline.setPosition(870.f, 410.f);
            break;

        default:
            break;
        }
    }

    return 0;
}