
#include "stm32f0xx_hal.h"

#include "base.h"
#include "types.h"
#include "action.h"
#include "led.h"


U8 D5_Check;
U8 TL,TH;
U16 T_last; 
U16 T_now;
int t;

int D5OutH(){
	D5_GPIO_Port->MODER = D5_GPIO_Port->MODER | (0x01 << 10);
	D5_GPIO_Port->ODR = D5_GPIO_Port->ODR | D5_Pin;
	return 0;
}


int D5OutL(){
	D5_GPIO_Port->MODER = D5_GPIO_Port->MODER | (0x01 << 10);
	D5_GPIO_Port->ODR = D5_GPIO_Port->ODR & (~D5_Pin);	
	return 0;
}


int D5In(){
	D5_GPIO_Port->MODER = D5_GPIO_Port->MODER & (~(0x3<<10));
	return 0;
}


int D5Check(){
	D5_Check = D5_GPIO_Port->IDR;
	if((D5_Check & D5_Pin) == D5_Pin)
		return 1;
	else
		return 0;
}	



int D5ReadBit(){
	//60us
	D5OutL();
	Delay1us();
	D5In();
	Delay10us();
	int D5_Data = D5_GPIO_Port->IDR;
	DelayN10us(5);
	if((D5_Data & D5_Pin) == D5_Pin)
		return 1;
	else
		return 0;
}	
	

int D5WriteBit(int bit){
	//60-120us
	D5OutL();
	Delay10us();
	if(bit == 0)
		DelayN10us(8);		
	else{
		D5In();
		DelayN10us(8);		
	}
	D5In();
	DelayN10us(4);
	return 0;
}


int D5ReadByte(){
	int j;
	int q = 0;
	for(int i=0;i<8;i++){
		j = D5ReadBit();
		j=j<<7;
		q = (q>>1) | j;
	}
	return q;
}


int D5WriteByte(int byte){
	int d;
	int j = byte;
	for(int i=0;i<8;i++){
		d = (j & 0x1);
		j = (j >> 1);
		D5WriteBit(d);
	}
	return 0;
}


int T1_Reset(){
	D5OutL();
	DelayN10us(75);	//480-960us
	D5In();
	DelayN10us(4);	//15-60us
	int ret = D5Check();
	DelayN10us(10);	//60-240us
	return ret;
}


int T1_Init(){
	TL = 0;
	TH = 0;
	T_last = 0x1B0;
	T_now = 0x1B0;
	T1_Reset();
	return 0;
}


int T1_GetTemp(){

	Led2Glint();
	T1_Reset();
	D5WriteByte(0xCC);
	D5WriteByte(0x44);
	Delay1s();
	Delay1s();
	T1_Reset();
	D5WriteByte(0xCC);
	D5WriteByte(0xBE);
	TL = D5ReadByte();
	TH = D5ReadByte();
	if((TH & 0xff) == 0xff) 
		T_now = T_last;
	else {
		T_now = (TH << 8 | TL);
		T_last = T_now;
	}
	Led2Glint();
	return T_now;
}
//发现有时间会出现温度显示FFFF


