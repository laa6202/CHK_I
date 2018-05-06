
#include <stdio.h>
#include <string.h>

#include <action.h>
#include <commu.h>
#include <types.h>

#define LEN_BUF 32

U8 recBuf[LEN_BUF];


int AppInit(){
	memset(recBuf,0,LEN_BUF*sizeof(U8));
	I2C_Init();
	
	return 0;
}


int AppMain(){
	GetTPKG(recBuf);
	ShowTPKG(recBuf);
	
	return 0;
}


