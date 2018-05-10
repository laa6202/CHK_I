//The top of STM32F030 project

#include "stm32f0xx_hal.h"

#include "top.h"

int TickBegin;
int TickEnd;
int Tick;
int temp;

int AppInit(){
	SysTick->LOAD =0xffffff;
	
	return 0;
}


int AppMain(){
	
	BeginTick();
	Delay5ms();
	EndTick();
	
	
	IWDG->KR = 0xAAAA;
	return 0;
}

int BeginTick(){
	TickBegin = SysTick->VAL;
	return 0;	
}


int EndTick(){
	TickEnd = SysTick->VAL;
	Tick = TickBegin - TickEnd;
	return 0;
}


int Delay5ms(){
	for(int i=0;i<5;i++)
		Delay1ms();
	return 0;
}


int Delay1ms(){
	for(int i=8000;i>=5;i--)
		temp++;
	return 0;
}
