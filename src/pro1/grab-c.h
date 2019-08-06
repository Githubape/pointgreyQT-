#pragma once
#include "FlyCapture2_C.h"
#include "opencv2/opencv.hpp"
#include "context.h"
using namespace cv;
void SetTimeStamping(fc2Context context, BOOL enableTimeStamp);
cv::Mat GrabImages(contextmat *conp, int numImagesToGrab);
//Mat grab(fc2Context context);
Mat grab0();