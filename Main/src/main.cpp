#include <iostream>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <string.h>
#include <wiringPi.h>
#include <mcp3004.h>
#include <wiringPiSPI.h>
#include <unistd.h>

#define BASE 100
#define SPI_CHAN 0

int main()
{
    int i;
    printf("WiringPiSPISetup RC=%d\n",wiringPiSPISetup(0,500000));
    mcp3004Setup(BASE,SPI_CHAN);
    
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

        for(i=0;i<8;i++){
            printf("Channel %d: value=%4d\n",i,analogRead(BASE+i));
            printf("\n");
            sleep(0.5);
        }
        sleep(2);

        
    }

    

    return 0;
}