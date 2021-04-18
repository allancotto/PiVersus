#include "SFML/Graphics.hpp"

#ifndef menu_h
#define menu_h

#define NUMBER_OF_GAMES 2

class Menu {

public:
    Menu();
    void draw(sf::RenderWindow &window);
    void MoveRight();
    void MoveLeft();
    int menuState;

private:
    sf::Font font;
    sf::Text games[NUMBER_OF_GAMES];
    sf::RectangleShape outline;
    sf::RectangleShape buttons[NUMBER_OF_GAMES];
    sf::Texture background;
    sf::Sprite bgSprite;
};

#endif

