#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "opencv2/opencv.hpp"

#include "gui_types.h"
#include "gui_action.h"
#include "gui_mat.h"
#include "gui_dm.h"


char winName[20];

void *GUI_Action(void * args){
	printf("...GUI_Action: \n");
	strcpy(winName,"XDM-I");
	struct timeval tv;
	
	BSHOW blockShow;
	CvCapture *cam;
	IplImage *mat;
	IplImage *matRef;
	mat = cvCreateImage(cvSize(MAT_W,MAT_H),IPL_DEPTH_8U,3);
	cvNamedWindow(winName,CV_WINDOW_NORMAL);
	cvSetWindowProperty(winName,CV_WND_PROP_FULLSCREEN,CV_WINDOW_FULLSCREEN);
	
	BuildBase(mat);

	matRef = cvCloneImage(mat); //matRef is base 
	cam = cvCaptureFromCAM(0);

	while(1){
		cvCopy(matRef,mat);
		GetBlockTest(&blockShow);
		ShowRPM(mat,blockShow);
		ShowTem(mat,blockShow);
		ShowFlag(mat,blockShow);
		BuildCam(mat,cam);
		cvShowImage(winName,mat);

		char key = cvWaitKey(100);
		if(key == 'q')
			break;
	}
}


int CamInit(int cid){
	
	return 0;
}

