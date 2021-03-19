#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    std::cout << "From the PiVersus team, hello world!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "PiVersus"); //Making the window and giving it a title
    window.setVerticalSyncEnabled(true);                           //Turning on V-Sync
    sf::CircleShape shape(150.f);                                  //Making a placeholder shape
    shape.setFillColor(sf::Color::Green);                          //Defining it's fill colour

    bool isLeftClickPressed; //Boolean to handle when the Left Mouse Button is pressed.

    sf::RectangleShape buttonOne(sf::Vector2f(300.0f, 200.0f));   //Making the shape for the button for game 1
    sf::RectangleShape buttonTwo(sf::Vector2f(300.0f, 200.0f));   //Repeating for button 2...
    sf::RectangleShape buttonThree(sf::Vector2f(300.0f, 200.0f)); //...and button 3

    sf::Font arialFont; //Variable for text font

    sf::Text gameOne; //Variables for text that go over the buttons that are numbered accordingly
    sf::Text gameTwo;
    sf::Text gameThree;

    /* START OF VARIABLE TRANSFORM SECTION */

    buttonOne.setFillColor(sf::Color(163, 44, 196)); //Fill colours for the button shapes
    buttonOne.setPosition(100.f, 420.f);             //Setting the positions for the shapes
    buttonTwo.setFillColor(sf::Color(163, 44, 196));
    buttonTwo.setPosition(490.f, 420.f);
    buttonThree.setFillColor(sf::Color(163, 44, 196));
    buttonThree.setPosition(880.f, 420.f);

    arialFont.loadFromFile("Main/src/Resources/Fonts/arial.ttf"); //Load the text font from file

    gameOne.setFont(arialFont);             //Transforms for text 1, which goes over button 1. This is setting up the font.
    gameOne.setString("Soda Prank");        //Setting the string message
    gameOne.setCharacterSize(24);           //Setting the font size (in pixels, NOT points)
    gameOne.setFillColor(sf::Color::White); //Setting text colour
    gameOne.setStyle(sf::Text::Bold);       //Setting text to bold
    gameOne.setPosition(100.f, 420.f);      //Setting the position. This should be at the upper left corner of the shape it's in

    gameTwo.setFont(arialFont); //This process is repeated for text 2, which goes over button 2...
    gameTwo.setString("Statue Game");
    gameTwo.setCharacterSize(24);
    gameTwo.setFillColor(sf::Color::White);
    gameTwo.setStyle(sf::Text::Bold);
    gameTwo.setPosition(490.f, 420.f);

    gameThree.setFont(arialFont); //...and text 3, which goes over button 3.
    gameThree.setString("Piggy Bank");
    gameThree.setCharacterSize(24);
    gameThree.setFillColor(sf::Color::White);
    gameThree.setStyle(sf::Text::Bold);
    gameThree.setPosition(880.f, 420.f);

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
                // Lovely code block that runs through the keyboard keys
                break;

            // Mouse Button Press event
            case sf::Event::MouseButtonPressed:
                switch (event.mouseButton.button)
                {

                case sf::Mouse::Left:
                    isLeftClickPressed = true; //Setting & keeping up a flag for as long as the left click is pressed
                    break;

                default:
                    break;
                }
                break;

            case sf::Event::MouseButtonReleased:
                switch (event.mouseButton.button)
                {
                case sf::Mouse::Left:
                    isLeftClickPressed = false; //Dropping the above flag when left click is released
                    break;

                default:
                    break;
                }

            default:
                break;
            }
        }

        window.clear(sf::Color::Black);

        window.draw(buttonOne);
        window.draw(buttonTwo);
        window.draw(buttonThree);
        window.draw(gameOne);
        window.draw(gameTwo);
        window.draw(gameThree);
        window.display();
    }

    return 0;
}