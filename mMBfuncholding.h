#ifndef _MMBFUNCHOLDING_H_
#define _MMBFUNCHOLDING_H_

#include "include.h"
/**
 * д���ּĴ������������ò������ݱ��� 
 * regAddr ���ݱ�������*dataValue Ҫд�������ָ��
 **/
void Write_HoldingRegister(u16 regAddr,u8 * dataValuePtr);
void Read_HoldingRegister(u16 regAddr,u8 * dataValuePtr,u8 regNUM);

#endif
