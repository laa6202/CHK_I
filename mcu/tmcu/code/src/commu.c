#include "stm32f4xx_hal.h"

#include "commu.h"
#include "types.h"
#include "string.h"

#define LEN_U2_BUF 10

uint8_t u2RecBuf[LEN_U2_BUF];
int 		u2RecIndex;
int 		u2RecNumber;
uint8_t u1SendBuf[100];
uint8_t u1RecBuf[100];
int u1SendBytes;



int Commu_Init(){
//	USART3->CR1 = USART3->CR1 | USART_CR1_TCIE;
	USART1->CR1 = USART1->CR1 | USART_CR1_TCIE;
	USART2->CR1 = USART2->CR1 | USART_CR1_RXNEIE;
	u1SendBytes = 0;
	CTRL1_GPIO_Port->ODR = CTRL1_GPIO_Port->ODR | CTRL1_Pin;
	u2RecIndex = 0;
	u2RecNumber = 0;
	memset(u2RecBuf,0,LEN_U2_BUF*sizeof(uint8_t));
	return 0;
}


int U1_IRQ(){
	if((USART1->SR & USART_SR_TC_Msk) == USART_SR_TC_Msk){
		USART1->SR = USART1->SR & (~USART_SR_TC_Msk);
		if(u1SendBytes < sizeof(TPKG)){
			USART1->DR = u1SendBuf[u1SendBytes];
			u1SendBytes++;
		}
	}	
	return 0;
}

int U1_IRQ_END(){
	USART1->CR1 = USART1->CR1 | USART_CR1_TCIE;
	return 0;
}





int U2RecData(pTPKG pkg){
	u2RecNumber++;
	uint8_t u2RecData = USART2->DR;
	if((u2RecIndex == 0) &&(u2RecData != 0x54)){
		u2RecIndex = 0;
		return -1;
	}
	else if((u2RecIndex == 1) &&(u2RecData != 0x31)){
		u2RecIndex = 0;
		return -1;
	}
	else {
		u2RecBuf[u2RecIndex] = u2RecData;
		u2RecIndex++;
		if(u2RecIndex == 4)	{
			u2RecIndex = 0;
			pkg->t_1 = u2RecBuf[2] << 8 | u2RecBuf[3];
		}
		return 0;
	}
}


U8 GetU2RecBuf(int index){
	uint8_t q;
	q = u2RecBuf[index];
	return q;
}



int U1Send(TPKG pkg){
	memcpy(u1SendBuf,&pkg,sizeof(TPKG));
	USART1->DR = u1SendBuf[0];
	u1SendBytes = 1;
	return 0;
}


int U3Send(U8 data){
	USART3->DR  = data;
	return 0;
}

