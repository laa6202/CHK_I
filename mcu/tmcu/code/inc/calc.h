#ifndef __CALC_H
#define __CALC_H


#include "types.h"

int SliceInit(void);
int TestData(pSLICE);

int SliceRFFT(pSLICE);
int ABSFreq(pSLICE);
int FirFreq(int);
int MeanFreq(pSLICE,float *);

#endif


