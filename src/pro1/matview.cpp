#include "matview.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "context.h"
#include "grab-c.h"
#include "FlyCapture2_C.h"
#include "opencv2/opencv.hpp"
#include <Qimage>
#include <QPainter>

using namespace cv;
matview::matview(QWidget *p):QOpenGLWidget(p)
{
	conp = new(contextmat);

}


matview::~matview()
{
	delete conp;
}
void matview::paintEvent(QPaintEvent *e)

{
	printf("startorpause::%d\n",conp->startorpause);
	
		

			QPainter painter;

			painter.begin(this); 	
			painter.drawImage(QPoint(0, 0), img);
			painter.end();
			printf("endcap\n");
			
		
}

void matview::SetImage(Mat mat)
{
	/* imshow("a", mat);
	waitKey(30);   */
	if (img.isNull())
	{
		uchar *buf = new uchar[width()*height() * 3];
		img = QImage(buf, width(), height(), QImage::Format_RGB888);
	}
	memcpy(img.bits(), mat.data, mat.cols*mat.rows*mat.elemSize());
	update();
}