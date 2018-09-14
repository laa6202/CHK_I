#ifndef __CAL_H
#define __CAL_H

#include <types.h>

int CalInit(void);
int CalRec1(pREC1,const U8 *);

int CalHead(const U8*);
int CalIndex(const U8*);
int CalRot(const U8 *);
float CalT1(const U8 *);
float CalT2(const U8 *);
float CalTCore(const U8 *);
float CalOilP(const U8 *);
int CalCntM(const U8 *);
int CalCntX(const U8 *);
int CalSumX(const U8 *);

#endif

