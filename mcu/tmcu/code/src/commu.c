#include "stm32f4xx_hal.h"

#include "commu.h"
#include "types.h"
#include "string.h"


uint8_t u2SendBuf[100];
uint8_t u2RevBuf[100];
uint8_t u1SendBuf[100];
uint8_t u1RevBuf[100];
int u1SendBytes;



int Commu_Init(){
//	USART3->CR1 = USART3->CR1 | USART_CR1_TCIE;
	USART1->CR1 = USART1->CR1 | USART_CR1_TCIE;
	USART2->CR1 = USART2->CR1 | USART_CR1_RXNEIE;
	u1SendBytes = 0;
	CTRL1_GPIO_Port->ODR = CTRL1_GPIO_Port->ODR | CTRL1_Pin;
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


int U2_IRQ(){
	
	
	return 0;
}


int U3_IRQ(){
	if((USART3->SR & USART_SR_TC_Msk) == USART_SR_TC_Msk){
		USART3->SR = USART3->SR & (~USART_SR_TC_Msk);
	}
	return 0;
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

