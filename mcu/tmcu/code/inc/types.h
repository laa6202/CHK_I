#ifndef __TYPES_H
#define __TYPES_H

#define LEN_SLICE 4096


typedef struct {
	int index;
	float t[LEN_SLICE];
	float f[LEN_SLICE];
	int flag;
} SLICE,pSLICE;



#endif
