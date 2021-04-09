// instructions class
#include "instructions.h"

Instructions::Instructions()
{

  font.loadFromFile("../Resources/Fonts/arial.ttf");

  background.loadFromFile("../Resources/Images/PiVersus_Logo.png");

  bgSprite.setTexture(background);
  bgSprite.setPosition(100.f, 40.f);

  for (int i = 0; i < NUMBER_OF_GAMES; i++){
    instructionText[i].setFont(font);
    switch (i)
    {
    case 0:
      instructionText[i].setString("Instructions for Game 1");
      break;
    case 1:
      instructionText[i].setString("Instructions for Game 2");
      break;
    case 2:
      instructionText[i].setString("Instructions for Game 3");
      break;
    default:
      break;
    }
    //instructionText[0].setString("Soda Prank");
    instructionText[i].setCharacterSize(36); // font size in pixels not points
    instructionText[i].setFillColor(sf::Color::White);
    instructionText[i].setStyle(sf::Text::Bold);
    instructionText[i].setPosition(50.f, 50.f); // position to upper left corner
  }

  menuState = 0;

  // for some reason defined value isn't currently working so defining here instead
  float menuButtonSizeX = 300.f, menuButtonSizeY = 200.f;

  outline.setSize(sf::Vector2f(menuButtonSizeX + 20.f, menuButtonSizeY + 20.f));
  outline.setOutlineThickness(3.f);
  outline.setOutlineColor(sf::Color(255, 255, 255));
  outline.setPosition(90.f, 410.f);

  startButton.setSize(sf::Vector2f(menuButtonSizeX, menuButtonSizeY));
  startButton.setFillColor(sf::Color(162, 44, 196));
  startButton.setPosition(490.f, 420.f);
}

void Instructions::draw(sf::RenderWindow &window, int State)
{

  window.draw(bgSprite);
  window.draw(outline);
  window.draw(startButton);

  switch (State)
  {
  case 0:
    window.draw(instructionText[State]);
    break;
  case 1:
    window.draw(instructionText[State]);
    break;
  case 2:
    window.draw(instructionText[State]);
    break;
  default:
    break;
  }

  window.draw(bgSprite);
}
