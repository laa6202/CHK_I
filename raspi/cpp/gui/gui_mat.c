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
	strcat(fnBase,"/pic/base3.png");
	mBase = cvLoadImage(fnBase);
	cvResize(mBase,mat);
//	cvCopy(mBase,mat);
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
	int camW = 360;
	int camH = 360;
	int camTop = 180;
	int camLeft = 410;
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

//	cvReleaseImage(&mCam);
	cvReleaseImage(&mCam2);

	return 0;
}


int ShowRPM(IplImage * mat,BSHOW block){

	CvFont fontRPM;
	double hS =1.8;
	double vS =1.8;
	int lineW = 2;
	char cRPM[40];	memset(cRPM,0,40*sizeof(char));
	int rpm = block.rpm;
	sprintf(cRPM,"%d",rpm);
//	fontRPM = cvFontQt("Times");
//	cvAddText(mat,cRPM,cvPoint(300,250),&fontRPM);
	cvInitFont(&fontRPM,CV_FONT_HERSHEY_SIMPLEX,hS,vS,0,lineW);
	if(rpm < 2300)
		cvPutText(mat,cRPM,cvPoint(240,260),&fontRPM,CV_RGB(255,0,0));
	else 
		cvPutText(mat,cRPM,cvPoint(240,260),&fontRPM,CV_RGB(20,200,20));
	return 0;
}




int ShowTem(IplImage * mat,BSHOW block){

	CvFont font;
	double hS =1.8;
	double vS =1.8;
	int lineW = 2;
	float tem = block.tem;
	char cTem[40];	memset(cTem,0,40*sizeof(char));
	sprintf(cTem,"%02.1f",block.tem);
//	fontRPM = cvFontQt("Times");
//	cvAddText(mat,cRPM,cvPoint(300,250),&fontRPM);
	cvInitFont(&font,CV_FONT_HERSHEY_SIMPLEX,hS,vS,0,lineW);
	if(tem <= 69)
		cvPutText(mat,cTem,cvPoint(240,370),&font,CV_RGB(20,200,20));
	else
		cvPutText(mat,cTem,cvPoint(240,370),&font,CV_RGB(255,0,0));

	return 0;
}


int ShowFlag(IplImage * mat,BSHOW block){
	int flag = block.flag;


	IplImage *mFlag;
	IplImage *mFlag2;
	char fnFlag[200];	memset(fnFlag,0,200*sizeof(char));
	getcwd(fnFlag,200);
	if(flag == 1)
		strcat(fnFlag,"/pic/prepare.png");
	else if(flag == 2)
		strcat(fnFlag,"/pic/working.png");
	else 
		return 0;

	mFlag = cvLoadImage(fnFlag);
//	cvShowImage("Flag",mFlag);

	int mW = 300;	//width
	int mH = 50;	//height
	mFlag2 = cvCreateImage(cvSize(mW,mH),mFlag->depth,mFlag->nChannels);
	cvResize(mFlag,mFlag2);
//	cvShowImage("title",mFlag2);

	CvRect roiFlag = cvRect(200,100,mW,mH);
	cvSetImageROI(mat,roiFlag);
	cvCopy(mFlag2,mat);
	cvResetImageROI(mat);

	return 0;
}



