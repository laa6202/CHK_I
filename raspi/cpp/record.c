
#include <stdio.h>
#include <string.h>

#include <record.h>
#include <types.h>

int SaveRec1(REC1 rec){
	char fn[] = "rec1.dat";
	FILE * fid = fopen(fn,"w");
	fwrite(&rec,1,sizeof(REC1),fid);
	fclose(fid);	
	return 0;
}
