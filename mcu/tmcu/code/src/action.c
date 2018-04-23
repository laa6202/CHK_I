#include "action.h"
#include "stm32f4xx_hal.h"


static int index;

int App_Init(){
	index=0;
	LED_PB9_GPIO_Port->ODR = (LED_PB9_GPIO_Port->ODR & (~LED_PB9_Pin));	
	App_TIM7_Init();
	return 0;
}

int App_Action(){
	
//	IWDG->KR = 0xAAAA;
	return 0;
}

int App_TIM7_IRQ(){
	index++;
	return 0;
}


int App_TIM7_Init(){
	TIM7->PSC = 41;		//main clock = 84MHz
	TIM7->ARR = 125;	//for 16KHz int
	TIM7->DIER = (TIM7->DIER | TIM_DIER_UIE);
	TIM7->CR1 = (TIM7->CR1 | TIM_CR1_CEN);
	return 0;
}



