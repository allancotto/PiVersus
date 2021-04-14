#include "SFML/Graphics.hpp"

#ifndef gamescreen_h
#define gamescreen_h

#define NUMBER_OF_PLAYERS 2

class GameScreen
{

public:
  GameScreen();
  void draw(sf::RenderWindow &window, int state);

  sf::Text scoreText;
  sf::Text timeText;
  sf::Text readingsText;
  int gameState; // to track what game has been selected

private:
  sf::Font font;
  
  sf::RectangleShape scoreBackground;
  sf::RectangleShape timeBackground;
  sf::RectangleShape readingsBackground;
  sf::Texture background;
  sf::Sprite bgSprite;
};

#endif