//The top of STM32F030 project

#include "stm32f0xx_hal.h"

#include "top.h"
#include "commu.h"
#include "led.h"
#include "base.h"
#include "action.h"

int T;

int AppInit(){
	T = 0x550;
	SysTick->LOAD =0xffffff;
	U1_Init();
	LedInit();
	T1_Init();

	return 0;
}


int AppMain2(){
	
	BeginTick();
	U1_Send();
	for(int i=0;i<200;i++)
		Delay5ms();
	Led1Glint();
	EndTick();
	
	
	IWDG->KR = 0xAAAA;
	return 0;
}



int AppMain(){

	T = T1_GetTemp();
	PushBuf(T);
	U1_Send();
	Delay1s();
	IWDG->KR = 0xAAAA;
	return 0;
}
