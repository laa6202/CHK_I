#include <wiringPi.h>

#include <stdio.h>
#include <commu.h>



int main(int agrc,char *argv[]){
	printf("XMPP the Low APP of XDM-I\n");	

	wiringPiSetup();
	I2C_Init();

	for(int i=0;i<1;i++){
	GetTPKG();
//		I2C_Test();
		delay(300);
//		printf("Main i=%d\n",i);	
	}	
	return 0;
}


