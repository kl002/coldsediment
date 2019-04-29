#include "../system/system.h"
#include "../include.h"

static BOOL bGotCmd = FALSE;

#define   TEST_VALUE    0xAA55
#define   TEST_CMD_LEN  3 

void UART6_init()
{
	U6BRG = BAUDRATEREG6;		//���ò�����9600
	U6MODE = 0x8000;				//UART6ʹ��
	U6STA = 0x1400;				//���ա�����ʹ��
}

static unsigned char recv_cmdBuf[TEST_CMD_LEN];
static unsigned char index = 0;
char U6_events()
{
    while(U6STAbits.URXDA == 1)
    {
        recv_cmdBuf[index++] = U6RXREG;
 
        if ( TEST_CMD_LEN <= index )
        {
            index = 0;
            if ( '3'== recv_cmdBuf[0]&&
                 '2'== recv_cmdBuf[1]&&
                 '3'== recv_cmdBuf[2])
            {
                bGotCmd = TRUE;
                T1_test = 0;
            }
        }
        
        Nop();
    }        
}


void U6_putbyte ( unsigned char byte )		//U6���͵��ֽ�
{
	while( U6STAbits.UTXBF) ;
        U6TXREG = byte;  
} 

#define  TESTBUF_LEN      13
static unsigned char sTestRsltBuf[TESTBUF_LEN] = {0};
static unsigned char bEEPRomOK = 0;

static void sendTestRslt()
{
    int i = 0, j;
    sTestRsltBuf[i++] = 0x55;
    sTestRsltBuf[i++] = bEEPRomOK;
    sTestRsltBuf[i++] = plate_off;
    sTestRsltBuf[i++] = plate_on;
    sTestRsltBuf[i++] = plate_reset;
    sTestRsltBuf[i++] = rotate_RM;
    sTestRsltBuf[i++] = manual_SAGM;
    sTestRsltBuf[i++] = data_scales1;
    sTestRsltBuf[i++] = data_scalesP;
    sTestRsltBuf[i++] = value_scales2;
    sTestRsltBuf[i++] = value_LPM;
    sTestRsltBuf[i++] = value_line;
    sTestRsltBuf[i++] = 0xAA;
    
    for (j = 0; j < i; j++){
        U6_putbyte( sTestRsltBuf[j] );
    }
}

void TestMode_events()
{
//    static unsigned sendCnt = 0;
//    int tmp = 0;
//    
//    if ( FALSE == bGotCmd )
//        return;
//    
//    if ( T1_test < 5 )
//    {
//        writeSEE( EE_TEST_POS, TEST_VALUE );
//    }
//    else if ( T1_test < 15 ){
//        tmp = readSEE( EE_TEST_POS );
//        
//        bEEPRomOK = (tmp == TEST_VALUE);
//    }
//    else{
//        sendTestRslt();
//        sendCnt++;
//        
//        if ( sendCnt >= 5 ){
//            sendCnt = 0;
//            bGotCmd = FALSE;   
//        }
//    }
}