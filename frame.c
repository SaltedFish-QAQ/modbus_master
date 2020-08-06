#include "frame.h"

#define MB_BUFFER_MAXSIZE   200

static CmdType cmdType;
static CmdType cmdTypeLast;
static volatile u8 mb_buff[MB_BUFFER_MAXSIZE];
static volatile u8 mMBBuffPos;

void Cmd_Splice(u8 slaveAddr,u8 funCode,u16 regAddr,u16 dataValue)
{
    cmdType.sendFlag = 1;//暂时使用flag进行是否发送命令的判断，后续改用设置事件函数来进行操作
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

//此处原实现方式为预先发送一个字节以触发发送中断，在发送中断服务中开始逐个发送报文
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
        /* 根据不同的从机地址可进行其他处理 */
    }
    
    buff = &mb_buff[1];//将自功能?之后的数据首地址返回
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
    regNUM = cmdTypeLast.dataValue;//在03功能?中，数据位保存信息位要读取的寄存器个数
    dataValuePtr = mMBbuff + 2;
    Read_HoldingRegister(regAddr,dataValuePtr,regNUM);

}

void mMBFuncWriteHoldingRegister(u8 * mMBbuff)
{

}
