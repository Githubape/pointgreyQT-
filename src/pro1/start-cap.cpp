#include "pch.h"
#include "FlyCapture2_C.h"
#include <stdio.h>
#include "shut.h"
#include "startcap-c.h"

int startcap(fc2Context context)
{
	fc2Error error;
	error = fc2StartCapture(context);     //≤∂ªÒ’’∆¨
	if (error != FC2_ERROR_OK)
	{	
		
		fc2DestroyContext(context);

		printf("Error in fc2StartCapture: %s\n", fc2ErrorToDescription(error));
		printf("Press Enter to exit...\n");
		getchar();
		return -1;
	}
	return 0;
}