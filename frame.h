#ifndef _FRAME_H_
#define _FRAME_H_

#include "include.h"

void Cmd_Splice(u8 slaveAddr,u8 funCode,u16 regAddr,u16 dataValue);
void Cmd_RTUSend(CmdType cmdType);
void Slave_CmdSend(void);
u8 * Frame_PDUCut(void);
void mMBFuncReadHoldingRegister(u8 * mMBbuff);
void mMBFuncWriteHoldingRegister(u8 * mMBbuff);
#endif
