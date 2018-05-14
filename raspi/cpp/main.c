#include <wiringPi.h>

#include <stdio.h>
#include <action.h>


int main(int agrc,char *argv[]){
	printf("XMPP the Low APP of XDM-I\n");	
	wiringPiSetup();
	AppInit();

	for(int i=0;i<10;i++){
		printf("Main i=%d\n",i);	
		AppMain();
		delay(200);
	}	
	return 0;
}


