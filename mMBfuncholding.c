#include "mMBfuncholding.h"
#include "RegTable_RW.h"

void Write_HoldingRegister(u16 regAddr,u8 * dataValuePtr)
{
    if (regAddr <= REGTABLE_MAXSIZE)
    {
        Set_RegTable(regAddr,DATA_CHANGED,*dataValuePtr);
    }
    return;
}
void Read_HoldingRegister(u16 regAddr,u8 * dataValuePtr,u8 regNUM)
{
    u16 dataTemp;

    if (regAddr > REGTABLE_MAXSIZE)//���Ҫд��ĵ�ַ�������ݱ����Χ����������
    {
        return;
    }
    
    while (regNUM)
    {
        dataTemp = ((u16)*dataValuePtr)<<8|((u16)*(dataValuePtr+1));
        Set_RegTable(regAddr,DATA_CHANGED,dataTemp);
        dataValuePtr += 2;
        ++regAddr;
        --regNUM;
    }
    
}
