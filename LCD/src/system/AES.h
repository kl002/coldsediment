/* 
 * File:   aes.h
 * Author: slrom
 *
 * Created on November 29, 2016, 4:51 PM
 */

#ifndef AES_H
#define AES_H

#ifdef   __cplusplus
extern "C" {
#endif
    
void getAESCipherTxt( unsigned char *cipher, unsigned char *txt );

//////��ʱ��Ӧ���ⲿʹ��
void aes_encrypt(unsigned char *state, unsigned char *key);


#ifdef	__cplusplus
}
#endif

#endif /* AES_H */