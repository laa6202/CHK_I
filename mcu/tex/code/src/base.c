
#include "stm32f0xx_hal.h"

#include "base.h"


int TickBegin;
int TickEnd;
int Tick;
int temp;

int BeginTick(){
	TickBegin = SysTick->VAL;
	return 0;	
}


int EndTick(){
	TickEnd = SysTick->VAL;
	Tick = TickBegin - TickEnd;
	return 0;
}


int Delay1ms(){
	for(int i=8000;i>=5;i--)
		temp++;
	return 0;
}


int Delay5ms(){
	for(int i=0;i<5;i++)
		Delay1ms();
	return 0;
}



int Delay10us(){
	for(int i=0;i<66;i++)
		temp++;
	return 0;
}


int Delay1us(){
	for(int i=0;i<6;i++)
		temp++;
	return 0;
}

int DelayN10us(int n){
	for(int i=0;i<n;i++){
		Delay10us();
	}
	return 0;
}


int Delay1s(){
	for(int i=0;i<200;i++)
		Delay5ms();
	return 0;
}
