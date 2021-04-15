#include "SFML/Graphics.hpp"

#ifndef instructions_h
#define instructions_h

#define NUMBER_OF_GAMES 3

class Instructions
{

public:
  int instructionState; // to know what button is selected - either play the game or go back to the main menu

  Instructions();
  void draw(sf::RenderWindow &window, int State);

  void moveRight();
  void moveLeft();

private:
  sf::Font font;
  sf::Text instructionText[NUMBER_OF_GAMES];
  sf::Text buttonText[2];
  sf::RectangleShape outline;
  sf::RectangleShape buttons[2];
  sf::Texture background;
  sf::Sprite bgSprite;
};

#endif
