#ifndef __ACTION_PKG_H
#define __ACTION_PKG_H

#include "types.h"

int TPKG_Init(pTPKG);
int BufSlice(float*);
int GetFreq(pTPKG pkg);
int IncTPKG(pTPKG pkg);
int SendTPKG(TPKG);
int UpdateTPKG_T1(pTPKG);

#endif

