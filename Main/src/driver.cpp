/* class for driver */

#include "driver.h"
#include "cstdio"
#include <wiringPi.h>
#include <mcp3004.h>
#include <wiringPiSPI.h>
#include <string>





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
    
    if(horizontal < 100) {

    } else if (horizontal > 100 && horizontal <1000)
    {
        
    } else {

    }
    

}
