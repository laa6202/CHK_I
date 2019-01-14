#include <stdio.h>
#include <pthread.h>

#include "opencv2/opencv.hpp"
#include "gui_action.h"


int main(int argr,char ** argv){
	pthread_t pid1;
	printf("The gui of XMPP\n");

//	cvNamedWindow("aa");
//	pthread_create(&pid1,NULL,GUI_Action,NULL);
	(void*)GUI_Action(NULL);

	return 0;
}
