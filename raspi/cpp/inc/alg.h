#ifndef __ALG_H
#define __ALG_H

#include <types.h>

int GetFlag(pREC1);
int GetError(pREC1);

int RotGap(int rot);
int RotFIR5(int rot_now);
int RotAve(int rot_now,int level);
int RotModK(int rot);
int RotMod100(int rot);


#endif

