#include "pch.h"
#include "FlyCapture2_C.h"
#include <stdio.h>
#include "shut.h"
#include "grab-c.h"
#include "opencv2/opencv.hpp"
#include "context.h"
using namespace cv;

Mat GrabImages(contextmat *conp, int numImagesToGrab)
{
	Mat a;
	fc2Error error;
	fc2TimeStamp prevTimestamp = { 0 };
	int i;



	// If externally allocated memory is to be used for the converted image,
	// simply assigning the pData member of the fc2Image structure is
	// insufficient. fc2SetImageData() should be called in order to populate
	// the fc2Image structure correctly. This can be done at this point,
	// assuming that the memory has already been allocated.

	for (i = 0; i < numImagesToGrab; i++)
	{

		// Retrieve the image
		error = fc2RetrieveBuffer(*(conp->context), conp->rawImage); //¼ìË÷»º³åÇø

		if (error != FC2_ERROR_OK)
		{
			printf("Error in retrieveBuffer: %s\n", fc2ErrorToDescription(error));
			return a;
		}
		else
		{

			// Get and print out the time stamp
			fc2TimeStamp ts = fc2GetImageTimeStamp(conp->rawImage);
			int diff = (ts.cycleSeconds - prevTimestamp.cycleSeconds) * 8000 +
				(ts.cycleCount - prevTimestamp.cycleCount);
			prevTimestamp = ts;
			printf("timestamp [%d %d] - %d\n",
				ts.cycleSeconds,
				ts.cycleCount,
				diff);
		}
	}
	//error == FC2_ERROR_OK;
	if (error == FC2_ERROR_OK)
	{

		// Convert the final image to RGB
		error = fc2ConvertImageTo(FC2_PIXEL_FORMAT_BGR, conp->rawImage, conp->convertedImage);
		if (error != FC2_ERROR_OK)
		{
			printf("Error in fc2ConvertImageTo: %s\n", fc2ErrorToDescription(error));
			return a;
		}
		
	
	

		// Save it to PNG
	/*	printf("Saving the last image to fc2TestImage.png \n");
		error = fc2SaveImage(&convertedImage, "fc2TestImage.png", FC2_PNG);
		if (error != FC2_ERROR_OK)
		{
			printf("Error in fc2SaveImage: %s\n", fc2ErrorToDescription(error));
			printf("Please check write permissions.\n");
			return -1;
		}*/


	}


	unsigned int rowBytes = (double)(*conp->convertedImage).dataSize / (double)(*conp->convertedImage).rows;

	cv::Mat image = cv::Mat((*conp->convertedImage).rows, (*conp->convertedImage).cols, CV_8UC3, (*conp->convertedImage).pData, rowBytes);


    resize(image, image, Size(500,500));
	return image;
	}

