#include "SFML/Graphics.hpp"

#ifndef menu_h
#define menu_h

#define NUMBER_OF_GAMES 3

class Menu {

public:
    Menu(float width, float height);

    void draw(sf::RenderWindow &window);
    void MoveRight();
    void MoveLeft();


private:
    int menuState;
    sf::Font font;
    sf::Text games[NUMBER_OF_GAMES];
    sf::RectangleShape outline;
    sf::RectangleShape buttons[NUMBER_OF_GAMES];
    sf::Texture background;
    sf::Sprite bgSprite;
    


};

#endif

