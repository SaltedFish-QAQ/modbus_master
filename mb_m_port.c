#include "mb_m_port.h"

/*************************************************
 * baud ���������ã�parity У��λ���á�
 * *********************************************/
void usartInit(u32 baud,u8 parity);

/**
 * usartstate �����ж�״̬����
 * **/
void usartSetState(usartState usartstate);
/**
 * ch�����ڱ���Ӵ��ڻ�õ��ַ���ָ��
 * **/
void usartGetChar(u8* ch);

/**
 * ch�����ڴ��ڷ����ַ���ֵ
 * **/
void usartSetChar(u8 ch);

/**
 * baud ����������
 * **/
void timerInit(u32 baud);

void timerEnable(void);

void timerDisable(void);

void TIMx_IRQHandler(void);

void USARTx_IRQHandler(void);
