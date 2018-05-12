//action_pkg.c

#include "stm32f4xx_hal.h"
#include "arm_math.h"

#include "types.h"
#include "action_pkg.h"
#include "calc.h"
#include "commu.h"


SLICE sliceA;

int TPKG_Init(pTPKG pkg){
	memset(pkg,0,sizeof(TPKG));
	pkg->head = 0x5450;
	arm_fill_f32(0,sliceA.f,LEN_SLICE);
	arm_fill_f32(0,sliceA.t,LEN_SLICE);
	return 0;
}


int BufSlice(float* bufA){
	arm_copy_f32(bufA,sliceA.t,LEN_SLICE);
	//for calc temp
	//arm_scale_f32(sliceA.t,0.0008056640625f,sliceA.t,LEN_SLICE);
	
	return 0;
}


int GetFreq(pTPKG pkg){
	float  freq = 0;
	TestData(&sliceA);
	SliceRFFT(&sliceA);
	ABSFreq(&sliceA);
	FirFreq(8);
	MeanFreq(&sliceA,&freq);
	pkg->freq = freq;
	return 0;
}


int IncTPKG(pTPKG pkg){
	pkg->index ++;
	return 0;
}


int SendTPKG(TPKG pkg){
	
	U1Send(pkg);
	return 0;
}


int UpdateTPKG_T1(pTPKG pkg){
	
	return 0;
}

