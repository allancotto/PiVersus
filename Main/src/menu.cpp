// menu class 
#include "menu.h"


Menu::Menu() {


    font.loadFromFile("../Resources/Fonts/arial.ttf");
    


    background.loadFromFile("../Resources/Images/PiVersus_Logo.png"); 
        
    bgSprite.setTexture(background);
    bgSprite.setPosition(100.f,40.f);

    
    

    games[0].setFont(font);
    games[0].setString("Soda Prank");
    games[0].setCharacterSize(24); // font size in pixels not points
    games[0].setFillColor(sf::Color::White);
    games[0].setStyle(sf::Text::Bold);
    games[0].setPosition(100.f, 420.f); // position to upper left corner

    games[1].setFont(font);
    games[1].setString("Statue Game");
    games[1].setCharacterSize(24); // font size in pixels not points
    games[1].setFillColor(sf::Color::White);
    games[1].setStyle(sf::Text::Bold);
    games[1].setPosition(490.f, 420.f); // position to upper left corner

    games[2].setFont(font);
    games[2].setString("Piggy Bank");
    games[2].setCharacterSize(24); // font size in pixels not points
    games[2].setFillColor(sf::Color::White);
    games[2].setStyle(sf::Text::Bold);
    games[2].setPosition(880.f, 420.f); // position to upper left corner

    menuState = 0;

    // for some reason defined value isn't currently working so defining here instead
    float menuButtonSizeX = 300.f, menuButtonSizeY = 200.f;

    
    outline.setSize(sf::Vector2f(menuButtonSizeX + 20.f, menuButtonSizeY + 20.f));
    outline.setOutlineThickness(3.f);
    outline.setOutlineColor(sf::Color(255, 255, 255));
    outline.setPosition(90.f, 410.f);

    for (int i=0; i< NUMBER_OF_GAMES; i++) {
        buttons[i].setSize(sf::Vector2f( menuButtonSizeX, menuButtonSizeY));
        buttons[i].setFillColor(sf::Color(162, 44, 196));
        buttons[i].setPosition(i*390.f + 100, 420.f); 
    }


}

 

void Menu::draw(sf::RenderWindow &window) {

    window.draw(bgSprite);
    window.draw(outline);

    // draw names and buttons
    for (int i=0; i< NUMBER_OF_GAMES; i++) {
        window.draw(buttons[i]);
        window.draw(games[i]);
    }
    
    
    
    window.draw(bgSprite);
}



void Menu::MoveRight() {

    if(menuState +1 <NUMBER_OF_GAMES ) {
        
        menuState++;
        outline.setPosition(buttons[menuState].getPosition().x-10,buttons[menuState].getPosition().y-10);
    }
}

void Menu::MoveLeft() {

    if(menuState -1 >= 0 ) {
        
        
        menuState--;
        outline.setPosition(buttons[menuState].getPosition().x-10,buttons[menuState].getPosition().y-10);
    }
}



  