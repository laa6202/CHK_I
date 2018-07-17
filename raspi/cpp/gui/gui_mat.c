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
	IplImage * mCam;
	IplImage * mCam2;
	int camW = 450;
	int camH = 450;
	int camTop = 200;
	int camLeft = 650;
	if(cam == NULL){
		char fnCam[200];	memset(fnCam,0,200*sizeof(char));
		getcwd(fnCam,200);
		strcat(fnCam,"/pic/noCam.jpg");
		mCam = cvLoadImage(fnCam);
//		printf("no cam = %d\n",cam);
	}
	else{ 
		mCam = cvQueryFrame(cam);
	}
//	cvShowImage("Cam",mCam);
	mCam2 = cvCreateImage(cvSize(camW,camH),mCam->depth,mCam->nChannels);
	cvResize(mCam,mCam2);

	CvRect roiTitle = cvRect(camLeft,camTop,camW,camH);
	cvSetImageROI(mat,roiTitle);
	cvCopy(mCam2,mat);
	cvResetImageROI(mat);

	return 0;
}


int ShowRPM(IplImage * mat,BSHOW block){

	CvFont fontRPM;
	double hS =1;
	double vS =1;
	int lineW = 2;
	char cRPM[40];	memset(cRPM,0,40*sizeof(char));
	sprintf(cRPM,"%d RPM",block.rpm);
//	fontRPM = cvFontQt("Times");
//	cvAddText(mat,cRPM,cvPoint(300,250),&fontRPM);
	cvInitFont(&fontRPM,CV_FONT_HERSHEY_SIMPLEX,hS,vS,0,lineW);
	cvPutText(mat,cRPM,cvPoint(300,250),&fontRPM,CV_RGB(255,0,0));

	return 0;
}





