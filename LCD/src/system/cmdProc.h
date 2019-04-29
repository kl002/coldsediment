#ifndef __PROTOCOL_CMDPROC_H_
#define __PROTOCOL_CMDPROC_H_

#ifdef __cplusplus
extern "C"{
#endif

#include "../transport/Protocol/ProtocolAPI.h"


void RegistCmdProc();

extern void ExecCommands();
#ifdef __cplusplus
}
#endif

#endif /* __PROTOCOL_CMDPROC_H_ */
