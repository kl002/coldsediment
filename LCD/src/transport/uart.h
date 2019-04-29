/* ************************************************************************** */
/** Descriptive File Name

  @Company
    Company Name

  @File Name
    uart.h

  @Summary
    ����PICƽ̨����ͨ�Ź���.

  @Description
    Describe the purpose of this file.
 */
/* ************************************************************************** */

#ifndef __UART_H    /* Guard against multiple inclusion */
#define __UART_H

#define DEFAULT_BAUDRATE 			115200

#define Ux(y)           U3##y
#define _UART_x(y)      _UART_3##y

#define UxBRG           Ux(BRG)
#define UxMODE          Ux(MODE)
#define UxSTA           Ux(STA)
#define UxSTAbits       Ux(STAbits)
#define UxSTACLR        Ux(STACLR)
#define UxSTASET        Ux(STASET)
#define UxTXREG         Ux(TXREG)
#define UxRXREG         Ux(RXREG)
#define UxRXIE          Ux(RXIE)
#define UxRXIF          Ux(RXIF)
#define UxIP            Ux(IP)
#define UxIS            Ux(IS)
#define UxRXInterrupt   Ux(RXInterrupt)

#define _UART_x_VECTOR  _UART_x(_VECTOR)


#define TRANS_LAYER_Init UartInit
#define TRANS_LAYER_Task UartTask
#define TRANS_LAYER_Close UartClose

#ifdef __cplusplus
extern "C" {
#endif
extern void TRANS_LAYER_Init(UINT);
extern void TRANS_LAYER_Task(void);
extern void TRANS_LAYER_Close(void);
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
