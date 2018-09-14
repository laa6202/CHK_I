
#include <stdio.h>
#include <string.h>

#include <alg.h>
#include <types.h>
#include <record.h>


#define TH_M 	100
#define TH_X  10

int GetFlag(pREC1 rec){
//	printf("cntM = %d\n",rec->cntM);
	if(rec->cntX > TH_X)
		rec->isM = 2;
	else if(rec->cntM > TH_M)
		rec->isM = 1;
	else 
		rec->isM = 0;
	return 0;
}


int GetError(pREC1 rec){
	int err = 0;
	int index[10];
	for(int i=9;i>0;i--)
		index[i] = index[i-1];
	index[0] = rec->index;
	int diff  = 0;
	for(int i=0;i<9;i++)
		diff += (index[i] - index[i+1]);
	if(diff == 0)
		err = 1;
 	rec->error = err;
	return 0;
}


int RotGap(int rot){
	static int d2;
	static int d1;
	static int d0;
	d2 = d1;
	d1 = d0;	
	d0 = rot;
	int d = d1;
	if((d1 > d2) && (d1 > d0))
		d = (d2 + d0) /2;
	return d;
}



int RotFIR5(int rot_now){
	static int rot_d[6];
	for(int i=5;i>0;i--)
		rot_d[i] = rot_d[i-1];
	rot_d[0] = rot_now;
	int sum =0;
	sum += (rot_d[0] * 8);
	sum += (rot_d[1] * 4);
	sum += (rot_d[2] * 2);
	sum += (rot_d[3] * 1);
	sum += (rot_d[4] * 1);
	int fir5 = sum / 16;
	return fir5;
}




int RotAve(int rot_now,int level){
	static int rot_d[20];
	if (level > 19)
		level = 19;
	for(int i=level;i>0;i--)
		rot_d[i] = rot_d[i-1];
	rot_d[0] = rot_now;

	int sum = 0;
	for(int i=0;i<level;i++){
		sum += rot_d[i];
	}
	
	int ave = sum / level;

	return ave;
}



int RotModK(int rot){
	float k;
	float b;

	LoadKBTest(&k,&b);
	float rot_f = k * rot + b;

	return rot_f;
}



int RotMod100(int rot){
	int a;
	if(rot > 2750)
		a = 2800;
	else if (rot < 100)
		a = 0;
	else a = rot;
	int b = a /10;
	return b*10;
}


