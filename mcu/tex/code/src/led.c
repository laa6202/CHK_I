
#include "stm32f0xx_hal.h"

#include "led.h"

int stLed1;
int stLed2;

int LedInit(){
	stLed1 = 0;
	stLed2 = 1;
	LED1_GPIO_Port->ODR = LED1_GPIO_Port->ODR | (LED1_Pin);
	LED2_GPIO_Port->ODR = LED2_GPIO_Port->ODR | (LED2_Pin);
	return 0;
}


int Led1Glint(){
	if(stLed1 == 0){
		stLed1 = 1; 
		LED1_GPIO_Port->ODR = LED1_GPIO_Port->ODR & (~LED1_Pin);
	}
	else {
		stLed1 = 0;
		LED1_GPIO_Port->ODR = LED1_GPIO_Port->ODR | (LED1_Pin);
	}
	return 0;
}


int Led2Glint(){
	if(stLed2 == 0){
		stLed2 = 1; 
		LED2_GPIO_Port->ODR = LED2_GPIO_Port->ODR & (~LED2_Pin);
	}
	else {
		stLed2 = 0;
		LED2_GPIO_Port->ODR = LED2_GPIO_Port->ODR | (LED2_Pin);
	}
	return 0;
}

