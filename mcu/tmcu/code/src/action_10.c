//action_10.c
//IRQ for ADC1 get temp and oil press

#include "stm32f4xx_hal.h"

#include "types.h"
#include "action_10.h"

float temp_1 = 0;
float temp_2 = 0;
float temp_3 = 0;
float temp_4 = 0;
	
int GetADC1CH1(pTPKG ptpkg){
//temp = (Vsen - V25) / Avg_slope + 25;
//V25 = 0.76;	Avg_slope = 0.0025;
	temp_1 = ADC1->JDR1 / 4096.0f;
	temp_2 = (temp_1) * 3.3f;
	temp_3 = temp_2 - 0.76f;
	temp_4 = temp_3 / 0.0025f;
	ptpkg->t_core = (U16)((temp_4 + 25)*10);
	return 0;
}


int GetADC1CH4(pTPKG ptpkg){
	U16 pres_1 = ADC1->JDR4;	
	// no alg
	ptpkg->p_oil = pres_1;
	return 0;
}
