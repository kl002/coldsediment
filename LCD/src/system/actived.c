#include "actived.h"
#include "../include.h"

unsigned char isRegistered()
{
    unsigned char val = 0;    
//    val = readSEE( EE_FLAG_ACTIVED );
    
    return val;
}
unsigned char registerMachine(unsigned char *ch)
{
    unsigned char i = 0;
    unsigned char key[CIPHER_LEN]={};
    unsigned char cipher[CIPHER_LEN];
    
    if ( 0 == ch )
        return 0;

    strncpy( key, "1234", CIPHER_LEN );
   
    getAESCipherTxt( cipher, key );

    for ( i = 0; i < CIPHER_LEN; i++ ){
        if ( cipher[i] != ch[i] )
            return 0;
    }

//    writeSEE( EE_FLAG_ACTIVED, 1 );
    return 1;
}
