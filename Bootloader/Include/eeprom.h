/* 
 * File:   eeprom.h
 * Author: slrom
 *
 * Created on December 28, 2016, 2:17 PM
 */

#ifndef EEPROM_H
#define	EEPROM_H

#ifdef	__cplusplus
extern "C" {
#endif

#define CS_NVRAM_TRIS 	TRISFbits.TRISF3
#define CS_NVRAM 		LATFbits.LATF3		//??NVRAM????RF3

//NVRAM commands
#define SEE_WRSR    1       // write status register	
#define SEE_WRITE   2       // write command
#define SEE_READ    3       // read command
#define SEE_WDI     4       // write disable
#define SEE_STAT    5       // read status register
#define SEE_WEN     6       // write enable

extern int writeSPI( int i);
extern void NVRAM_init( void);
extern int readStatus( void);
extern int readSEE( int address);
extern void writeEnable( void);
extern void writeSEE( int address, int data);


//upgrade flag address in EEProm
#define EE_FLAG_UPGRADE      0x0E48       //0x0E48 

#ifdef	__cplusplus
}
#endif

#endif	/* EEPROM_H */

