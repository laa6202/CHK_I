#ifndef __GUI_MAT_H
#define __GUI_MAT_H

#define MAT_W 800 
#define MAT_H 600

#include "gui_types.h"

int BuildBase(IplImage *);
int BuildTitle(IplImage *);
int BuildLogo(IplImage *);
int BuildCam(IplImage *,CvCapture *);

int ShowRPM(IplImage *,BSHOW);
int ShowTem(IplImage *,BSHOW);
int ShowFlag(IplImage *,BSHOW);

#endif

