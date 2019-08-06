#include "pro1.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/opencv.hpp"

#include "FlyCapture2_C.h"
#include "context.h"
#include "init-c.h"
#include "startcap-c.h"
#include "stopcap-c.h"
#include "shut.h"
#include "grab-c.h"
#include <Qimage>
#include <QPainter>
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "Matthread.h"
using namespace cv;

pro1::pro1(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);
//显示连接
//此线程控制循环 主线程实例化显示
	qRegisterMetaType<Mat>("Mat");       
	QObject::connect(Matthread::Get(),
		SIGNAL(ViewImage(Mat)),
		ui.openGLWidget,
		SLOT(SetImage(Mat))
	);
//实现主次线程参数传递
	qRegisterMetaType<contextmat>("contexmat");
	QObject::connect(this,
		SIGNAL(transconp(contextmat*)),
		Matthread::Get(),
		SLOT(setconp(contextmat*))
	);

}
// 开始 button callback
void pro1::start()
{
	   printf("********************开始********************\n");

		ui.openGLWidget->conp->startorpause = 1;
		
		printf("********************开始********************\n");

	
}
//停止 button callback
void pro1:: pause()
{
	printf("********************停止********************\n");
	ui.openGLWidget->conp->startorpause = 0;
	printf("********************停止********************\n");

}
//打开箱机button callback
void pro1::initmat()
{
	printf("********************打开相机********************\n");
	//相机初始化
	init(ui.openGLWidget->conp);
	//开始
	startcap(*(ui.openGLWidget->conp->context));
	//初始化控件
	ui.openGLWidget->conp->camera = 1;
	ui.openGLWidget->conp->startorpause = 0;
	//传递控制模块
	transconp(ui.openGLWidget->conp);
	printf("********************打开相机********************\n");

}
// 关闭 button callback
void pro1::exit()
{
	printf("********************关闭相机********************\n");
	//锁定控制参数
	ui.openGLWidget->conp->camera = 0;
	ui.openGLWidget->conp->startorpause = 0;
	//stopcap
	stopcap(*(ui.openGLWidget->conp->context));

	//关闭相机
	shut(ui.openGLWidget->conp);

	printf("********************关闭相机********************\n");

}