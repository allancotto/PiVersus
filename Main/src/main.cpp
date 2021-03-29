#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <mcp3004.h>
#include <wiringPiSPI.h>
#include <unistd.h>
#include "driver.h"

#include <stdio.h>
#include <wiringPiI2C.h>
#include <iostream>
#include <chrono>
#include <thread>

int main()
{
   
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

    }

    return 0;
}