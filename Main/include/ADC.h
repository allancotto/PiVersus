/* 
Library for communication with MCP3008 ADC 
based of github.com/marcod234 - integrated mcp3008 and bcm2835
*/

#ifndef ADC_h
#define ADC_h

#include <bcm2835.h>
#include <stdio.h>
#include <stdlib.h>

#define ADC_SPI_0 0
#define ADC_SPI_AUX 1  //SPI1

class ADC {
    public:
        bool begin(uint8_t spiModule=ADC_SPI_AUX, uint8_t cs=0);
        int readADC(uint8_t channel);
        int readADCDifference(uint8_t differential);
    private:
        uint8_t spiModule;
        uint8_t cs;
        int SPIxADC(uint8_t channel,bool differential);
};


#endif