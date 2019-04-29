/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    filename.c

  @Summary
    Brief description of the file.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

/* ************************************************************************** */
/* ************************************************************************** */
/* Section: Included Files                                                    */
/* ************************************************************************** */
/* ************************************************************************** */
#include "../system/system.h"
#include "../include.h"
#include "Protocol/types.h"
#include "Protocol/Src/RingFifo.h"

static UINT8 TxBuff[255];
#ifdef __cplusplus
extern "C" {
#endif
BOOL GetChar(UINT8 *byte);
void PutChar(UINT8 txChar);
#ifdef __cplusplus
}
#endif

unsigned char Tx_data[128]={0x02,0x00,0x09,0x00,0x03,0x00,0x06,0x00};	//��λ�����ݰ�
unsigned char Rx_data[128];


u8 _RxFifoBuffer[1024];
TRingFifo RxFifo = 
    {_RxFifoBuffer, sizeof(u8), 1024, 0, 0};

u8 _TxFifoBuffer[1024];
TRingFifo TxFifo = 
    {_TxFifoBuffer, sizeof(u8), 1024, 0, 0};

void __ISR(_UART_x_VECTOR, IPL4AUTO) UxRXInterrupt(void)
{
    unsigned char ch = 0;

    while(!UxSTAbits.URXDA);

    ch = UxRXREG; //TODO 

    RingFifoIn(&RxFifo, &ch);

    IFS2bits.UxRXIF = 0;			//�жϱ�־����
}

s32 rx_hal_read(s32 dev_handle, u8 * buf, u32 size)
{
   s32 cnt = 0;
    
    while( (RingFifoOut( &RxFifo, buf+cnt ) == 1)  &&  (cnt < size) )
    {
       cnt++;
    }
    return cnt;
}

/* ע�ᵽHAL TX */
s32 tx_hal_write(s32 dev_handle, u8 * buf, u32 size)
{
   s32 cnt = 0;
    /* ��������ͻ����п�λ */
    while( (RingFifoIn(&TxFifo, buf+cnt) == 1) && (cnt<size)){
        cnt++;
    }
   
    return cnt;
}

void tx_hal_send_to_hardware()
{
    // ֻҪ����TX����BUSY, �������ݴ��� 
    char ch;
    while(( UxSTAbits.UTXBF == 0) && (RingFifoOut(&TxFifo,&ch) ))  //TODO
    {
        UxTXREG = ch;  //TODO 
    }
}

/********************************************************************
* Function: 	UartInit()
*
* Precondition: 
*
* Input: 		PB Clock
*
* Output:		None.
*
* Side Effects:	None.
*
* Overview:     Initializes UART.
*
*			
* Note:		 	None.
********************************************************************/	
void UartInit(UINT pbClk)
{
	#if   (((__PIC32_FEATURE_SET__ >= 100) && (__PIC32_FEATURE_SET__ <= 299)))
		#error("TODO: For PIC32MX1xx/PIC32MX2xx devices, user should map the UART ports to required pins using PPS");
		/* Example code
			PPSInput(2,U2RX, RPA9);  //Assign U2RX to pin RPA09
    		PPSOutput(4,RPC4,U2TX);   //Assign U2TX to pin RPC4	
    		//Do not forget to switch-off corrresponding "analog selection".
    		ANSELx = 0;	
		*/
	#endif
	// Open UART2 with Receive and Transmitter enable.
    UxBRG  = (pbClk/16/DEFAULT_BAUDRATE-1); // calculate actual BAUD generate value.
    UxMODE = UART_EN;
    UxSTA  = (UART_RX_ENABLE | UART_TX_ENABLE);
    IPC12bits.UxIP  = 4;			        //ָ����ѡ�ж�Դ�����ȼ�
    IEC2bits.UxRXIE = 1;			    //ʹ���ж�

    Protocol_Register(0, rx_hal_read, tx_hal_write);	//ע�ᴮ�ڣ�����д����
    RegistCmdProc();	
}	


/********************************************************************
* Function: 	UartClose()
*
* Precondition: 
*
* Input: 		None
*
* Output:		None.
*
* Side Effects:	None.
*
* Overview:     Closes UART connection.
*
*			
* Note:		 	None.
********************************************************************/	
void UartClose(void)
{
	//TODO: do some closing operation if required.	
}	


/********************************************************************
* Function: 	UartTasks()
*
* Precondition: 
*
* Input: 		None
*
* Output:		None
*
* Side Effects:	None.
*
* Overview:     Runs some UART routines like receive bytes and transmit bytes.
*
*			
* Note:		 	None.
********************************************************************/
void UartTask(void)
{
    tx_hal_send_to_hardware();	//����ͨѶģ��
    
    Protocol_RxAction();    
    
//     if ( T1_ARM >= 20 )
//    {
//        Protocol_Send(Tx_data, 32);	//��ʱ�ϴ�����
//        T1_ARM = 0;
//    }
}


/********************************************************************
* Function: 	GetChar()
*
* Precondition: 
*
* Input: 		None
*
* Output:		True: If there is some data.
*
* Side Effects:	None.
*
* Overview:     Gets the data from UART RX FIFO.
*
*			
* Note:		 	None.
********************************************************************/
BOOL GetChar(UINT8 *byte)
{
	BYTE dummy;

	if(UxSTA & 0x000E)              // receive errors?
	{
		dummy = UxRXREG; 			// dummy read to clear FERR/PERR
		UxSTAbits.OERR = 0;			// clear OERR to keep receiving
	}

	if(UxSTAbits.URXDA)
	{
		*byte = UxRXREG;		        // get data from UART RX FIFO
		return TRUE;
	}
	
	return FALSE;

}


/********************************************************************
* Function: 	PutChar()
*
* Precondition: 
*
* Input: 		None
*
* Output:		None
*
* Side Effects:	None.
*
* Overview:     Puts the data into UART tx reg for transmission.
*
*			
* Note:		 	None.
********************************************************************/
void PutChar(UINT8 txChar)
{
    while(UxSTAbits.UTXBF); // wait for TX buffer to be empty
    UxTXREG = txChar;
}


/***************************************End Of File*************************************/
