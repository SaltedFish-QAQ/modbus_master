#include "frame.h"

#define MB_BUFFER_MAXSIZE   200

static CmdType cmdType;
static CmdType cmdTypeLast;
static volatile u8 mb_buff[MB_BUFFER_MAXSIZE];
static volatile u8 mMBBuffPos;

void Cmd_Splice(u8 slaveAddr,u8 funCode,u16 regAddr,u16 dataValue)
{
    cmdType.sendFlag = 1;//��ʱʹ��flag�����Ƿ���������жϣ��������������¼����������в���
    cmdType.slaveAddr = slaveAddr;
    cmdType.funCode =funCode;
    cmdType.regAddr = regAddr;
    cmdType.dataValue = dataValue;
}

void Cmd_RTUSend(CmdType cmdType)
{
    u16 buffCRC16;

    cmdType.sendFlag = 0;

    cmdTypeLast.slaveAddr = cmdType.slaveAddr;
    cmdTypeLast.funCode = cmdType.funCode;
    cmdTypeLast.regAddr = cmdType.regAddr;
    cmdTypeLast.dataValue = cmdType.dataValue;

    mb_buff[0] = cmdType.slaveAddr;
    mb_buff[1] = cmdType.funCode;
    mb_buff[2] = (u8)(cmdType.regAddr>>8);
    mb_buff[3] = (u8)cmdType.slaveAddr;
    mb_buff[4] = (u8)(cmdType.slaveAddr>>8);
    mb_buff[5] = (u8)cmdType.slaveAddr;

    buffCRC16 = usMBCRC16((const u8*)mb_buff,6);
    mb_buff[6] = (u8)buffCRC16;
    mb_buff[7] = (u8)(buffCRC16>>8);

//�˴�ԭʵ�ַ�ʽΪԤ�ȷ���һ���ֽ��Դ��������жϣ��ڷ����жϷ����п�ʼ������ͱ���
    usartSetState(usart_tx);
    for (u8 i = 0; i <= 7; i++)
    {
        usartSetChar(mb_buff[i]);
    }
    
}

void Slave_CmdSend(void)
{
    if (cmdType.sendFlag == 0)
    {
        return ;
    }
    
    Cmd_RTUSend(cmdType);
}

u8* Frame_PDUCut(void)
{
    u8 * buff;
    if (mb_buff[0] == 1)
    {
        /* ���ݲ�ͬ�Ĵӻ���ַ�ɽ����������� */
    }
    
    buff = &mb_buff[1];//���Թ���?֮��������׵�ַ����
    return buff;
}

void mMBFuncReadHoldingRegister(u8 * mMBbuff)
{
    u8   regNUM;
    u8   regAddr;
    u8 * dataValuePtr;

    if(mMBbuff[1] != (cmdTypeLast.dataValue*2))
    {
        return;
    }

    regAddr = cmdTypeLast.regAddr;
    regNUM = cmdTypeLast.dataValue;//��03����?�У�����λ������ϢλҪ��ȡ�ļĴ�������
    dataValuePtr = mMBbuff + 2;
    Read_HoldingRegister(regAddr,dataValuePtr,regNUM);

}

void mMBFuncWriteHoldingRegister(u8 * mMBbuff)
{

}
