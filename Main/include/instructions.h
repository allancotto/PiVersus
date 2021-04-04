#include "SFML/Graphics.hpp"

#ifndef instructions_h
#define instructions_h

#define NUMBER_OF_GAMES 3

class Instructions
{

public:
  Instructions();
  void draw(sf::RenderWindow &window, int State);

private:
  int menuState;
  sf::Font font;
  sf::Text instructionText[NUMBER_OF_GAMES];
  sf::RectangleShape outline;
  sf::RectangleShape startButton;
  sf::Texture background;
  sf::Sprite bgSprite;
};

#endif
