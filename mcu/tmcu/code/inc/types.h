#ifndef __TYPES_H
#define __TYPES_H

#define LEN_SLICE 4096
#define LEN_BUF		4096

typedef unsigned char  U8;
typedef unsigned short U16;

typedef struct {
	int index;
	float t[LEN_SLICE];
	float f[LEN_SLICE];
	int flag;
} SLICE,*pSLICE;


typedef struct {
	U16 head;
	U16 index;
	U16 freq;
	U16 cnt_m;
	U16 cnt_x;
	U16 t_core;
	U16 p_oil;
	U16 t_1;
	U16 t_2;
	U16 h_1;
	U16 res[6];
} TPKG,*pTPKG;
	

typedef struct{
	U16 ch1;
	U16 ch2;
	U16 ch3;
	U16 ch4;
} DADC1,DADC2,*pDADC1,*pDADC2;

#endif
