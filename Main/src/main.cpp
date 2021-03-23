#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <mcp3004.h>
#include <wiringPiSPI.h>
#include <unistd.h>
#include "driver.h"



int main()
{
   
   /* driver test code */
    Driver driver;
    



    std::cout << "Hello Easy C++ project!" << std::endl;
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();

    
        driver.printJoystickStatus();
        printf("\n");
        sleep(2);
    
        
    }

    

    return 0;
}