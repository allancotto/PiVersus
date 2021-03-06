//game screen draw class
#include "gameScreen.h"
#include "iostream"
#include <string>
#include <sstream>
#include "driver.h"





GameScreen::GameScreen(){
  font.loadFromFile("../Resources/Fonts/arial.ttf");

  background.loadFromFile("../Resources/Images/PiVersus_Logo.png");
  statuePng.loadFromFile("../Resources/Images/SG_LOGO.png");
  sodaPng.loadFromFile("../Resources/Images/SP_LOGO.png");

  bgSprite.setTexture(background);
  bgSprite.setPosition(50.f, 20.f);

  titleSprite.setTexture(statuePng);
  titleSprite.setScale(0.4,0.4);
  titleSprite.setPosition(350.f, 25.f);



  previousReadings.x = 1;
  previousReadings.y =  0;
  previousReadings.z = 0;

  scoreText.setFont(font);
  scoreText.setString("0");
  scoreText.setCharacterSize(72); 
  scoreText.setFillColor(sf::Color::White);
  scoreText.setStyle(sf::Text::Bold);
  scoreText.setPosition(570.f, 425.f); 


  timeText.setFont(font);
  timeText.setString("00");
  timeText.setCharacterSize(72);
  timeText.setFillColor(sf::Color::White);
  timeText.setStyle(sf::Text::Bold);
  timeText.setPosition(595.f, 95.f); 

  readingsText.setFont(font);
  readingsText.setString("x: 00  y:00  z:00");
  readingsText.setCharacterSize(30);
  readingsText.setFillColor(sf::Color::White);
  readingsText.setStyle(sf::Text::Bold);
  readingsText.setPosition(525.f, 625.f); 


  timeBackground.setSize(sf::Vector2f(150.f, 150.f));
  timeBackground.setOutlineThickness(3.f);
  timeBackground.setFillColor(sf::Color(162, 44, 196));
  timeBackground.setOutlineColor(sf::Color(255,255,255));
  timeBackground.setPosition(565.f, 90.f);


  scoreBackground.setSize(sf::Vector2f(200.f, 150.f));
  scoreBackground.setOutlineThickness(3.f);
  scoreBackground.setFillColor(sf::Color(162, 44, 196));
  scoreBackground.setOutlineColor(sf::Color(255,255,255));
  scoreBackground.setPosition(540.f, 420.f);

  readingsBackground.setSize(sf::Vector2f(300.f, 60.f));
  readingsBackground.setOutlineThickness(3.f);
  readingsBackground.setFillColor(sf::Color(162, 44, 196));
  readingsBackground.setOutlineColor(sf::Color(255,255,255));
  readingsBackground.setPosition(490.f, 620.f);



}


void GameScreen::updateReadings(int x, int y, int z) {

  scoreUpdate(x, y, z);
  std::ostringstream oss;
  oss << "x: " << x << "  y: " << y << "  z: " << z;
  
  readingsText.setString(oss.str());
}

void GameScreen::countdownTime(){

  if(gameDuration>0) {
    gameDuration--;
  } else {
    timeEnded = true;
  }
  
  std::ostringstream oss;
  oss << gameDuration;

  timeText.setString(oss.str());
  
}

void GameScreen::scoreUpdate(int x, int y, int z) {
  accel currentReadings;

  currentReadings.x = x;
  currentReadings.y = y;
  currentReadings.z = z;

  switch (gameSelected)
  {
  case 0:
    updateScore1(currentReadings);
    break;
  
  case 1:
    updateScore2(currentReadings);
    break;
  }
}


void GameScreen::draw(sf::RenderWindow &window, int state) {
  
  gameSelected = state;

  if(gameSelected == 0) {
    titleSprite.setTexture(sodaPng);
  } else {
    titleSprite.setTexture(statuePng);
  }
  

  window.draw(bgSprite);
  window.draw(timeBackground);
  window.draw(scoreBackground);
  window.draw(readingsBackground);
  

  window.draw(scoreText);
  window.draw(timeText);
  window.draw(readingsText);
  window.draw(titleSprite);


}

void GameScreen::updateScore1(accel currentReadings) {

  accel difference = scoreDifference(currentReadings);
  currentScore = currentScore + difference.y/2;

  std::ostringstream oss;
  oss << currentScore;
  scoreText.setString(oss.str());

}

void GameScreen::updateScore2(accel currentReadings) {

  accel difference = scoreDifference(currentReadings);

  int differenceAdded = difference.x + difference.y + difference.z +1;

  if(differenceAdded<5) {
    currentScore = currentScore + (5/differenceAdded);
  }
  

  std::ostringstream oss;
  oss << currentScore;
  scoreText.setString(oss.str());



}


accel GameScreen::scoreDifference(accel currentReadings) {

  accel returnValue;

  
  //case negative value
  returnValue.x = accelReadingDifference(currentReadings.x, previousReadings.x);
  returnValue.y = accelReadingDifference(currentReadings.y, previousReadings.y);
  returnValue.z = accelReadingDifference(currentReadings.z, previousReadings.z);

  previousReadings = currentReadings;

  return returnValue;

}

int GameScreen::accelReadingDifference(int current, int previous) {

  if(current<0) {  

    if(previous<0) {
      return abs(abs(current)-abs(previous)); 

    } else {
      return abs(current) + previous;

    }


  } else {

    if(previous<0) {
      return abs(previous) + current;
    } else {
      return abs(current-previous);
    }
  }

  return 0;
}