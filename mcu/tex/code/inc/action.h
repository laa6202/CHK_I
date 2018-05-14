#ifndef __ACTION_H
#define __ACTION_H


int D7OutH(void);
int D7OutL(void);
int D7In(void);
int D7Check(void);
int D7ReadBit(void);
int D7WriteBit(int);
int D7WriteByte(int);
int D7ReadByte(void);

int T1_Reset(void);
int T1_Init(void);
int T1_GetTemp(void);
#endif

