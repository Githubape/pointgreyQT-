 #pragma once
#include <QtWidgets/QOpenGLWidget>  
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "context.h"
using namespace cv;
#include <Qimage>
class matview:public QOpenGLWidget
{
	Q_OBJECT

public slots:
	void SetImage(Mat);


public:
	matview(QWidget *p);
	~matview();
	void paintEvent(QPaintEvent *e);
	contextmat* conp;   
	





protected:
	QImage img;
};

