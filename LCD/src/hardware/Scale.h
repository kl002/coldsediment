//电子秤模块端口
#include <xc.h>
#define ADSK1_TRIS	TRISEbits.TRISE5	
#define ADSK1		LATEbits.LATE5

#define ADDO1_TRIS	TRISEbits.TRISE6	
#define ADDO1		PORTEbits.RE6	

#define ADSK2_TRIS	TRISCbits.TRISC1
#define ADSK2		LATCbits.LATC1

#define ADDO2_TRIS	TRISCbits.TRISC2
#define ADDO2		PORTCbits.RC2	
void Scale_init();
void Scale1_init();
void Scale2_init();
void delay_5us (int i);
int Read_Scale1();
int Read_Scale2();