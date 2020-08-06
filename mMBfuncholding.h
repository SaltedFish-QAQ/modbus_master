#ifndef _MMBFUNCHOLDING_H_
#define _MMBFUNCHOLDING_H_

#include "include.h"

void Write_HoldingRegister(u16 regAddr,u8 * dataValue);
void Read_HoldingRegister(u16 regAddr,u8 * dataValue,u8 regNUM);

#endif
