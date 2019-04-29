#include <p32xxxx.h>
#include <plib.h>
#include "Include\eeprom.h"

// send one byte of data and receive one back at the same time
int writeSPI( int i)
{
    SPI3BUF = i;                  // write to buffer for TX
    while( !SPI3STATbits.SPIRBF); // wait for transfer complete
    
    return SPI3BUF;               // read the received value
}//writeSPI

void NVRAM_init( void)
{
    // init the SPI peripheral 
    CS_NVRAM_TRIS = 0;      // make SSEE pin output
    CS_NVRAM = 1;           // de-select the Serial EEPROM

    SPI3CON = 0x8120;       // enable the peripheral
    SPI3BRG = 15;         	// select clock speed (2.5MHz)
}// initNVRAM

int readStatus( void)
{
    // Check the Serial NVRAM status register
    int i;	
    CS_NVRAM = 0;           // select the Serial NVRAM
    writeSPI( SEE_STAT);   // send a READ STATUS COMMAND
    i = writeSPI( 0);      // send/receive
    CS_NVRAM = 1;           // deselect terminate command
    return i;
} // readStatus

int readSEE( int address)
{ // read a 32-bit value starting at an even address
    int i;
    // wait until any work in progress is completed
    while ( readStatus() & 0x1);// check WIP
    // perform a 16-bit read sequence (two byte sequential read)
    CS_NVRAM = 0;                   // select the Serial EEPROM
    writeSPI( SEE_READ);       // read command
    writeSPI( address >>8);    // address MSB first
    writeSPI( address & 0xfc); // address LSB (word aligned)
    i = writeSPI( 0);          // send dummy, read msb
    i = (i<<8)+ writeSPI( 0);  // send dummy, read lsb
    i = (i<<8)+ writeSPI( 0);  // send dummy, read lsb
    i = (i<<8)+ writeSPI( 0);  // send dummy, read lsb
    CS_NVRAM = 1;
    return ( i);
}// readSEE

void writeEnable( void)
{
    // send a Write Enable command
    CS_NVRAM = 0;          // select the Serial NVRAM
    writeSPI( SEE_WEN);    // write enable command
    CS_NVRAM = 1;          // deselect to complete the command
}// writeEnable   

void writeSEE( int address, int data)
{ // write a 32-bit value starting at an even address
    // wait until any work in progress is completed
    while ( readStatus() & 0x1);// check the WIP flag
    // Set the Write Enable Latch
    writeEnable();
    // perform a 32-bit write sequence (4 byte page write)
    CS_NVRAM = 0;                   // select the Serial EEPROM
    writeSPI( SEE_WRITE);      // write command
    writeSPI( address>>8);     // address MSB first
    writeSPI( address & 0xfc); // address LSB (word aligned)
    writeSPI( data >>24);      // send msb
    writeSPI( data >>16);      // send msb
    writeSPI( data >>8);       // send msb
    writeSPI( data);           // send lsb
    CS_NVRAM = 1;
}// writeSEE

