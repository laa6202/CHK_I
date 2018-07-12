
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


int SaveRec11(REC1 rec){
	char fn[] = "rec11.dat";
	FILE * fid = fopen(fn,"w");
	fprintf(fid,"%08x\n%d\n%d\n",rec.head,rec.index,rec.rot);
//fprintf(fid,"%.2f\n%.2f\n%.2f\n%.2f\n",rec.t1,rec.t2,rec.tCore,rec.oilP);
	fprintf(fid,"%.2f\n%.2f\n%.2f\n%.2f\n",rec.tCore,rec.tCore,rec.tCore,rec.oilP);
	fprintf(fid,"%d\n%d\n",rec.cntM,rec.cntX);
	fprintf(fid,"%d\n%d\n",rec.isM,rec.error);
	fclose(fid);
	return 0;
}
