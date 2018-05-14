

#include <stdio.h>

#include <cal.h>
#include <types.h>

int CalRec1(pREC1 rec,const U8 * recBuf){
	int rot = CalRot(recBuf);
	float tCore = CalTCore(recBuf);
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


float CalT2(const U8 * recBuf){
	
 	return 0;
}


float CalTCore(const U8 * recBuf){
	int tH = (*(recBuf+10) >> 4) | (*(recBuf+11) << 4);
	int tL = *(recBuf+10) & 0xf;
	float tCore = tH + tL * 0.0625;
	printf("tCore = %03.2f\ttH = %02x\ttL = %02x\n",tCore,tH,tL);
 	return tCore;
}


float CalOilP(const U8 * recBuf){

	return 0;
}

