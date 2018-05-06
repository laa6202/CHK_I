#include <wiringPi.h>

#include <stdio.h>
#include <action.h>


int main(int agrc,char *argv[]){
	printf("XMPP the Low APP of XDM-I\n");	
	wiringPiSetup();
	AppInit();

	for(int i=0;i<1;i++){
		AppMain();
		delay(300);
		printf("Main i=%d\n",i);	
	}	
	return 0;
}


