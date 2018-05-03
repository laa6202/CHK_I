#ifndef __COMMU_H
#define __COMMU_H

#include "types.h"

int Commu_Init(void);
int U1_IRQ(void);
int U2_IRQ(void);
int U3_IRQ(void);
int U1SendTest(void);
int U3SendTest(void);
int U1Send(TPKG);
int U3Send(U8);

#endif

