/* Header file for Driver class 
class will contain function to read and trouble shoot all sensors i.e joystick, accelerometer*/

#ifndef driver_h
#define driver_h

#define BASE 100
#define SPI_CHAN 0


class Driver
{
private:
    

    
public:
    Driver(); 
    void printADChannel(int channel);
    void printJoystickStatus(void);
    int getJoystickLR(void);
    int getJoystickUD(void);
    
};








# endif