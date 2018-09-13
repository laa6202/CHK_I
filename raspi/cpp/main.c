#include <wiringPi.h>

#include <stdio.h>
#include <action.h>




int main(int agrc,char *argv[]){
	printf("XMPP the Low APP of XDM-I\n");	
	wiringPiSetup();
	AppInit();

	int i=0;
	while(1){
		i++;
		printf("Main i=%d\n",i);	
		AppMain();
		delay(200);

#ifdef DEBUG
		if(i>10000)
			break;
#endif

	}	
	return 0;
}


