#pragma once
#include "FlyCapture2_C.h"


class contextmat
{
public:
	contextmat();
	~contextmat();
public:
	fc2Context* context;  //������
	int startorpause;      //bool��ͣ
	int camera;              //���״̬
	fc2Image* rawImage;     //ͼƬraw
	fc2Image* convertedImage;   //ͼƬcover

private:


};

