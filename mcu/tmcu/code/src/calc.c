#include "stm32f4xx_hal.h"
#include "arm_math.h"

#include "types.h"
#include "calc.h"


SLICE sliceA;
static float tt;

int SliceInit(void){
	return 0;
}

int BufSlice(float* bufA){
	sliceA.t = bufA;
	//for calc temp
	arm_scale_f32(sliceA.t,0.0008056640625f,sliceA.t,LEN_SLICE);
//		arm_scale_f32(bufA,3.3f,bufA,8000);
	
	tt = bufA[0];
	return 0;
}




