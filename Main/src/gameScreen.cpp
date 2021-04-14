//game screen draw class
#include "gameScreen.h"

GameScreen::GameScreen(){
  font.loadFromFile("../Resources/Fonts/arial.ttf");

  background.loadFromFile("../Resources/Images/PiVersus_Logo.png");

  bgSprite.setTexture(background);
  bgSprite.setPosition(100.f, 40.f);

  scoreText.setFont(font);
  scoreText.setString("0");
  scoreText.setCharacterSize(36); // font size in pixels not points
  scoreText.setFillColor(sf::Color::White);
  scoreText.setStyle(sf::Text::Bold);
  scoreText.setPosition(540.0f + 270.f, 360.f); // position to upper left corner


  scoreDivider.setFont(font);
  scoreDivider.setString("-");
  scoreDivider.setCharacterSize(36);
  scoreDivider.setFillColor(sf::Color::White);
  scoreDivider.setStyle(sf::Text::Bold);
  scoreDivider.setPosition(540.f, 360.f); // position to upper left corner

  

    
  timeBackbround.setSize(sf::Vector2f(300.f, 100.f));
  timeBackbround.setOutlineThickness(3.f);
  timeBackbround.setOutlineColor(sf::Color(255, 255, 255));
  timeBackbround.setPosition(90.f, 410.f);
}


void GameScreen::draw(sf::RenderWindow &window) {

  window.draw(bgSprite);
  window.draw(timeBackbround);

  window.draw(scoreText);
  window.draw(scoreDivider);

}

