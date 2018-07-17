#include <stdio.h>
#include <stdlib.h>

#include "gui_types.h"
#include "gui_dm.h"


int GetBlock(pBSHOW pBlock){
	pBlock->rpm = 2800;
	pBlock->tem = 85.1;
	pBlock->flag = 0;

	return 0;
}

