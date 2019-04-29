#include "mcu_adc.h"

unsigned int round_voltage = 0;

void mcu_adc_init()
{
    AD1PCFGbits.PCFG11 = 0;
    AD1CON1bits.SSRC = 0b111; // Internal counter ends sampling and starts conversion (auto convert)
    AD1CON3bits.ADRC = 0b0; // 0 = Clock derived from Peripheral Bus Clock (PBCLK)
    AD1CON3bits.SAMC = 0b11111; // 31 TAD ACQUIRE
    AD1CON3bits.ADCS = 39 ; // SAMPLE CLK = 1/10 PBCLK IS 1MHZ
    AD1CSSL = 0x800 ; // AN11  SCAN
    AD1CON2bits.CSCNA = 1 ; //SCAN MODE
    AD1CON2bits.VCFG = 0 ; // AVDD GND AS REF
    AD1CON2bits.BUFM =0 ;  // Single 16-word result buffer 
    AD1CON2bits.SMPI =1 ; // 2 BUFFER
    AD1CON2bits.ALTS = 0 ; // MUX A USE
    AD1CHSbits.CH0NA = 0; // NEG INPUT IS GND
    AD1CON1SET = 0x8000; // START AD
    AD1CON1bits.ASAM = 1; //START SAMPLE ;
}

void adc_value_update()
{
    if( AD1CON1bits.DONE == 0 )  // 采集没有完成，判断是否采集超时，如果超时，进行报错
    {
        return ;        
    }
    else 
    {
        round_voltage = ( ADC1BUF0 + ADC1BUF1 ) / 2 ;
        round_voltage = round_voltage / FACTOR ;
        AD1CON1bits.DONE = 0;
    }
        
}

