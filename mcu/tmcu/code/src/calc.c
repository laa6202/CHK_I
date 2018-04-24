#include "stm32f4xx_hal.h"
#include "arm_math.h"

#include "types.h"
#include "calc.h"


SLICE sliceA;

int SliceInit(void){
	
	arm_fill_f32(0.0f,sliceA.t,LEN_SLICE);
	arm_fill_f32(0.0f,sliceA.f,LEN_SLICE);
	return 0;
}

int BufSlice(float* bufA){
//	arm_q15_to_float(bufA,sliceA.t,LEN_SLICE);
	
	return 0;
}




