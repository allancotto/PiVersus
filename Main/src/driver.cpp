/* class for driver */

#include "driver.h"
#include "cstdio"
#include <wiringPi.h>
#include <mcp3004.h>
#include <wiringPiSPI.h>





Driver::Driver(){
    printf("WiringPiSPISetup RC=%d\n",wiringPiSPISetup(0,500000));
    mcp3004Setup(BASE,SPI_CHAN);

}

void Driver::printADChannel(int channel) {
    printf("Channel %d: value=%4d\n",channel,analogRead(BASE+channel));
}

void Driver::printJoystickStatus() {
    /*Joystick connected to channels 0 and 1 of the ADC (L/R to 0 and U/P to 1)*/
    int horizontal = analogRead(BASE+0);
    int vertical = analogRead(BASE+1);
    printf("The horizontal value is %d and the vertical value is %d",horizontal, vertical);

}

int Driver::getJoystickLR() {
    /* Return Joystick LR value, 1 = right, 0 = centre, -1 = left */
    int horizontal = analogRead(BASE+0);

    if(horizontal>100 && horizontal<1000) {
        return 0;
    } else if (horizontal < 100) {
        return -1;
    } else {
        return 1;
    }

}

int Driver::getJoystickUD() {
    /* Return joystick UD (up/down) value, 1 = up, 0 = centre, -1 = down */
    int verticle = analogRead(BASE+1);

    if(verticle>100 && verticle<1000) {
        return 0;
    } else if (verticle < 100) {
        return -1;
    } else {
        return 1;
    }

}

