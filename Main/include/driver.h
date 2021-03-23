/* Header file for Driver class 
class will contain function to read from all ADC inputs i.e joystick, accelerometer*/

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
    
};








# endif