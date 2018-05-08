//The top of rmcu
#include "stm32f1xx_hal.h"

#include "top.h"


int AppInit(){
	
//	GPIOC->ODR = GPIOC->ODR & (~GPIO_PIN_13);
	return 0;
}


int AppMain(){
	
	
	IWDG->KR = 0xAAAA;
	return 0;
}


