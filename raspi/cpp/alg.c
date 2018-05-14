
#include <stdio.h>
#include <string.h>

#include <alg.h>
#include <types.h>

int GetFlag(pREC1 rec){
//	printf("cntM = %d\n",rec->cntM);
	if(rec->cntM > 10)
		rec->isM = 1;
	return 0;
}


int GetError(pREC1 rec){
	int err = 0;
	if((rec->isM == 1) && (rec->rot < 2000))
		err = err | 0x1; 
	if(rec->tCore > 69)
		err = err | 0x2;
	if(rec->oilP > 1000)
		err = err | 0x4;
 	rec->error = err;
	return 0;
}
