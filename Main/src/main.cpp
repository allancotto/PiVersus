#include <iostream>
#include <SFML/Graphics.hpp>

int main()
{
    std::cout << "From the PiVersus team, hello world!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "PiVersus"); //Making the window and giving it a title
    window.setVerticalSyncEnabled(true);                           //Turning on V-Sync
    sf::CircleShape shape(150.f);                                  //Making a placeholder shape
    shape.setFillColor(sf::Color::Green);                          //Defining it's fill colour

    bool isLeftClickPressed = false; //Boolean to handle when the Left Mouse Button is pressed.
    float menuButtonSizeX = 300.f, menuButtonSizeY = 200.f;
    sf::Vector2i cursorWindowPosition; //2D Vector with the coordinates of the mouse cursor in the window
    sf::Vector2f buttonOnePosition, buttonTwoPosition, buttonThreePosition;

    sf::RectangleShape buttonOne(sf::Vector2f(menuButtonSizeX, menuButtonSizeY));   //Making the shape for the button for game 1
    sf::RectangleShape buttonTwo(sf::Vector2f(menuButtonSizeX, menuButtonSizeY));   //Repeating for button 2...
    sf::RectangleShape buttonThree(sf::Vector2f(menuButtonSizeX, menuButtonSizeY)); //...and button 3

    sf::Font arialFont; //Variable for text font

    sf::Text gameOne; //Variables for text that go over the buttons that are numbered accordingly
    sf::Text gameTwo;
    sf::Text gameThree;

    /* START OF VARIABLE TRANSFORM SECTION */

    buttonOne.setFillColor(sf::Color(163, 44, 196)); //Fill colours for the button shapes
    buttonOne.setPosition(100.f, 420.f);             //Setting the positions for the shapes...
    buttonOnePosition = buttonOne.getPosition();     //...and parsing them into a vector variable for click detection purposes
    buttonTwo.setFillColor(sf::Color(163, 44, 196));
    buttonTwo.setPosition(490.f, 420.f);
    buttonTwoPosition = buttonTwo.getPosition();
    buttonThree.setFillColor(sf::Color(163, 44, 196));
    buttonThree.setPosition(880.f, 420.f);
    buttonThreePosition = buttonThree.getPosition();

    arialFont.loadFromFile("../src/Resources/Fonts/arial.ttf"); //Load the text font from file

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
            // DO NOT DELETE THIS CASE! DOING SO MEANS THAT THE WINDOW WILL NOT BE ABLE TO CLOSE!
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

        if (isLeftClickPressed)
        { //Click detection code block
            cursorWindowPosition = sf::Mouse::getPosition(window);

            if ((cursorWindowPosition.x > buttonOnePosition.x) && (cursorWindowPosition.x < buttonOnePosition.x + menuButtonSizeX) && (cursorWindowPosition.y > buttonOnePosition.y) && (cursorWindowPosition.y < buttonOnePosition.y + menuButtonSizeY))
            {
                std::cout << "You have successfully clicked on game 1!" << std::endl;
                //Code block that moves to the instruction scene for game one, perhaps after some nice effects.
            }

            if ((cursorWindowPosition.x > buttonTwoPosition.x) && (cursorWindowPosition.x < buttonTwoPosition.x + menuButtonSizeX) && (cursorWindowPosition.y > buttonTwoPosition.y) && (cursorWindowPosition.y < buttonTwoPosition.y + menuButtonSizeY))
            {
                std::cout << "You have successfully clicked on game 2!" << std::endl;
                //Code block that moves to the instruction scene for game two, perhaps after some nice effects.
            }

            if ((cursorWindowPosition.x > buttonThreePosition.x) && (cursorWindowPosition.x < buttonThreePosition.x + menuButtonSizeX) && (cursorWindowPosition.y > buttonThreePosition.y) && (cursorWindowPosition.y < buttonThreePosition.y + menuButtonSizeY))
            {
                std::cout << "You have successfully clicked on game 3!" << std::endl;
                //Code block that moves to the instruction scene for game three, perhaps after some nice effects.
            }
        }
    }

    return 0;
}