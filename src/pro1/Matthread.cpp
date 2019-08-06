#include "Matthread.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "grab-c.h"
#include "dealmat.h"
#include "context.h"
using namespace cv;


Matthread::Matthread()
{
	//start();
}


Matthread::~Matthread()
{
	delete conp;
}

void Matthread::run()
{
	printf("������߳�\n\a");
	Mat mat(500, 500, CV_8UC3);

	VideoCapture cap;
	cap.open(1);    

	while (conp->camera) {
		if (conp->startorpause)
		{
			printf("mat\n");

			mat=  GrabImages(conp, 1);//���ò���������mat
			
			cap >> mat;
		/*
			imshow("d", mat);
			waitKey(30);  */
			cvtColor(mat, mat, COLOR_BGR2RGB);
			//mat = dealwmat(mat);  //����ͼ��
			ViewImage(mat);
			
			msleep(40);
		}
	}
	printf("���߳̽���\n\a");
}

void Matthread::setconp(contextmat *con)
{
	conp = con;
	start();
	printf("���߳̿�ʼ\n\a");
}
