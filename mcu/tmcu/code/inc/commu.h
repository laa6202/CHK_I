#ifndef __COMMU_H
#define __COMMU_H

#include "types.h"

int Commu_Init(void);
int U1_IRQ(void);
int U1_IRQ_END(void);
int U2RecData(pTPKG);
U8 GetU2RecBuf(int);
int U1Send(TPKG);
int U3Send(U8);

#endif

