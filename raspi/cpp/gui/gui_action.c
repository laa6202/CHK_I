#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "opencv2/opencv.hpp"

#include "gui_action.h"
#include "gui_mat.h"
#include "gui_dm.h"


char winName[20];

void *GUI_Action(void * args){
	printf("...GUI_Action: \n");
	strcpy(winName,"XDM-I");
	struct timeval tv;

	CvCapture *cam;
	IplImage *mat;
	mat = cvCreateImage(cvSize(MAT_W,MAT_H),IPL_DEPTH_8U,3);
	cvNamedWindow(winName);
	cvSetWindowProperty(winName,CV_WND_PROP_FULLSCREEN,CV_WINDOW_FULLSCREEN);
	
	BuildBase(mat);
	BuildTitle(mat);
	BuildLogo(mat);


	cam = cvCaptureFromCAM(0);

	while(1){
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

