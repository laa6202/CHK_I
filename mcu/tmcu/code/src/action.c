
#include "stm32f4xx_hal.h"
#include "arm_math.h"

#include "types.h"
#include "action.h"
#include "calc.h"
#include "commu.h"
#include "action_8k.h"
#include "action_10.h"
#include "action_pkg.h"



static int timeBegin;
static int timeEnd;
static int timeInter;
int rdy_A,rdy_B;
float32_t bufPointA[LEN_BUF];
float32_t bufPointB[LEN_BUF];
TPKG pkg_tube;


int Value_Init(){
	timeBegin = 0;
	timeEnd = 0;
	timeInter = 0;
	rdy_A = 0;	
	rdy_B = 0;
	arm_fill_f32(0,bufPointA,LEN_BUF);
	arm_fill_f32(0,bufPointB,LEN_BUF);

	TPKG_Init(&pkg_tube);
	return 0;
}


int App_Init(){
	Value_Init();
	SliceInit();
	Commu_Init();
//	SysTick->CTRL = (~SysTick_CTRL_CLKSOURCE_Msk) & SysTick->CTRL;
	SysTick->LOAD = SysTick_LOAD_RELOAD_Msk;
	LED_PB9_GPIO_Port->ODR = (LED_PB9_GPIO_Port->ODR & (~LED_PB9_Pin));	
	App_ADC1_Init();
	App_ADC2_Init();
	App_TIM5_Init();
	App_TIM7_Init();
	return 0;
}


int App_Action(){

	if(rdy_A == 1){
		BeginTick();
		BufSlice(bufPointA);
		GetFreq(&pkg_tube);
		IncTPKG(&pkg_tube);
		SendTPKG(pkg_tube);
		EndTick();
		rdy_A = 0;
	}
	
	if(rdy_B == 1){
		BufSlice(bufPointB);
		GetFreq(&pkg_tube);
		IncTPKG(&pkg_tube);
		SendTPKG(pkg_tube);
		rdy_B = 0;
	}

	IWDG->KR = 0xAAAA;
	return 0;
}



int App_TIM5_Init(){
	TIM5->CR1 = TIM5->CR1 | TIM_CR1_CEN;
	return 0;
}



int App_TIM7_IRQ(){
	ADC1->CR2 = ADC1->CR2 | ADC_CR2_JSWSTART;
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
		ADC1->SR = 0;
		GetADC1CH1(&pkg_tube);
		GetADC1CH4(&pkg_tube);
	}
	return 0;
}


int App_ADC2_Init(void)
{
	ADC2->CR1 = ADC2->CR1 | ADC_CR1_JEOCIE;
	ADC2->CR2 = ADC2->CR2 | ADC_CR2_ADON;
	return 0;
}
	

int App_ADC2_IRQ(void)
{
	if((ADC2->SR & ADC_SR_JEOC_Msk) == ADC_SR_JEOC_Msk){
		ADC2->SR = 0;
		BufPoint(bufPointA,bufPointB,&rdy_A,&rdy_B);
		U3Send_sel();
		GetCntM(&pkg_tube);
		GetCntX(&pkg_tube);
		IncIndex();
	}
	return 0;
}


int U2_IRQ(){
	if((USART2->SR & USART_SR_RXNE) == USART_SR_RXNE){
		U2RecData(&pkg_tube);
		USART2->SR = USART2->SR & (~USART_SR_RXNE);
	}
	return 0;
}


int U3_IRQ(){
	if((USART3->SR & USART_SR_TC_Msk) == USART_SR_TC_Msk){
		USART3->SR = USART3->SR & (~USART_SR_TC_Msk);
	}
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


