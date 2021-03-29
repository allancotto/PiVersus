/* class for driver */

#include "driver.h"
#include "cstdio"
#include <iostream>
#include <wiringPi.h>
#include <mcp3004.h>
#include <wiringPiSPI.h>
#include <wiringPiI2C.h>

Driver::Driver(){
    
    // set-up SPI on driver initialization
    printf("WiringPiSPISetup (MCP3008) RC=%d\n",wiringPiSPISetup(0,500000));
    mcp3004Setup(BASE,SPI_CHAN);


    // Setup I2C communication with FXOS8700Q
    this->fd = wiringPiI2CSetup(FXOS8700CQ_SLAVE_ADDR);
    if (fd == -1) {
        std::cout << "Failed to init I2C communication.\n";
    }
    std::cout << "I2C communication successfully setup.\n";
    // Switch device to measurement mode
    wiringPiI2CWriteReg8(fd, FXOS8700CQ_CTRL_REG1, 0000000001);

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
    } else if (horizontal < 150) {
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
    } else if (verticle < 150) {
        return -1;
    } else {
        return 1;
    }
}

accel Driver::getAccelValues() {

    int dataXmsb = wiringPiI2CReadReg8(this->fd, OUT_x_MSB);
    int dataXlsb = wiringPiI2CReadReg8(this->fd, OUT_x_LSB);
    dataXmsb = (int16_t)(dataXmsb <<8 | dataXlsb >> 2); //as 14 bit word shift lsb to the right by 2

    int dataYmsb = wiringPiI2CReadReg16(this->fd, OUT_Y_MSB);
    int dataYlsb = wiringPiI2CReadReg16(this->fd, OUT_Y_LSB);
    dataYmsb = (int16_t)(dataYmsb <<8 | dataYlsb >> 2);

    int dataZmsb = wiringPiI2CReadReg16(this->fd, OUT_Z_MSB);
    int dataZlsb = wiringPiI2CReadReg16(this->fd, OUT_Z_LSB);
    dataZmsb = (int16_t)(dataZmsb <<8 | dataZlsb >> 2);

    accel values;
    values.x = dataXmsb;
    values.y = dataYmsb;
    values.z = dataZmsb;

    return values;
}

