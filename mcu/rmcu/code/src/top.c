//The top of rmcu
#include "stm32f1xx_hal.h"

#include "top.h"
#include "beep.h"
#include "commu.h"



int AppInit(){
	TIM3_Init();
	U1_Init();
	U2_Init();
	I2C_Init();
	ADC_Init();
	return 0;
}


int AppMain(){
	
	
	IWDG->KR = 0xAAAA;
	return 0;
}


int U1_IRQ(){
	if((USART1->SR & USART_SR_RXNE) == USART_SR_RXNE){
		U1RecData();
		USART1->SR = USART1->SR & (~USART_SR_RXNE);
	}
	return 0;
}


int U1_IRQ_END(){
	USART1->CR1 = USART1->CR1 | USART_CR1_RXNEIE;
	return 0;
}


int U2_IRQ(){
	if((USART2->SR & USART_SR_TC) == USART_SR_TC){
		USART2->SR = USART2->SR & (~USART_SR_TC);
		U2_SendCon();
	}
	return 0;
}


int ADC_Init(void){
	ADC1->CR1 = ADC1->CR1 | ADC_CR1_JEOCIE;
	ADC1->CR2 = ADC1->CR2 | ADC_CR2_JEXTTRIG;
	ADC1->CR2 = ADC1->CR2 | ADC_CR2_ADON;
	TIM4->CR1 = TIM4->CR1 | TIM_CR1_CEN;
	return 0;
}


int ADC_IRQ(void){
	GetADCTemp();
	U2_Send();
	return 0;
}


int ADC_IRQ_End(void){
	ADC1->CR1 = ADC1->CR1 | ADC_CR1_JEOCIE;
	ADC1->CR2 = ADC1->CR2 | ADC_CR2_JEXTTRIG;
	ADC1->CR2 = ADC1->CR2 | ADC_CR2_ADON;
	return 0;
}

