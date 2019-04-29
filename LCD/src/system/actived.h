/* 
 * File:   actived.h
 * Author: slrom
 *
 * Created on December 5, 2016, 11:50 AM
 */

#ifndef ACTIVED_MY_H
#define	ACTIVED_MY_H

#ifdef	__cplusplus
extern "C" {
#endif

#define      CIPHER_LEN    (16)
   
unsigned char in_cipher[CIPHER_LEN];
    
extern unsigned char isRegistered();
extern unsigned char registerMachine( unsigned char *ch );


#ifdef	__cplusplus
}
#endif

#endif	/* ACTIVED_MY_H */

