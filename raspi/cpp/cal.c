

#include <stdio.h>

#include <cal.h>
#include <types.h>

int CalRec1(pREC1 rec,const U8 * recBuf){
	int rot = CalRot(recBuf);

	return 0;
}


int CalRot(const U8 * recBuf){
	int rot0 = *(recBuf+4) | (*(recBuf+5) << 8);
	int rot = rot0 * 50;
	printf("rot0 = %d\t rot = %d\n",rot0,rot);
	return 0;
}


float CalT1(const U8 * recBuf){
	
 	return 0;
}


float CalOilP(const U8 * recBuf){

	return 0;
}

