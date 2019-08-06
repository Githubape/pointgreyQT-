
#include "opencv2/opencv.hpp"
#include "pch.h"
//#include <iostream>
#if defined(_WIN32) || defined(_WIN64)
#define _CRT_SECURE_NO_WARNINGS
#endif

#include "FlyCapture2_C.h"
#include <stdio.h>
#include<math.h>
#include "init-c.h"
#include "shut.h"
#include "startcap-c.h"
#include "stopcap-c.h"
#include "grab-c.h"
//using namespace cv;
int main()
{
     fc2Context context=new(fc2Context);
	printf("c1::%d\n", context);
	unsigned int * b = (unsigned int *)context;
	printf("*c1::%d\n", *b);
	//相机初始化
	context=init();
	printf("c2::%d\n", context);
	unsigned int * c = (unsigned int *)context;
	printf("*c2::%d\n",*c);
	//开始
	 startcap(context);
	 printf("c3::%d\n", context);
	 unsigned int * d = (unsigned int *)context;
	 printf("*c3::%d\n", *d);
	 //捕获
	 grab(context);
	 printf("c4::%d\n", context);
	 unsigned int * e = (unsigned int *)context;
	 printf("*c4::%d\n", *e);
	 //停止
	 stopcap(context);
	
	//关闭相机
	shut(context);

	return 0;
//	delete(context);
}

