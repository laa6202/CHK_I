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

	cvNamedWindow(winName);
	cam = cvCaptureFromCAM(0);

	while(1){
		m1 = cvQueryFrame(cam);
		cvShowImage(winName,m1);

		char key = cvWaitKey(100);
		if(key == 'q')
			break;
	}
}


int CamInit(int cid){
	
	return 0;
}

