//The commu of rmcu
//1-to low level mcu(STM32F407)
//2-to high level raspi
#include "stm32f1xx_hal.h"
#include "string.h"

#include "types.h"
#include "commu.h"

#define LEN_U1_BUF 32



int recU1Number;
U8 recU1Buf[LEN_U1_BUF];
int recU1Index;
U8 recI2C_RecData;
U8 recI2C_SendData;
U8 temp;
int recI2C_Number;
int irqI2C_Number;

int U1_Init(){
	recU1Number = 0;
	recU1Index = 0;
	memset(recU1Buf,0,LEN_U1_BUF*sizeof(U8));
	USART1->CR1 = USART1->CR1 | USART_CR1_RXNEIE;
	return 0;
}


int U1_IRQ(){
	if((USART1->SR & USART_SR_RXNE) == USART_SR_RXNE){
		U1RecData();
		USART1->SR = USART1->SR & (~USART_SR_RXNE);
	}
	return 0;
}


int U1RecData(){
	recU1Number ++;
	U8 recU1Data = USART1->DR;
	if((recU1Index == 0) && (recU1Data != 0x50))
		return -1;
	else if((recU1Index == 1) && (recU1Data != 0x54)){
		recU1Index = 0;
		return -1;
	}
	else{
		recU1Buf[recU1Index] = recU1Data;
		recU1Index++;
		if(recU1Index == LEN_U1_BUF)	recU1Index = 0;	
		return 0;
	}
}


int U1_IRQ_END(){
	USART1->CR1 = USART1->CR1 | USART_CR1_RXNEIE;
	return 0;
}


int I2C_Init(){
	temp = 0;
	recI2C_Number = 0;
	recI2C_RecData = 0;
	recI2C_SendData = 0;
	irqI2C_Number = 0;
	I2C1->CR2 = I2C1->CR2 | I2C_CR2_ITEVTEN;
	I2C1->CR1 = I2C1->CR1 | I2C_CR1_ACK | I2C_CR1_NOSTRETCH; 

	return 0;
}


int I2C_EVIRQ(){
	if((I2C1->SR1 & I2C_SR1_RXNE) == I2C_SR1_RXNE){
		recI2C_RecData = I2C1->DR;
		recI2C_SendData = recU1Buf[recI2C_RecData];
		recI2C_Number++;
	}
	I2C1->DR = recI2C_SendData;
	irqI2C_Number++;
	return 0;
}


int I2C_EVIRQ_End(){
	I2C1->CR2 = I2C1->CR2 | I2C_CR2_ITEVTEN;
	I2C1->CR1 = I2C1->CR1 | I2C_CR1_ACK;
	return 0;
}
