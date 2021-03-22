/*class setup for adc
#include "ADC.h"


bool ADC::begin(uint8_t spiModule, uint8_t cs) {

    this->cs = cs;
    this->spiModule = spiModule;

    if(this->spiModule == ADC_SPI_AUX)
    {
        uint16_t clockDivider = bcm2835_aux_spi_CalcClockDivider(100000);
        bcm2835_aux_spi_setClockDivider(clockDivider);
    }
    else if(this->spiModule == ADC_SPI_0)
    {
        if(this->cs != BCM2835_SPI_CS0 && this->cs != BCM2835_SPI_CS1)
        {
            printf("choose correct cs");
            return false;
        }
    

    bcm2835_spi_setBitOrder(BCM2835_SPI_BIT_ORDER_MSBFIRST);
    bcm2835_spi_setDataMode(BCM2835_SPI_MODE0);
    bcm2835_spi_setClockDivider(BCM2835_SPI_CLOCK_DIVIDER_4096);
    bcm2835_spi_chipSelect(this->cs);
    bcm2835_spi_setChipSelectPolarity(this->cs,LOW);
    }

    else {
    printf("choose spi_aux or spi 0\n");
    return false;
    }

    return true;
}


int ADC::readADC(uint8_t channel) {
    if((channel<0) || (channel>7)) return -1;
    return SPIxADC(channel,false);  
}

*/