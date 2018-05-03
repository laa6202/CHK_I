#ifndef __ACTION_H
#define __ACTION_H

int Value_Init(void);
int App_Init(void);
int App_Action(void);

int App_TIM5_Init(void);
int App_TIM7_IRQ(void);
int App_TIM7_Init(void);

int App_ADC1_Init(void);
int App_ADC1_IRQ(void);

int App_ADC2_Init(void);
int App_ADC2_IRQ(void);

int BeginTick(void);
int EndTick(void);

#endif


