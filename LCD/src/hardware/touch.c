#include <p32xxxx.h>
#include <plib.h>
#include "../system/system.h"
#include "../include.h"

unsigned short flag_touch = 0;		//=1���м����£�=2�����ּ��������룻=3��ȡʱ��
signed short value_keyboard = 0;	//��������λ�ñ��
unsigned short gKeyValue = 0xFFFF;
signed short value_number = 1000;
unsigned char receive_touch[TOUCH_BUF_LEN];
unsigned short gTouchData[TOUCH_BUF_LEN];
unsigned char gTouchData_Bytes[TOUCH_BUF_LEN];

BOOL bRegisterVar = FALSE;

void __ISR(_UART_5_VECTOR, IPL1AUTO) U5RXInterrupt(void)
{
    unsigned short j,i = 0;
    unsigned unit_bytes = 1;
//    while(1 == U5STAbits.URXDA){
    for( i = 0; i <= TOUCH_LEN_INDEX; i++ ){
        while(!U5STAbits.URXDA);
        
        if ( flag_touch == TS_NULL ){
            receive_touch[i] = U5RXREG;
        }
        else{
            unsigned char x = U5RXREG;
        }
    }

    
    //���ݳ���Ҫ��ȥ��ͷ��len ��3byte
    for( j = 0; j < receive_touch[TOUCH_LEN_INDEX]; j++ ){
        while(!U5STAbits.URXDA);
        
        if ( flag_touch == TS_NULL ){
            receive_touch[i+j] = U5RXREG;
        }
        else{
            unsigned char x = U5RXREG;
        }
    }
    
    flag_touch = TS_NORM;
	IFS2bits.U5RXIF = 0;			//�жϱ�־����
}

static unsigned char parseTouchData(unsigned short* addr)
{
    int len, i, index = 0;
    unsigned short state = _sWaitHead;
    BOOL isHighByte = TRUE;
    
    unsigned short tmpVal = 0;
    for ( i = 0; i < TOUCH_BUF_LEN;i++ ){
        switch ( state )
        {
            case _sWaitHead:
                if ( isHighByte ){
                    tmpVal = receive_touch[i];
                    isHighByte = FALSE;
                }
                else{
                    isHighByte = TRUE;
                    tmpVal = (tmpVal<<8)|receive_touch[i];
                    
                    if ( TR_Head == tmpVal ){
                        state = _sWaitLen;
                    }
                    else{
                        return 0;
                    }
                }
                break;
             case _sWaitLen:                 
                 state = _sWaitCmd;
                break;               
            case _sWaitCmd:
                 if ( TR_Rgst_Cmd == receive_touch[i] ){
                     bRegisterVar = TRUE;
                 } 
                 state = _sWaitAddr;                
                break;
            case _sWaitAddr:
                if ( isHighByte ){
                    tmpVal = receive_touch[i];
                    isHighByte = FALSE;
                    
                    //  �Ĵ���������ַ ֻ��1byte
                    if ( bRegisterVar ){
                        isHighByte = TRUE;
                        *addr = tmpVal;
                         state = _sWaitDataLen;
                    }
                }
                else{
                    isHighByte = TRUE;
                    tmpVal = (tmpVal<<8)|receive_touch[i];
                    
                    *addr = tmpVal;
                    state = _sWaitDataLen;
                }
                break;
            case _sWaitDataLen:
                len = receive_touch[i];
                state = _sWaitData1;
                break;
            case _sWaitData1:
                if( bRegisterVar ){
                   memcpy( gTouchData_Bytes, &receive_touch[i], len ); 
                   return len;
                }
                else{
                    if ( isHighByte ){
                        tmpVal = receive_touch[i];
                        isHighByte = FALSE;
                    }
                    else{
                        isHighByte = TRUE;
                        tmpVal = (tmpVal<<8)|receive_touch[i];

                        gTouchData[index] = tmpVal;

                        index++;
                        if ( index >= len )
                            return len;
                    }
                }
                break;
            default:
                return 0;
        }
    }
}

void touch_events()
{
    unsigned short addr, len;
    BOOL bGotData = FALSE;
    bRegisterVar  = FALSE;
    gKeyValue = KEY_NONE;
    
    if (  TS_NORM == flag_touch ){
        len = parseTouchData( &addr );
        
        bGotData = ( len > 0 ) ? TRUE : FALSE;
    }

    if ( bGotData ){
        if ( !bRegisterVar ){
           onTouchCmd( addr, len );
        }
        else{
            if ( TOUCH_DATETIME_R_ADDR == addr ){
            }
        }
        
        memset( receive_touch, 0, TOUCH_BUF_LEN );
    }
    
    if ( 1 == U5STAbits.OERR ){
        U5STAbits.OERR = 0;
    }
    
    flag_touch = TS_NULL;   	
}


