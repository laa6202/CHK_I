#ifndef __ACTION_H
#define __ACTION_H


int D5OutH(void);
int D5OutL(void);
int D5In(void);
int D5Check(void);
int D5ReadBit(void);
int D5WriteBit(int);
int D5WriteByte(int);
int D5ReadByte(void);

int T1_Reset(void);
int T1_Init(void);
int T1_GetTemp(void);
#endif

