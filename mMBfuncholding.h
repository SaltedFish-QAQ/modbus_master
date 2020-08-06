#ifndef _MMBFUNCHOLDING_H_
#define _MMBFUNCHOLDING_H_

#include "include.h"
/**
 * 写保持寄存器函数，调用操作数据表函数 
 * regAddr 数据表索引，*dataValue 要写入的数据指针
 **/
void Write_HoldingRegister(u16 regAddr,u8 * dataValuePtr);
void Read_HoldingRegister(u16 regAddr,u8 * dataValuePtr,u8 regNUM);

#endif
