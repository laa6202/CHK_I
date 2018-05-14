#include <stdio.h>
#include <string.h>
#include <wiringPiI2C.h>

#include <commu.h>
#include <types.h>

#define LEN_TPKG 32

int fd;


int I2C_Init(){
	fd = wiringPiI2CSetup(0x30);
	printf("I2C setup ret = %d\n",fd);
	return 0;
}


int I2C_Test(){
	//int q = wiringPiI2CWriteReg8(fd,0x12,0x34);
	int q = wiringPiI2CReadReg8(fd,0x56);
	printf("read q = %d\n",q);
	return 0;
}


int GetTPKG(U8 * recBuf){
	for(int i=0;i<LEN_TPKG;i++){
		U8 ret = wiringPiI2CReadReg8(fd,i);
		*(recBuf+i) = ret;
	}
	return 0;
}


int ShowTPKG(const U8 *recBuf){
	for(int i=0;i<LEN_TPKG;i++){
		printf("\treg %d = 0x%02x",i,*(recBuf+i));
		if(i%4 == 3)
			printf("\n");
	}
	return 0;
}


int TPKGIsNew(U8 * recBuf,U8 * recBufOld){
	int isSame = 0;
	int index = *(recBuf+2) | (*(recBuf+3) << 8);
	int indexOld = *(recBufOld+2) | (*(recBufOld+3) << 8);
	if(index == indexOld){
//		printf("Same : index = %04x\n",index); 
		isSame = 1;
	}
	else {
//		printf("Diff : index = %04x\n",index); 
//		printf("Diff : indexOld = %04x\n",indexOld); 
		isSame = 0;
	}
	memcpy(recBufOld,recBuf,LEN_TPKG * sizeof(U8));	
	return isSame;
}


