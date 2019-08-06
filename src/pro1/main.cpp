#include "pro1.h"
#include <QtWidgets/QApplication>
#include "FlyCapture2_C.h"
#include "context.h"
#include "init-c.h"
#include "shut.h"
#include "startcap-c.h"
#include "stopcap-c.h"
#include "grab-c.h"
int main(int argc, char *argv[])
{



		


	QApplication a(argc, argv);
	pro1 w;
	w.show();

	return a.exec();
}
