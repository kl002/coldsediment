#include <p32xxxx.h>
#include <plib.h>
#include "../system/system.h"
#include "../include.h"

unsigned pointer_plasma_bag = 0,	pointer_SAGM_bag = 0,	pointer_main_bag = 0;

void UART5_init()
{
	U5BRG = BAUDRATEREG5;			//���ò�����
	U5MODE = 0x8000;				//UART5ʹ��
	U5STA = 0x1400;					//���ա�����ʹ��

    IPC12bits.U5IP = 1;             //ָ����ѡ�ж�Դ�����ȼ�
//	IPC12 |= 0x04000000;			//ָ����ѡ�ж�Դ�����ȼ�
	IEC2bits.U5RXIE = 1;			//ʹ���ж�

}

void U5_PutByte ( unsigned char byte )		//U5���͵��ֽ�
{
	while( U5STAbits.UTXBF) ;
	U5TXREG = byte;  
} 

void U5_PutWord(unsigned short word)		//����˫�ֽ�
{
	unsigned char H8 = 0,L8 = 0;
	H8 = word>>8;
	while(U5STAbits.UTXBF);	//�ȴ����ͻ�����δ��
	U5TXREG = H8;
	L8 = word;
	while(U5STAbits.UTXBF);	//�ȴ����ͻ�����δ��
	U5TXREG = L8;
}

void U5_PutDWord(unsigned Dword)		//����4�ֽ�
{
	unsigned short H16 = 0,L16 = 0;
	H16 = Dword>>16;
	U5_PutWord(H16);
	L16 = Dword;
	U5_PutWord(L16);
}

void LCD_show_BG(unsigned short index)	//��ʾ����ͼ
{
	U5_PutWord( LCD_START );
    U5_PutByte( 4 ); // ���ݳ���
    U5_PutByte( LCD_W_REG ); // 
    U5_PutByte( LCD_REG_BG );
	U5_PutWord( index );
}

void LCD_Update_Num_Var(unsigned short addr, unsigned short value)	//���±���
{
	U5_PutWord( LCD_START );
    U5_PutByte( 5 ); // ���ݳ���
    U5_PutByte( LCD_W_VAR_ROM ); // 
    U5_PutWord( addr );
	U5_PutWord( value );
}

void LCD_Update_LNum_Var(unsigned short addr, const char* s, unsigned char len)	//���±���
{
    UINT8 i;
	U5_PutWord( LCD_START );
    U5_PutByte( len + 3 ); // ���ݳ���
    U5_PutByte( LCD_W_VAR_ROM ); // 
    U5_PutWord( addr );
    for ( i = 0; i < len; i++ ){
        U5_PutByte( *(s + i) );
    }
}

void LCD_Update_Str_Var(unsigned short addr, const char* s)	//���±���
{
    UINT8 i, len = strlen(s);
	U5_PutWord( LCD_START );
    U5_PutByte( len + 3 ); // ���ݳ���
    U5_PutByte( LCD_W_VAR_ROM ); // 
    U5_PutWord( addr );
    
    for ( i = 0; i < len; i++ ){
        U5_PutByte( *(s + i) );
    }
}

void LCD_show_Icon(unsigned short addr, unsigned short index)
{
    LCD_Update_Num_Var(addr, index);
}

void LCD_Read_Var(unsigned short addr, unsigned char len)
{
    // A5 5A LEN Cmd Addr��2�� DataLen   һ��7byte
    if ( len > TOUCH_BUF_LEN - 7 )
        return;
    
    U5_PutWord( LCD_START );
    U5_PutByte( 4 ); // ���ݳ���
    U5_PutByte( LCD_R_VAR_ROM ); // 
    U5_PutWord( addr );
	U5_PutByte( len );
}

void LCD_Get_DateTime()
{
    U5_PutWord( LCD_START );
    U5_PutByte( 3 ); // ���ݳ���
    U5_PutByte( LCD_R_REG ); // 
    U5_PutByte( 0x20 );
	U5_PutByte( 7 );
}

void LCD_Bee(unsigned short t10mS)
{
    U5_PutWord( LCD_START );
    U5_PutByte( 3 ); // ���ݳ���
    U5_PutByte( LCD_W_REG ); // 
    U5_PutByte( 0x02 );
	U5_PutByte( t10mS );
}