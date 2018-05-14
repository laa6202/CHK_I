#ifndef __TYPES_H
#define __TYPES_H

typedef unsigned char 	U8;
typedef unsigned short 	U16;
typedef unsigned int 		U32;

typedef struct {
	int head;
	unsigned int index;
	int rot;
	float t1;
	float t2;
	float tCore;
	float oilP;
	int cntM;
	int cntX;
	int isM;
	int error;
}	REC1, *pREC1;


typedef struct {
	int rot;
	int t1;
	int sumX;
}	REC2, *pREC2;


#endif

