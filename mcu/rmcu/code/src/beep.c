//The top of rmcu
#include "stm32f1xx_hal.h"

#include "types.h"
#include "beep.h"

int flag;

int TIM3_Init(){
	flag = 0;
	TIM3->DIER = TIM3->DIER | TIM_DIER_UIE;
	TIM3->CR1 = TIM3->CR1 | TIM_CR1_CEN;
	return 0;
}

//TIM3 IRQ is 4KHZ
int TIM3_IRQ(){
	flag ++;
	
	return 0;
}

