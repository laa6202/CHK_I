#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "opencv2/opencv.hpp"

#include "gui_action.h"

char winName[20];

void *GUI_Action(void * args){
	printf("...GUI_Action: \n");
	struct timeval tv;
	CvCapture *cam;
	IplImage * m1;

	strcpy(winName,"aa");

	gettimeofday(&tv,NULL);
	printf("t0 = %d.%06d\n",tv.tv_sec,tv.tv_usec);
	cvNamedWindow(winName);
	cam = cvCaptureFromCAM(0);

	gettimeofday(&tv,NULL);
	printf("t1 = %d.%06d\n",tv.tv_sec,tv.tv_usec);


	while(1){
	gettimeofday(&tv,NULL);
	printf("t3 = %d.%06d\n",tv.tv_sec,tv.tv_usec);
		m1 = cvQueryFrame(cam);

	gettimeofday(&tv,NULL);
	printf("t4 = %d.%06d\n",tv.tv_sec,tv.tv_usec);
		cvShowImage(winName,m1);

	gettimeofday(&tv,NULL);
	printf("t5 = %d.%06d\n",tv.tv_sec,tv.tv_usec);

		char key = cvWaitKey(100);
		if(key == 'q')
			break;
	}
}


int CamInit(int cid){
	
	return 0;
}

