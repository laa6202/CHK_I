//action_8k.c
//All these functions runs at ADC2 IRQ


#include "stm32f4xx_hal.h"

#include "types.h"
#include "action_8k.h"
#include "commu.h"


int index_point = 0;
int sel_send = 2;
int th_m = 0x100;
int th_x = 0x100;

int BufPoint(float * bufA,float * bufB,int * rdy_A,int *rdy_B){		
	uint16_t adc_d1 =  ADC2->JDR1;
	float adc_d1f = (float)adc_d1;
		
	if(index_point < LEN_BUF){
		*(bufA+index_point) = adc_d1f;
	}
	else if(index_point == LEN_BUF){
		*bufB = adc_d1f; 
		*rdy_A = 1;
	}
	else if(index_point < 2*LEN_BUF){
		*(bufB + index_point - LEN_BUF) = adc_d1f;
	}
	else{
		*bufA = adc_d1f; 
		*rdy_B = 1;
	}
	return 0;
}


int IncIndex(){
	if(index_point < 2*LEN_BUF)
		index_point ++;
	else 
		index_point = 1;
	return 0;
}


int U3Send_sel(){
	U8 data_tx = 0x55;
	switch (sel_send){
		case 0 : data_tx = index_point; break;
		case 1 : data_tx = (ADC2->JDR1) >> 4; break;
		case 2 : data_tx = (ADC2->JDR2) >> 4; break;
		case 3 : data_tx = (ADC2->JDR3) >> 4; break;
		case 4 : data_tx = (ADC2->JDR4) >> 4; break;
		
		default :data_tx = 0x55; 
	}
	U3Send(data_tx);
	return 0;
}


int GetCntM(pTPKG ptpkg){
	int m_value = ADC2->JDR2;
	static int cnt_m;
	if(m_value >= th_m)
		cnt_m ++;
	
	if(index_point == LEN_BUF){
		ptpkg->cnt_m = cnt_m;
		cnt_m = 0;
	}
	else if(index_point == 2*LEN_BUF){
		ptpkg->cnt_m = cnt_m;
		cnt_m = 0;	
	}
	else ;
	
	return 0;
}


int GetCntX(pTPKG ptpkg){
	int x_value = ADC2->JDR3;
	static int sum_x;
	static int cnt_x;
	if(x_value >= th_x){
		cnt_x ++;
		sum_x += x_value; 
	}
	
	if(index_point == LEN_BUF){
		ptpkg->cnt_x = cnt_x;
		ptpkg->sum_x = sum_x;
		cnt_x = 0;
		sum_x = 0;
	}
	else if(index_point == 2*LEN_BUF){
		ptpkg->cnt_x = cnt_x;
		ptpkg->sum_x = sum_x;
		cnt_x = 0;
		sum_x = 0;
	}
	else ;	
	
	return 0;
}

