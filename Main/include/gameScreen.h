#include "SFML/Graphics.hpp"
#include <string>
#include <driver.h>

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
  void countdownTime();
  void scoreUpdate(int x, int y, int z);

  int gameSelected; 

private:

  void updateScore1(accel readings); //update score following rules of game 1
  void updateScore2(accel readings); // update score following rules of game 2
  accel scoreDifference(accel readings); // returns a score difference between two accelermeter readings
  int accelReadingDifference(int current, int previous);

  sf::Font font;
  sf::Text scoreText;
  sf::Text timeText;
  sf::Text readingsText;
  
  sf::RectangleShape scoreBackground;
  sf::RectangleShape timeBackground;
  sf::RectangleShape readingsBackground;
  sf::Texture background;
  sf::Sprite bgSprite;

  int gameDuration = 21;
  accel previousReadings;
  int currentScore = 0; 
  bool timeEnded = false;
};

#endif