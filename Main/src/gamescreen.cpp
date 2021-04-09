//game screen draw class
#include "gamescreen.h"

GameScreen::GameScreen(){
  font.loadFromFile("../Resources/Fonts/arial.ttf");

  background.loadFromFile("../Resources/Images/PiVersus_Logo.png");

  bgSprite.setTexture(background);
  bgSprite.setPosition(100.f, 40.f);

  for (int i = 0; i < NUMBER_OF_PLAYERS; i++)
  {
    scoreText[i].setFont(font);
    switch (i)
    {
    case 0:
      scoreText[i].setString("0");
      break;
    case 1:
      scoreText[i].setString("0");
      break;
    default:
      break;
    }
    //scoreText[0].setString("Soda Prank");
    scoreText[i].setCharacterSize(36); // font size in pixels not points
    scoreText[i].setFillColor(sf::Color::White);
    scoreText[i].setStyle(sf::Text::Bold);
    scoreText[i].setPosition(i * 540.0f + 270.f, 360.f); // position to upper left corner
  }

  scoreDivider.setFont(font);
  scoreDivider.setString("-");
  scoreDivider.setCharacterSize(36);
  scoreDivider.setFillColor(sf::Color::White);
  scoreDivider.setStyle(sf::Text::Bold);
  scoreDivider.setPosition(540.f, 360.f); // position to upper left corner
}