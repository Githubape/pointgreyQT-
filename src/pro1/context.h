#pragma once
#include "FlyCapture2_C.h"


class contextmat
{
public:
	contextmat();
	~contextmat();
public:
	fc2Context* context;  //Ïà»ú¾ä±ú
	int startorpause;      //boolÔÝÍ£
	int camera;              //Ïà»ú×´Ì¬
	fc2Image* rawImage;     //Í¼Æ¬raw
	fc2Image* convertedImage;   //Í¼Æ¬cover

private:


};

