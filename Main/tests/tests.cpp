#define CONFIG_CATCH_MAIN

#include "catch.hpp"
#include "driver.h"
#include "threadManager.h"
#include "menu.h"
#include "instructions.h"
#include "gameScreen.h"

//driver tests
TEST_CASE("Testing pushbutton output") {//testing pushbutton 
    Driver d = Driver();
    REQUIRE(d.getPushButton() == 0);
}

TEST_CASE("Testing joystick output") {//testing UD
    Driver d = Driver();
    REQUIRE(d.getJoystickUD() == 0);
}

TEST_CASE("Testing joystick output") {//testing LR 
    Driver d = Driver();
    REQUIRE(d.getJoystickLR() == 0);
}

//ThreadManager tests

TEST_CASE("Testing thred control booleans output") {//ensure joystick thread boolean alive on start-up
    Menu m;
    Driver d;
    Instructions i;
    GameScreen g;
    ThreadManager t(&m, &d, &i, &g);
    
    REQUIRE(t.joystickThreadAlive == true);
}

TEST_CASE("Testing thred control booleans output") {//ensure pushbutton thread alive on start-up
    Menu m;
    Driver d;
    Instructions i;
    GameScreen g;
    ThreadManager t(&m, &d, &i, &g);
    
    REQUIRE(t.pushButtonThreadAlive == true);
}

TEST_CASE("Testing thred control booleans output") {//ensure accelerometer thread false on start up
    Menu m;
    Driver d;
    Instructions i;
    GameScreen g;
    ThreadManager t(&m, &d, &i, &g);
    
    REQUIRE(t.accelerometerThreadAlive == false);
}

TEST_CASE("Testing thred control booleans output") {//ensure gameTimeThread false on start up
    Menu m;
    Driver d;
    Instructions i;
    GameScreen g;
    ThreadManager t(&m, &d, &i, &g);
    
    REQUIRE(t.gameTimeThreadAlive == false);
}

TEST_CASE("Testing thred control booleans output") {//ensure game running false on start up
    Menu m;
    Driver d;
    Instructions i;
    GameScreen g;
    ThreadManager t(&m, &d, &i, &g);
    
    REQUIRE(t.gameRunning == false);
}

TEST_CASE("Testing instruction selection") {//state 1 should lead to 4 with the function
    Menu m;
    Driver d;
    Instructions i;
    GameScreen g;
    ThreadManager t(&m, &d, &i, &g);
    
    t.state = 1;
    i.instructionState = 0; //game will be played
    t.instructionSelection(); //function called

    REQUIRE(t.state == 4);


}

TEST_CASE("Testing instruction selection") {//state 2 should lead to 5 with the function
    Menu m;
    Driver d;
    Instructions i;
    GameScreen g;
    ThreadManager t(&m, &d, &i, &g);
    
    t.state = 2;
    i.instructionState = 0; //game will be played
    t.instructionSelection(); //function called

    REQUIRE(t.state == 5);


}

TEST_CASE("Testing instruction selection") {//state 3 should lead to 4 with the function
    Menu m;
    Driver d;
    Instructions i;
    GameScreen g;
    ThreadManager t(&m, &d, &i, &g);
    
    t.state = 3;
    i.instructionState = 0; //game will be played
    t.instructionSelection(); //function called

    REQUIRE(t.state == 6);


}

TEST_CASE("Testing instruction selection") {
    Menu m;
    Driver d;
    Instructions i;
    GameScreen g;
    ThreadManager t(&m, &d, &i, &g);
    
    t.state = 1;
    i.instructionState = 1; //game will be played
    t.instructionSelection(); //function called

    REQUIRE(t.state == 0);


}

TEST_CASE("Testing setFalse function makes booleans false") {
    Menu m;
    Driver d;
    Instructions i;
    GameScreen g;
    ThreadManager t(&m, &d, &i, &g);
    
    t.setAllFalse();
    REQUIRE(t.pushButtonThreadAlive == false);
    REQUIRE(t.joystickThreadAlive == false);
    REQUIRE(t.accelerometerThreadAlive == false);
    REQUIRE(t.gameTimeThreadAlive == false);

}

TEST_CASE("ensure start game function setups variables correctly") {
    Driver d;
    Instructions i;
    GameScreen g;
    ThreadManager t(&m, &d, &i, &g);
    
    t.gameRunning = false;
    REQUIRE(t.pushButtonThreadAlive == false);
    REQUIRE(t.joystickThreadAlive == false);
    REQUIRE(t.accelerometerThreadAlive == true);
    REQUIRE(t.gameTimeThreadAlive == true);
    REQUIRE(t.gameRunning == true);

}

TEST_CASE("test game screen function for the difference in accel values works") {
    GameScreen g;

    int return_value = g.accelReadingDifference(5,5);
    REQUIRE(return_value == 0);
}

TEST_CASE("test game screen function for the difference in accel values works") {
    GameScreen g;

    int return_value = g.accelReadingDifference(5,-5);
    REQUIRE(return_value == 10);
}

TEST_CASE("test game screen function for the difference in accel values works") {
    GameScreen g;

    int return_value = g.accelReadingDifference(-5,-5);
    REQUIRE(return_value == 0);
}

TEST_CASE("test countdown function") { // should decrement by 1
    GameScreen g;

    int time = g.gameDuration;
    g.countdownTime();
    REQUIRE(g.gameDuration == time-1);

}

TEST_CASE("test countdown function") { // if zero should no longer decrement
    GameScreen g;

    g.gameDuration = 0;
    g.countdownTime();
    REQUIRE(g.gameDuration == 0);

}