#include "stm32f4xx_hal.h"
#include "arm_math.h"

#include "types.h"
#include "calc.h"

#define LEN_TEST 4096


SLICE sliceA;
arm_rfft_fast_instance_f32 aa;
static float din[LEN_TEST],dout[LEN_TEST];

int SliceInit(void){

	arm_fill_f32(0,sliceA.f,LEN_SLICE);
	arm_fill_f32(0,sliceA.t,LEN_SLICE);
	TestInit();
	arm_status ret = arm_rfft_fast_init_f32 (&aa,LEN_TEST);
	if(ret != ARM_MATH_SUCCESS)
		return -1;
	return 0;
}


int TestInit(void){
	for(int i=0;i<LEN_TEST;i++)
		din[i] = cos(2*PI*i*10/LEN_TEST);
	return 0;
}


int BufSlice(float* bufA){
	arm_copy_f32(bufA,sliceA.t,LEN_SLICE);
	//for calc temp
	arm_scale_f32(sliceA.t,0.0008056640625f,sliceA.t,LEN_SLICE);
	
	return 0;
}


int TestRFFT(){
	float din2[LEN_TEST];
	arm_copy_f32(din,din2,LEN_TEST);
	arm_rfft_fast_f32(&aa,din2,dout,0);
	return 0;
}


