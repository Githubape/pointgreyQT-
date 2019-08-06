
#if defined(_WIN32) || defined(_WIN64)
#define _CRT_SECURE_NO_WARNINGS
#endif
#include "pch.h"
#include "FlyCapture2_C.h"
#include <stdio.h>
#include "context.h"
#include "init-c.h"

void PrintBuildInfo()        
{
	fc2Version version;
	char versionStr[512];
	char timeStamp[512];

	fc2GetLibraryVersion(&version);

	printf(versionStr,
		"FlyCapture2 library version: %d.%d.%d.%d\n",
		version.major,
		version.minor,
		version.type,
		version.build);

	printf("%s", versionStr);

	printf(timeStamp, "Application build date: %s %s\n\n", __DATE__, __TIME__);

	printf("%s", timeStamp);
}
void SetTimeStamping(fc2Context context, BOOL enableTimeStamp) //时间标记
{
	fc2Error error;
	fc2EmbeddedImageInfo embeddedInfo;

	error = fc2GetEmbeddedImageInfo(context, &embeddedInfo);  //获取相机信息
	if (error != FC2_ERROR_OK)
	{
		printf("Error in fc2GetEmbeddedImageInfo: %s\n", fc2ErrorToDescription(error));
	}

	if (embeddedInfo.timestamp.available != 0)
	{
		embeddedInfo.timestamp.onOff = enableTimeStamp;
	}

	error = fc2SetEmbeddedImageInfo(context, &embeddedInfo);  //设置相机信息
	if (error != FC2_ERROR_OK)
	{
		printf("Error in fc2SetEmbeddedImageInfo: %s\n", fc2ErrorToDescription(error));
	}
}

void PrintCameraInfo(fc2Context context)  
{
	fc2Error error;
	fc2CameraInfo camInfo;
	error = fc2GetCameraInfo(context, &camInfo);
	if (error != FC2_ERROR_OK)
	{
		printf("Error in fc2GetCameraInfo: %s\n", fc2ErrorToDescription(error));
	}

	printf("\n*** CAMERA INFORMATION ***\n"
		"Serial number - %u\n"
		"Camera model - %s\n"
		"Camera vendor - %s\n"
		"Sensor - %s\n"
		"Resolution - %s\n"
		"Firmware version - %s\n"
		"Firmware build time - %s\n\n",
		camInfo.serialNumber,
		camInfo.modelName,
		camInfo.vendorName,
		camInfo.sensorInfo,
		camInfo.sensorResolution,
		camInfo.firmwareVersion,
		camInfo.firmwareBuildTime);
}











int  init(contextmat *con)
{
	//contextmat *con=new(contextmat);
	fc2Error error;
	//fc2Context context;
	fc2PGRGuid guid;
	unsigned int numCameras = 0;

	PrintBuildInfo();

	error = fc2CreateContext(con->context);
	if (error != FC2_ERROR_OK)
	{
		printf("Error in fc2CreateContext: %s\n", fc2ErrorToDescription(error));
		printf("Press Enter to exit...\n");
		getchar();
		return -1;
	}
	error = fc2GetNumOfCameras(*(con->context), &numCameras);      //获取相机数量
	if (error != FC2_ERROR_OK)
	{
		fc2DestroyContext(*(con->context));

		printf("Error in fc2GetNumOfCameras: %s\n", fc2ErrorToDescription(error));
		printf("Press Enter to exit...\n");
		getchar();
		return -1;
	}

	if (numCameras == 0)
	{
		fc2DestroyContext(*(con->context));

		// No cameras detected
		printf("No cameras detected.\n");
		printf("Press Enter to exit...\n");
		getchar();
		return -1;
	}

	// Get the 0th camera
	error = fc2GetCameraFromIndex(*(con->context), 0, &guid);
	if (error != FC2_ERROR_OK)
	{
		fc2DestroyContext(*(con->context));

		printf("Error in fc2GetCameraFromIndex: %s\n", fc2ErrorToDescription(error));
		printf("Press Enter to exit...\n");
		getchar();
		return -1;
	}

	error = fc2Connect(*(con->context), &guid);
	if (error != FC2_ERROR_OK)
	{
		fc2DestroyContext((con->context));

		printf("Error in fc2Connect: %s\n", fc2ErrorToDescription(error));
		printf("Press Enter to exit...\n");
		getchar();
		return -1;
	}
	SetTimeStamping(*(con->context), TRUE);

	PrintCameraInfo(*(con->context));      //打印相机信息
	
	
	error = fc2CreateImage(con->rawImage);
	if (error != FC2_ERROR_OK)
	{
		printf("Error in fc2CreateImage: %s\n", fc2ErrorToDescription(error));
		return -1;
	}

	error = fc2CreateImage(con->convertedImage);
	if (error != FC2_ERROR_OK)
	{
		printf("Error in fc2CreateImage: %s\n", fc2ErrorToDescription(error));
		return -1;
	}
	return 0;
}