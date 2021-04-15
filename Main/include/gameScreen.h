#include "SFML/Graphics.hpp"
#include <string>

using namespace std;

#ifndef gamescreen_h
#define gamescreen_h

#define NUMBER_OF_PLAYERS 2

class GameScreen
{

public:
  GameScreen();
  void draw(sf::RenderWindow &window, int state);

  void updateReadings(int x, int y, int z); 

private:
  sf::Font font;

  

  sf::Text scoreText;
  sf::Text timeText;
  sf::Text readingsText;
  
  sf::RectangleShape scoreBackground;
  sf::RectangleShape timeBackground;
  sf::RectangleShape readingsBackground;
  sf::Texture background;
  sf::Sprite bgSprite;
};

#endif