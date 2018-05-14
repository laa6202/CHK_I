#ifndef __TYPES_H
#define __TYPES_H

typedef unsigned char 	U8;
typedef unsigned short 	U16;
typedef unsigned int 		U32;

typedef struct {
	int rot;
	int t1;
	int t2;
	int tCore;
	int oilP;
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

