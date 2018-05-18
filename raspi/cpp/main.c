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

		if(i>1000)
			break;
	}	
	return 0;
}


