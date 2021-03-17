#include <iostream>
#include <SFML/Graphics.hpp>



int main()
{
    std::cout << "From the PiVersus team, hello world!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "PiVersus");      //Making the window and giving it a title
    window.setVerticalSyncEnabled(true);                                //Turning on V-Sync
    sf::CircleShape shape(150.f);                                       //Making a placeholder shape
    shape.setFillColor(sf::Color::Green);                               //Defining it's fill colour

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
                case sf::Event::Closed:
                    window.close();
                    break;

                // Keyboard Key Press event
                case sf::Event::KeyPressed:
                    // Lovely code block that runs through the keyboard keys maybe
                    break;

                // Mouse Button Press event
                case sf::Event::MouseButtonPressed:
                    switch (event.mouseButton.button)
                    {

                    case sf::Mouse::Left:
                        // Left Click code block
                        break;

                    default:
                        break;
                    }
                    break;

                default:
                    break;
            }
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    return 0;
}