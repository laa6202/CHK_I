#include "stm32f4xx_hal.h"
#include "arm_math.h"

#include "types.h"
#include "calc.h"


static SLICE sliceA;
static float tt;

int SliceInit(void){
	
//	arm_fill_f32(0.0f,sliceA.t,LEN_SLICE);
//	arm_fill_f32(0.0f,sliceA.f,LEN_SLICE);
	return 0;
}

int BufSlice(float* bufA){
	arm_copy_f32(bufA,sliceA.t,LEN_SLICE);
	tt = sliceA.t[0];
	//for calc temp
//	arm_scale_f32(sliceA.t,0.0008056640625f,sliceA.t,LEN_SLICE);
		arm_scale_f32(sliceA.t,3.3f,sliceA.t,LEN_SLICE);
	
	tt = sliceA.t[0];
	return 0;
}




