
#include "stm32f0xx_hal.h"

#include "commu.h"
#include "types.h"
#include "string.h"

#define LEN_BUF 32

U8 SendBuf[LEN_BUF];
int lenSend;
int indexSend;


int U1_Init(){
	USART1->CR1 = USART1->CR1 | USART_CR1_TCIE;
	memset(SendBuf,0,LEN_BUF*sizeof(U8));
	lenSend = 0;
	indexSend = 0;
	SendBuf[0] = 0x54;
	SendBuf[1] = 0x31;
//	TP1();
	return 0;
}


int U1_IRQ(){
	if((USART1->ISR & USART_ISR_TC_Msk) == USART_ISR_TC_Msk){
		if(indexSend <lenSend){
			USART1->TDR = SendBuf[indexSend];
			indexSend++;
		}
		USART1->ICR = USART1->ICR | USART_ICR_TCCF;
	}
	return 0;
}


int U1_Send(){
	indexSend = 0;
	USART1->TDR = SendBuf[indexSend];
	indexSend++;
	return 0;
}


int TP1(void){
	lenSend = 6;
	for(int i=0;i<LEN_BUF;i++)
		SendBuf[i] = 0x30+i;
	return 0;
}


int PushBuf(int t){
	U8 byte = (t & 0xffff)>>8;
	SendBuf[2] = byte;
	byte = t & 0xff;
	SendBuf[3] = byte;
	lenSend = 4;
	return 0;
}

