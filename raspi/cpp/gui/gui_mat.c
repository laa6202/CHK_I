#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "opencv2/opencv.hpp"
#include "gui_mat.h"


int BuildBase(IplImage * mat){
	IplImage *mBase;
	char fnBase[200];	memset(fnBase,0,200*sizeof(char));
	getcwd(fnBase,200);
	strcat(fnBase,"/pic/base2.png");
	mBase = cvLoadImage(fnBase);
	cvCopy(mBase,mat);
//	cvShowImage("base2",mat);
	return 0;
}



int BuildTitle(IplImage * mat){
	IplImage * mTitle;
	char fn[200]; memset(fn,0,200*sizeof(char));
	getcwd(fn,200);
	strcat(fn,"/pic/Title.png");
	printf("fnTitle = %s\n",fn);
	mTitle = cvLoadImage(fn);
//	cvShowImage("title",mTitle);
	IplImage *mTitle2 = cvCreateImage(cvSize(700,100),mTitle->depth,mTitle->nChannels);
	cvResize(mTitle,mTitle2);
//	cvShowImage("title",mTitle2);
	CvRect roiTitle = cvRect(250,0,700,100);
	cvSetImageROI(mat,roiTitle);
	cvCopy(mTitle2,mat);
	cvResetImageROI(mat);

	return 0;
}


int BuildLogo(IplImage * mat){


	return 0;
}


int BuildCam(IplImage * mat, CvCapture * cam){



	return 0;
}






