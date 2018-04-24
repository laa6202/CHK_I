#ifndef __TYPES_H
#define __TYPES_H

#define LEN_SLICE 8000


typedef struct {
	int index;
	float t[LEN_SLICE];
	float f[LEN_SLICE];
	int flag;
} SLICE,pSLICE;



#endif
