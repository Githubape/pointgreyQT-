#include "context.h"

contextmat::contextmat()
{
//相机句柄参数
	context = new(fc2Context);  
	//image raw
	rawImage = new(fc2Image);   
	//imagecover
	convertedImage = new(fc2Image);  
// 暂停开始控件init

	startorpause = 0;
//  相机状态控件 init
	camera = 0;                 
}

contextmat::~contextmat()
{
	delete context;
	delete rawImage;
	delete convertedImage;
}