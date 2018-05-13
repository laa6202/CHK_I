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
int sendU2Index;
U8 recI2C_RecData;
U8 recI2C_SendData;



float temp_1,temp_2,temp_3,temp_4;
uint16_t t1;


int U1_Init(){
	recU1Number = 0;
	recU1Index = 0;

	memset(recU1Buf,0,LEN_U1_BUF*sizeof(U8));
	USART1->CR1 = USART1->CR1 | USART_CR1_RXNEIE;
	return 0;
}

int U2_Init(){
	sendU2Index = 0;
	USART2->CR1 = USART2->CR1 | USART_CR1_TCIE;
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
		if((recU1Index != 16) && (recU1Index != 17))	//16/17 is tem of F103
			recU1Buf[recU1Index] = recU1Data;	
		recU1Index++;
		if(recU1Index == LEN_U1_BUF)	recU1Index = 0;	
		return 0;
	}
}





int I2C_Init(){
	recI2C_RecData = 0;
	recI2C_SendData = 0;
	I2C1->CR2 = I2C1->CR2 | I2C_CR2_ITEVTEN;
	I2C1->CR1 = I2C1->CR1 | I2C_CR1_ACK | I2C_CR1_NOSTRETCH; 

	return 0;
}


int I2C_EVIRQ(){
	if((I2C1->SR1 & I2C_SR1_RXNE) == I2C_SR1_RXNE){
		recI2C_RecData = I2C1->DR;
		recI2C_SendData = recU1Buf[recI2C_RecData];
	}
	I2C1->DR = recI2C_SendData;
	return 0;
}


int I2C_EVIRQ_End(){
	I2C1->CR2 = I2C1->CR2 | I2C_CR2_ITEVTEN;
	I2C1->CR1 = I2C1->CR1 | I2C_CR1_ACK;
	return 0;
}


int GetADCTemp(){
	//temp = (V25 - Vsen ) / Avg_slope + 25;
//V25 = 1.34;	Avg_slope = 0.0043;
	temp_1 = ADC1->JDR1 / 4096.0f;
	temp_2 = (temp_1) * 3.3f;
	temp_3 = 1.34 - temp_2 ;
	temp_4 = temp_3 / 0.0043f;
	t1 = (U16)((temp_4 + 25)*16);
	recU1Buf[16] = t1 & 0xff;
	recU1Buf[17] = (t1 & 0xffff) >> 8;
	return 0;
}


int U2_Send(){
	USART2->DR = recU1Buf[0];
	sendU2Index = 1;
	return 0;
}

int U2_SendCon(){
	if(sendU2Index < LEN_U1_BUF){
		USART2->DR = recU1Buf[sendU2Index];
		sendU2Index++;
	}
	return 0;
}
