/* Header file for Driver class 
class will contain function to read and trouble shoot all sensors i.e joystick, accelerometer*/

#ifndef driver_h
#define driver_h

//for use with MCP3008 SPI
#define BASE 100
#define SPI_CHAN 0

//for use with Accelerometer (FXOS8700) I2C
#define FXOS8700CQ_SLAVE_ADDR 0x1f // found using i2cdetect -y 1 (from datasheet can be 1c,1d,1e or 1f)
#define FXOS8700CQ_CTRL_REG1 0x2A

//FXOS8700 registers from datasheet (data is a 14 bit word, 8 in msb and 6 in lsb - lsb has to be shifted >> 2)
#define OUT_x_MSB 0x01
#define OUT_x_LSB 0x02
#define OUT_Y_MSB 0x03
#define OUT_Y_LSB 0x04
#define OUT_Z_MSB 0x05
#define OUT_Z_LSB 0x06

//struct to hold acceleration values
struct accel {
    int x, y, z;
};

class Driver
{
private:
     
public:
    Driver(); 

    //variables
    int fd; // int variable for I2C set-up with fx0s8700cq

    //MCP3008 function to read an ADC channel
    void printADChannel(int channel);

    //joystick functions
    void printJoystickStatus(void);
    int getJoystickLR(void);
    int getJoystickUD(void);

    //accelerometer functions
    accel getAccelValues(void);
   
};

# endif