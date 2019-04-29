#ifndef _INCLUDE_sys_API_H_
#define _INCLUDE_sys_API_H_


#include "Src/Protocol.h"
#include "alarms.h"
#include "commands.h"
#include "status.h"

#ifdef __cplusplus
#include "qglobal.h"
extern "C"{
#endif

void Protocol_Register(s32 dev_handle, pfProtocolHal ptr_rx_hal, pfProtocolHal ptr_tx_hal);
void Protocol_RxAction();
void Protocol_RegistCmdProc(u8 cmdId, pfCmdCallback ptr_func);//ע��������Ӧ����(������Ӧ��������ͬ������)
s32 Protocol_Send(const u8 * buf, u8 len);//���Ͳ���ҪӦ�������

u8  Protocol_GetFrame(u8 * buf, u8 len);//��ȡ����ҪӦ�������(�첽)
s32 Protocol_Send_Secure(const u8 * buf, u8 len, s32 timeout);//������ҪӦ�������

#ifdef __cplusplus
}
#endif

#endif
