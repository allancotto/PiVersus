//game screen draw class
#include "gameScreen.h"

GameScreen::GameScreen(){
  font.loadFromFile("../Resources/Fonts/arial.ttf");

  background.loadFromFile("../Resources/Images/PiVersus_Logo.png");

  gameState = 0 // 0 for game 1 etc..

  bgSprite.setTexture(background);
  bgSprite.setPosition(100.f, 40.f);

  scoreText.setFont(font);
  scoreText.setString("0");
  scoreText.setCharacterSize(36); 
  scoreText.setFillColor(sf::Color::White);
  scoreText.setStyle(sf::Text::Bold);
  scoreText.setPosition(620.f, 425.f); 


  timeText.setFont(font);
  timeText.setString("10");
  timeText.setCharacterSize(36);
  timeText.setFillColor(sf::Color::White);
  timeText.setStyle(sf::Text::Bold);
  timeText.setPosition(620.f, 95.f); 

  readingsText.setFont(font);
  readingsText.setString("x: 00  y: 00  z: 00");
  readingsText.setCharacterSize(30);
  readingsText.setFillColor(sf::Color::White);
  readingsText.setStyle(sf::Text::Bold);
  readingsText.setPosition(515.f, 625.f); 


  timeBackground.setSize(sf::Vector2f(150.f, 60.f));
  timeBackground.setOutlineThickness(3.f);
  timeBackground.setFillColor(sf::Color(162, 44, 196));
  timeBackground.setOutlineColor(sf::Color(255,255,255));
  timeBackground.setPosition(565.f, 90.f);


  scoreBackground.setSize(sf::Vector2f(150.f, 60.f));
  scoreBackground.setOutlineThickness(3.f);
  scoreBackground.setFillColor(sf::Color(162, 44, 196));
  scoreBackground.setOutlineColor(sf::Color(255,255,255));
  scoreBackground.setPosition(565.f, 420.f);

  readingsBackground.setSize(sf::Vector2f(300.f, 60.f));
  readingsBackground.setOutlineThickness(3.f);
  readingsBackground.setFillColor(sf::Color(162, 44, 196));
  readingsBackground.setOutlineColor(sf::Color(255,255,255));
  readingsBackground.setPosition(490.f, 620.f);



}


void GameScreen::draw(sf::RenderWindow &window, int gameState) {

  gameState = gameState;

  window.draw(bgSprite);
  window.draw(timeBackground);
  window.draw(scoreBackground);
  window.draw(readingsBackground);

  window.draw(scoreText);
  window.draw(timeText);
  window.draw(readingsText);

}

