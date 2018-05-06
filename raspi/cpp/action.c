
#include <stdio.h>

#include <action.h>
#include <commu.h>

int AppInit(){
	I2C_Init();
	
	return 0;
}


int AppMain(){

	GetTPKG();
	ShowTPKG();
	return 0;
}


