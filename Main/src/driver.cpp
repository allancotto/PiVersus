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
