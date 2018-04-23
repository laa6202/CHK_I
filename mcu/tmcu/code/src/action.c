#include "action.h"
#include "stm32f4xx_hal.h"


static int index;

int App_Init(){
	index=0;
	LED_PB9_GPIO_Port->ODR = (LED_PB9_GPIO_Port->ODR & (~LED_PB9_Pin));	
	App_ADC1_Init();
	App_TIM5_Init();
	App_TIM7_Init();
	return 0;
}

int App_Action(){
	
//	IWDG->KR = 0xAAAA;
	return 0;
}


int App_TIM5_Init(){
	TIM5->CR1 = TIM5->CR1 | TIM_CR1_CEN;
	return 0;
}



int App_TIM7_IRQ(){
//	index++;
//	ADC1->CR2 = ADC1->CR2 | ADC_CR2_JSWSTART;
	return 0;
}


int App_TIM7_Init(){
	TIM7->DIER = (TIM7->DIER | TIM_DIER_UIE);
	TIM7->CR1 = (TIM7->CR1 | TIM_CR1_CEN);
	return 0;
}


int App_ADC1_Init(void)
{
	ADC1->CR1 = ADC1->CR1 | ADC_CR1_JEOCIE;
	ADC1->CR2 = ADC1->CR2 | ADC_CR2_ADON;
	return 0;
}


int App_ADC1_IRQ(void)
{
	if((ADC1->SR & ADC_SR_JEOC_Msk) == ADC_SR_JEOC_Msk)
		index++;
	return 0;
}


int App_ADC2_Init(void)
{
	return 0;
}
	

int App_ADC2_Action(void)
{
	return 0;
}

