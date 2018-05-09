//The top of rmcu
#include "stm32f1xx_hal.h"

#include "top.h"
#include "beep.h"
#include "commu.h"


int AppInit(){
	TIM3_Init();
	
	return 0;
}


int AppMain(){
	
	
	IWDG->KR = 0xAAAA;
	return 0;
}


