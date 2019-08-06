#pragma once
#include "context.h"
#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include <QThread>
#include <QMutex>
using namespace cv;

class Matthread:public QThread
{

	Q_OBJECT

public:
	static Matthread * Get()
	{
		printf("多线程构建\n\a");
		static Matthread vt;
		return &vt;
	}
	~Matthread();
	
	void run();
    
public slots:
	void setconp(contextmat*);
public:
	contextmat* conp;
signals:
	void ViewImage(Mat);
protected:
	Matthread();
	QMutex mutex;

};

