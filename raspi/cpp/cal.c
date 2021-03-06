

#include <stdio.h>

#include <types.h>
#include <cal.h>
#include <alg.h>

#define EN_SHOW 0

//unsigned int index;

int CalInit(){
	return 0;
}



int CalRec1(pREC1 rec,const U8 * recBuf){
	int head = CalHead(recBuf);
	int index = CalIndex(recBuf);
	int rot = CalRot(recBuf);
	float tCore = CalTCore(recBuf);
	float t1 = CalT1(recBuf);
	float t2 = CalT2(recBuf);
	float oilP = CalOilP(recBuf);
	int cntM = CalCntM(recBuf);
	int cntX = CalCntX(recBuf);
	long sumX = CalSumX(recBuf);
	rec->head = head;
	rec->index = index;
	rec->rot = rot;
	rec->t1 = t1;
	rec->t2 = t2;
	rec->tCore = tCore;
	rec->oilP = oilP;
	rec->cntM = cntM;
	rec->cntX = cntX;
	return 0;
}



int CalHead(const U8 * recBuf){
	int head = *(recBuf+0) | (*(recBuf+1) << 8);
	return head;
}


int CalIndex(const U8 * recBuf){
	int index = *(recBuf+2) | (*(recBuf+3) << 8);
	return index;
}


int CalRot(const U8 * recBuf){
	int rot0 = *(recBuf+4) | (*(recBuf+5) << 8);
	int rot = rot0 ;
	int rot1 = RotGap(rot);
	int rot_d = RotFIR5(rot1);
//	int rot_d = RotAve(rot,5);
	int rot_f = RotModK(rot_d);
//	int rot_100 = rot_f;
	int rot_100 = RotMod100(rot_f);

//	if(EN_SHOW) printf("rot = %d\t rot_d = %d\n",rot,rot_d);
	return rot_100;
}


float CalT1(const U8 * recBuf){
	int tH = (*(recBuf+14) >> 4) | (*(recBuf+15) << 4);
	int tL = *(recBuf+14) & 0xf;
	float t1 = tH + tL * 0.0625;
	if(EN_SHOW)	printf("t1 = %03.2f\ttH = %02x\ttL = %02x\n",t1,tH,tL);
 	return t1;
}


float CalT2(const U8 * recBuf){
	int tH = (*(recBuf+16) >> 4) | (*(recBuf+17) << 4);
	int tL = *(recBuf+16) & 0xf;
	float t2 = tH + tL * 0.0625;
	if(EN_SHOW)	printf("t2 = %03.2f\ttH = %02x\ttL = %02x\n",t2,tH,tL);
 	return t2;
}


float CalTCore(const U8 * recBuf){
	int tH = (*(recBuf+10) >> 4) | (*(recBuf+11) << 4);
	int tL = *(recBuf+10) & 0xf;
	float tCore = tH + tL * 0.0625;
	if(EN_SHOW)	printf("tCore = %03.2f\ttH = %02x\ttL = %02x\n",tCore,tH,tL);
 	return tCore;
}


float CalOilP(const U8 * recBuf){
	int oilP0 = *(recBuf+12) | (*(recBuf+13) << 8);
	float oilP = oilP * 1.2 + 100;
	return oilP;
}


int CalCntM(const U8 * recBuf){
	int cntM0 = *(recBuf+6) | (*(recBuf+7) << 8);
	int cntM = cntM0;
	return cntM;
}


int CalCntX(const U8 * recBuf){
	int cntX0 = *(recBuf+8) | (*(recBuf+9) << 8);
	int cntX = cntX0;
	return cntX;
}


int CalSumX(const U8 * recBuf){
	int SumX0 = *(recBuf+20) | (*(recBuf+21) << 8) | (*(recBuf+22)<<16) | (*(recBuf+23)<<24);
	int SumX = SumX0;
	return SumX;
}



