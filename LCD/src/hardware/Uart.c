#include "Uart.h"
#include "system.h"

void UART2_init()
{
	U2BRG = BAUDRATEREG2;		//设置波特率9600
    U2MODE = 0 ; // 8 N 1 bit mode
    U2STAbits.UTXISEL = 0b11 ;
    U2STAbits.URXISEL = 0b00 ; // RX interrupt mode
    IPC8bits.U2IP = 1 ;
    IEC1bits.U2RXIE = 1 ;
    U2STAbits.URXEN = 1;
    U2STAbits.UTXEN = 1;
    U2MODEbits.ON = 1;    
}

void UART6_init()
{
	U6BRG = BAUDRATEREG6;		//设置波特率9600
    U6MODE = 0 ; // 8 N 1 bit mode
    U6STAbits.UTXISEL = 0b11 ;
    U6STAbits.URXISEL = 0b00 ; // RX interrupt mode
    IPC12bits.U6IP = 1 ;
    IEC2bits.U6RXIE = 1 ;
    U6STAbits.URXEN = 1;
    U6STAbits.UTXEN = 1;
    U6MODEbits.ON = 1;    
}

void __ISR(_UART_2_VECTOR, IPL1AUTO) U2RXInterrupt(void)
{
    static int i=0;
    while(U2STAbits.URXDA)
    {
        Scan1[i] = U2RXREG; //TODO 
        if(Scan1[i] == 10)  //检测换行符号
        {
            i=0;
            flag_gotBarcode1 = 1;
            break;
        }
        i++;
    }

    IFS1bits.U2RXIF =  0;	
}

void __ISR(_UART_6_VECTOR, IPL1AUTO) U6RXInterrupt(void)
{
    static int i=0;
    while(U6STAbits.URXDA)
    {
        Scan2[i] = U6RXREG; //TODO 
        if(Scan2[i] == 10)   //检测换行符号
        {
            i=0;
            flag_gotBarcode2 = 1;
            break;
        }
        i++;
    }
    IFS2bits.U6RXIF = 0;	
}

