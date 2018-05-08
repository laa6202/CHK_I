//The top of rmcu
#include "stm32f1xx_hal.h"

#include "top.h"


int AppInit(){
	
	LED_GPIO_Port->ODR = LED_GPIO_Port->ODR | (LED_Pin);
	return 0;
}


int AppMain(){
	
	
	IWDG->KR = 0xAAAA;
	return 0;
}


