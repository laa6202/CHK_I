#include "stm32f4xx_hal.h"

#include "commu.h"
#include "types.h"

uint8_t u3SendBuf[100];
uint8_t u3RevBuf[100];
uint8_t u2SendBuf[100];
uint8_t u2RevBuf[100];
uint8_t u1SendBuf[100];
uint8_t u1RevBuf[100];
int u1SendBytes;
int u3SendBytes;


int Commu_Init(){
	USART3->CR1 = USART3->CR1 | USART_CR1_TCIE;
	USART1->CR1 = USART1->CR1 | USART_CR1_TCIE;
	u1SendBytes = 0;
	u3SendBytes = 0;
	CTRL1_GPIO_Port->ODR = CTRL1_GPIO_Port->ODR | CTRL1_Pin;
	return 0;
}


int U1_IRQ(){
	if((USART1->SR & USART_SR_TC_Msk) == USART_SR_TC_Msk){
		USART1->SR = USART1->SR & (~USART_SR_TC_Msk);
		if(u1SendBytes >0){
			USART1->DR = 0x50 - u1SendBytes;
			u1SendBytes --;
		}
	}	
	
	return 0;
}


int U2_IRQ(){
	
	
	return 0;
}


int U3_IRQ(){
	if((USART3->SR & USART_SR_TC_Msk) == USART_SR_TC_Msk){
		USART3->SR = USART3->SR & (~USART_SR_TC_Msk);
		if(u3SendBytes >0){
			USART3->DR = 0x50 - u3SendBytes;
			u3SendBytes --;
		}
	}
	return 0;
}



int U1SendTest(void){
	if(u1SendBytes == 0){
		u1SendBytes = 0x20;
		USART1->DR = 0x50 - u1SendBytes;
		u1SendBytes--;
	}
	return 0;
}


int U3SendTest(void){
	if(u3SendBytes == 0){
		u3SendBytes = 0x20;
		USART3->DR = 0x50 - u3SendBytes;
		u3SendBytes--;
	}
	return 0;
}


int U1Send(TPKG pkg){
	

	return 0;
}


int U3Send(U8 data){
	USART3->DR  = data;
	return 0;
}

