
#include <stdio.h>
#include <string.h>

#include <action.h>
#include <commu.h>
#include <types.h>
#include <cal.h>
#include <alg.h>
#include <record.h>


#define LEN_BUF 32

U8 recBuf[LEN_BUF];
U8 recBufOld[LEN_BUF];
REC1 rec1;


int AppInit(){
	memset(recBuf,0,LEN_BUF*sizeof(U8));
	memset(recBufOld,0,LEN_BUF*sizeof(U8));
	memset(&rec1,0,sizeof(REC1));
	I2C_Init();
	CalInit();	
	return 0;
}


int AppMain(){
	GetTPKG(recBuf);
//	ShowTPKG(recBuf);
	if(!TPKGIsNew(recBuf,recBufOld)){
		ShowTPKG(recBuf);
		CalRec1(&rec1,recBuf);
		GetFlag(&rec1);
		GetError(&rec1);
		SaveRec11(rec1);
	}
	else {
	}
	return 0;
}


