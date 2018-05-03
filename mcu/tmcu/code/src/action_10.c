//action_10.c

#include "stm32f4xx_hal.h"

#include "types.h"
#include "action_10.h"


int GetADC1CH1(pDADC padc1){
	padc1->ch1 = ADC1->JDR1;
	return 0;
}


int GetADC1CH4(pDADC padc1){
	padc1->ch4 = ADC1->JDR4;	
	return 0;
}
