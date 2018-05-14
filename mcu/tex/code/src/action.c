
#include "stm32f0xx_hal.h"

#include "base.h"
#include "types.h"
#include "action.h"
#include "led.h"


U8 D7_Check;
U8 TL,TH;
int t;

int D7OutH(){
	D7_GPIO_Port->MODER = D7_GPIO_Port->MODER | (0x01 << 14);
	D7_GPIO_Port->ODR = D7_GPIO_Port->ODR | D7_Pin;
	return 0;
}


int D7OutL(){
	D7_GPIO_Port->MODER = D7_GPIO_Port->MODER | (0x01 << 14);
	D7_GPIO_Port->ODR = D7_GPIO_Port->ODR & (~D7_Pin);	
	return 0;
}


int D7In(){
	D7_GPIO_Port->MODER = D7_GPIO_Port->MODER & (~(0x3<<14));
	return 0;
}


int D7Check(){
	D7_Check = D7_GPIO_Port->IDR;
	if((D7_Check & D7_Pin) == D7_Pin)
		return 1;
	else
		return 0;
}	



int D7ReadBit(){
	//60us
	D7OutL();
	Delay1us();
	D7In();
	Delay10us();
	int D7_Data = D7_GPIO_Port->IDR;
	DelayN10us(5);
	if((D7_Data & D7_Pin) == D7_Pin)
		return 1;
	else
		return 0;
}	
	

int D7WriteBit(int bit){
	//60-120us
	D7OutL();
	Delay10us();
	if(bit == 0)
		DelayN10us(8);		
	else{
		D7In();
		DelayN10us(8);		
	}
	D7In();
	DelayN10us(4);
	return 0;
}


int D7ReadByte(){
	int j;
	int q = 0;
	for(int i=0;i<8;i++){
		j = D7ReadBit();
		j=j<<7;
		q = (q>>1) | j;
	}
	return q;
}


int D7WriteByte(int byte){
	int d;
	int j = byte;
	for(int i=0;i<8;i++){
		d = (j & 0x1);
		j = (j >> 1);
		D7WriteBit(d);
	}
	return 0;
}


int T1_Reset(){
	D7OutL();
	DelayN10us(75);	//480-960us
	D7In();
	DelayN10us(4);	//15-60us
	int ret = D7Check();
	DelayN10us(10);	//60-240us
	return ret;
}


int T1_Init(){
	TL = 0;
	TH = 0;
	T1_Reset();
	return 0;
}


int T1_GetTemp(){
	Led2Glint();
	T1_Reset();
	D7WriteByte(0xCC);
	D7WriteByte(0x44);
	Delay1s();
	Delay1s();
	T1_Reset();
	D7WriteByte(0xCC);
	D7WriteByte(0xBE);
	TL = D7ReadByte();
	TH = D7ReadByte();
	int T = (TH << 8 | TL);
	Led2Glint();
	return T;
}
