
#include "stm32f4xx_hal.h"
#include "arm_math.h"
#include "action.h"
#include "calc.h"

#define LEN_BUF 8000

static int indexPoint;
static int timeBegin;
static int timeEnd;
static int timeInter;
int rdy_A,rdy_B;
float32_t bufPointA[LEN_BUF];
float32_t bufPointB[LEN_BUF];


int Value_Init(){
	indexPoint=0;
	timeBegin = 0;
	timeEnd = 0;
	timeInter = 0;
	rdy_A = 0;	
	rdy_B = 0;
//	arm_fill_f32(0,bufPointA,LEN_BUF);
//	arm_fill_f32(0,bufPointB,LEN_BUF);
	return 0;
}


int App_Init(){
	Value_Init();
//	SliceInit();
	//SysTick->CTRL = (~SysTick_CTRL_CLKSOURCE_Msk) & SysTick->CTRL;
	SysTick->LOAD = SysTick_LOAD_RELOAD_Msk;
	LED_PB9_GPIO_Port->ODR = (LED_PB9_GPIO_Port->ODR & (~LED_PB9_Pin));	
	App_ADC1_Init();
	App_TIM5_Init();
//	App_TIM7_Init();
	return 0;
}

int App_Action(){

	if(rdy_A == 1){
	//		BeginTick();
		BufSlice(bufPointA);
		rdy_A = 0;
	//		EndTick();
	}
	
	if(rdy_B == 1){
		BufSlice(bufPointB);
		rdy_B = 0;
	}

//	IWDG->KR = 0xAAAA;
	return 0;
}


int App_TIM5_Init(){
	TIM5->CR1 = TIM5->CR1 | TIM_CR1_CEN;
	return 0;
}



int App_TIM7_IRQ(){
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
	if((ADC1->SR & ADC_SR_JEOC_Msk) == ADC_SR_JEOC_Msk){
		BeginTick();
		
		uint16_t adc_d1 =  ADC1->JDR1;
		float adc_d1f = 0.3f;
		
		if(indexPoint < LEN_BUF){
			bufPointA[indexPoint] = adc_d1f;
			indexPoint++;
		}
		else if(indexPoint == LEN_BUF){
			bufPointB[0] = adc_d1f; 
			rdy_A = 1;
			indexPoint++;
		}
		else if(indexPoint < 2*LEN_BUF){
			bufPointA[indexPoint - LEN_BUF] = adc_d1f;
			indexPoint++;
		}
		else{
			bufPointA[0] = adc_d1f; 
			rdy_B = 1;
			indexPoint = 1;
			}
			EndTick();
	}
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


int BeginTick(void){
	timeBegin = SysTick->VAL;
	return 0;
}

int EndTick(void){
	timeEnd = SysTick->VAL;
	timeInter = timeBegin - timeEnd;
	return timeInter;
}


