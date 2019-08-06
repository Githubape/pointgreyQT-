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
//��ʾ����
//���߳̿���ѭ�� ���߳�ʵ������ʾ
	qRegisterMetaType<Mat>("Mat");       
	QObject::connect(Matthread::Get(),
		SIGNAL(ViewImage(Mat)),
		ui.openGLWidget,
		SLOT(SetImage(Mat))
	);
//ʵ�������̲߳�������
	qRegisterMetaType<contextmat>("contexmat");
	QObject::connect(this,
		SIGNAL(transconp(contextmat*)),
		Matthread::Get(),
		SLOT(setconp(contextmat*))
	);

}
// ��ʼ button callback
void pro1::start()
{
	   printf("********************��ʼ********************\n");

		ui.openGLWidget->conp->startorpause = 1;
		
		printf("********************��ʼ********************\n");

	
}
//ֹͣ button callback
void pro1:: pause()
{
	printf("********************ֹͣ********************\n");
	ui.openGLWidget->conp->startorpause = 0;
	printf("********************ֹͣ********************\n");

}
//�����button callback
void pro1::initmat()
{
	printf("********************�����********************\n");
	//�����ʼ��
	init(ui.openGLWidget->conp);
	//��ʼ
	startcap(*(ui.openGLWidget->conp->context));
	//��ʼ���ؼ�
	ui.openGLWidget->conp->camera = 1;
	ui.openGLWidget->conp->startorpause = 0;
	//���ݿ���ģ��
	transconp(ui.openGLWidget->conp);
	printf("********************�����********************\n");

}
// �ر� button callback
void pro1::exit()
{
	printf("********************�ر����********************\n");
	//�������Ʋ���
	ui.openGLWidget->conp->camera = 0;
	ui.openGLWidget->conp->startorpause = 0;
	//stopcap
	stopcap(*(ui.openGLWidget->conp->context));

	//�ر����
	shut(ui.openGLWidget->conp);

	printf("********************�ر����********************\n");

}