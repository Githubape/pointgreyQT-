#include "context.h"

contextmat::contextmat()
{
//����������
	context = new(fc2Context);  
	//image raw
	rawImage = new(fc2Image);   
	//imagecover
	convertedImage = new(fc2Image);  
// ��ͣ��ʼ�ؼ�init

	startorpause = 0;
//  ���״̬�ؼ� init
	camera = 0;                 
}

contextmat::~contextmat()
{
	delete context;
	delete rawImage;
	delete convertedImage;
}