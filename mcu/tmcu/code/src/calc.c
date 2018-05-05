#include "stm32f4xx_hal.h"
#include "arm_math.h"

#include "types.h"
#include "calc.h"



arm_rfft_fast_instance_f32 aa;
float f_abs[LEN_SLICE/2];

int SliceInit(void){
	arm_status ret = arm_rfft_fast_init_f32 (&aa,LEN_SLICE);
	if(ret != ARM_MATH_SUCCESS)
		return -1;
	return 0;
}


int TestData(pSLICE slice){
	for(int i=0;i<LEN_SLICE;i++)
		*(slice->t+i) = arm_cos_f32(2*PI*i*10/LEN_SLICE);
	return 0;
}



int SliceRFFT(pSLICE slice){
	arm_rfft_fast_f32(&aa,slice->t,slice->f,0);
	return 0;
}


int ABSFreq(pSLICE slice ){
	arm_cmplx_mag_f32(slice->f,f_abs,LEN_SLICE/2);
	
	return 0;
}


int FirFreq(int th_freq){
	for(int i=0;i<th_freq;i++)
		f_abs[i] = 0;
	return 0;
}


int MeanFreq(pSLICE slice,float * freq){
	float mean_fabs;
	arm_mean_f32(f_abs,LEN_SLICE/2,&mean_fabs);
	*freq = mean_fabs;
	return 0;
}



