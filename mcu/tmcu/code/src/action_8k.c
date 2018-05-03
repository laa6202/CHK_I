//action_8k.c

#include "stm32f4xx_hal.h"

#include "types.h"
#include "action_8k.h"
#include "commu.h"


int index = 0;
int sel_send = 0;

int BufPoint(float * bufA,float * bufB,int * rdy_A,int *rdy_B){
			
	uint16_t adc_d1 =  ADC2->JDR1;
	float adc_d1f = (float)adc_d1;
		
	if(index < LEN_BUF){
		*(bufA+index) = adc_d1f;
		index++;
	}
	else if(index == LEN_BUF){
		*bufB = adc_d1f; 
		*rdy_A = 1;
		index++;
	}
	else if(index < 2*LEN_BUF){
		*(bufB + index - LEN_BUF) = adc_d1f;
		index++;
	}
	else{
		*bufA = adc_d1f; 
		*rdy_B = 1;
		index = 1;
	}
		
	return 0;
}


int U3Send_sel(){
	U8 data_tx = 0x55;
	switch (sel_send){
		case 0 : data_tx = index; break;
		case 1 : data_tx = (ADC2->JDR1) >> 4; break;
		case 2 : data_tx = (ADC2->JDR2) >> 4; break;
		case 3 : data_tx = (ADC2->JDR3) >> 4; break;
		case 4 : data_tx = (ADC2->JDR4) >> 4; break;
		
		default :data_tx = 0x55; 
	}
	U3Send(data_tx);
	
	
	return 0;
}


