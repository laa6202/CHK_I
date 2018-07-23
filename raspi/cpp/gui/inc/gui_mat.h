#ifndef __GUI_MAT_H
#define __GUI_MAT_H

#define MAT_W 1200
#define MAT_H 720

#include "gui_types.h"

int BuildBase(IplImage *);
int BuildTitle(IplImage *);
int BuildLogo(IplImage *);
int BuildCam(IplImage *,CvCapture *);

int ShowRPM(IplImage *,BSHOW);
int ShowTem(IplImage *,BSHOW);

#endif

