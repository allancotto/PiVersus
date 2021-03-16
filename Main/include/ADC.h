/* 
Library for communication with MCP3008 ADC (adapted from github.com/nodesign/MCP3008)
which is ported originally from python code written by Adafruit
*/

#ifndef ADC_h
#define ADC_h

class ADC
{
    public:
        ADC(int clock, int mosi, int miso, int cs);     /* defines ADC pins */
        int readADC(int input_num) ; /*defines function to read specified pin from SPI*/

    private:
        int _clock, _mosi, _miso,_cs;
};


#endif