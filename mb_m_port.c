#include "mb_m_port.h"

/*************************************************
 * baud 波特率设置，parity 校验位设置。
 * *********************************************/
void usartInit(u32 baud,u8 parity);

/**
 * usartstate 串口中断状态设置
 * **/
void usartSetState(usartState usartstate);
/**
 * ch，用于保存从串口获得的字符的指针
 * **/
void usartGetChar(u8* ch);

/**
 * ch，用于串口发送字符的值
 * **/
void usartSetChar(u8 ch);

/**
 * baud 波特率设置
 * **/
void timerInit(u32 baud);

void timerEnable(void);

void timerDisable(void);

void TIMx_IRQHandler(void);

void USARTx_IRQHandler(void);
