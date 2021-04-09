#include "SFML/Graphics.hpp"

#ifndef gamescreen_h
#define gamescreen_h

#define NUMBER_OF_PLAYERS 2

class GameScreen
{

public:
  GameScreen();
  void draw(sf::RenderWindow &window, int State);

private:
  int menuState;
  sf::Font font;
  sf::Text scoreText[NUMBER_OF_PLAYERS];
  sf::Text scoreDivider;
  sf::RectangleShape outline;
  sf::RectangleShape startButton;
  sf::Texture background;
  sf::Sprite bgSprite;
};

#endif