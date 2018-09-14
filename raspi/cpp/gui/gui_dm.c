#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gui_types.h"
#include "gui_dm.h"

#define EN_SHOW 0


int GetBlockTest(pBSHOW pBlock){
	pBlock->rpm = 2800;
	pBlock->tem = 85.1;
	pBlock->flag = 0;
	pBlock->err = 0;
	return 0;
}


int GetBlock(pBSHOW pBlock){

	FILE * fp = fopen("../../rec11.dat","r");
	char st[20]; memset(st,0,20*sizeof(char));

	fgets(st,20,fp);	//head
	fgets(st,20,fp);	//index
	fgets(st,20,fp);	//rot
	pBlock->rpm = atoi(st);

	fgets(st,20,fp);	//t1
	pBlock->tem = atof(st);
	if(EN_SHOW)	printf("tem = %3.2f\n",pBlock->tem);

	fgets(st,20,fp);	//t2
	fgets(st,20,fp);	//tCore
	fgets(st,20,fp);	//oilP
	fgets(st,20,fp);	//cntM
	fgets(st,20,fp);	//cntX
	fgets(st,20,fp);	//isM
	int isM = atoi(st);
	if(isM != 0)
		pBlock->flag = isM;

	fgets(st,20,fp);	//error
	int err = atoi(st);
		pBlock->err = err;
	
	fclose(fp);
	return 0;
}




