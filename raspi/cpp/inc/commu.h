#ifndef __COMMU_H
#define __COMMU_H

#include <types.h>

int I2C_Init(void);
int I2C_Test(void);
int GetTPKG(U8 *);
int ShowTPKG(const U8 *);
int TPKGIsNew(U8 *,U8 *);

#endif

