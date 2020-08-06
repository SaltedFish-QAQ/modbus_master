#ifndef _INCLUDE_H_
#define _INCLUDE_H_
//include 文件，模块内要使用的通用宏定义，变量等
#include <stdint.h>

typedef uint8_t u8;
typedef uint16_t u16;
typedef uint32_t u32;
typedef int8_t s8;
typedef int16_t s16;
typedef int32_t s32;

typedef volatile uint8_t vu8;

typedef enum
{
    usart_tx = 0,
    usart_rx = 1,
    usart_silent = 3,
}usartState;

typedef struct
{
    u8  sendFlag;
    u8  slaveAddr;
    u8  funCode;
    u16 regAddr;
    u16 dataValue;
}CmdType;

typedef void (*mb_mFunctionHandler) (u8* mb_PDUBuff);

typedef struct 
{
    u8                    ModbusFunCode;
    mb_mFunctionHandler   mMBFunctionHandler;
};


#include "mbcrc.h"
#include "mb_m_port.h"
#include "mMBfuncholding.h"

#endif
