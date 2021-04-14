#include "SFML/Graphics.hpp"

#ifndef gamescreen_h
#define gamescreen_h

#define NUMBER_OF_PLAYERS 2

class GameScreen
{

public:
  GameScreen();
  void draw(sf::RenderWindow &window);

private:
  sf::Font font;
  sf::Text scoreText;
  sf::Text scoreDivider;
  sf::RectangleShape scoreBackround;
  sf::RectangleShape timeBackbround;
  sf::Texture background;
  sf::Sprite bgSprite;
};

#endif