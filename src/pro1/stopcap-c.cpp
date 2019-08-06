#include "pch.h"
#include "FlyCapture2_C.h"
#include <stdio.h>
#include "shut.h"
#include "stopcap-c.h"

int stopcap(fc2Context context)

{
	fc2Error error;
	error = fc2StopCapture(context);
	if (error != FC2_ERROR_OK)
	{
		fc2DestroyContext(context);

		printf("Error in fc2StopCapture: %s\n", fc2ErrorToDescription(error));
		printf("Press Enter to exit...\n");
		getchar();
		return -1;
	}
	return 0;

}