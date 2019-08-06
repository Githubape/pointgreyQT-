#include "pch.h"
#include "FlyCapture2_C.h"
#include <stdio.h>
#include "shut.h"

int shut(contextmat * con)
{	
	fc2Error error;

	error = fc2DestroyImage(con->rawImage);  //ÊÍ·Å
	if (error != FC2_ERROR_OK)
	{
		printf("Error in fc2DestroyImage: %s\n", fc2ErrorToDescription(error));
		return -1;
	}

	error = fc2DestroyImage(con->convertedImage);  //ÊÍ·Å
	if (error != FC2_ERROR_OK)
	{
		printf("Error in fc2DestroyImage: %s\n", fc2ErrorToDescription(error));
		return -1;
	}

	error = fc2DestroyContext(*con->context);
	if (error != FC2_ERROR_OK)
	{
		printf("Error in fc2DestroyContext: %s\n", fc2ErrorToDescription(error));
		printf("Press Enter to exit...\n");
		getchar();
		return -1;
	}
	return 0;

}