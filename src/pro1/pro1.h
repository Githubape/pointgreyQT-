#pragma once
#include <QtWidgets/QWidget>
#include "ui_pro1.h"
#include "FlyCapture2_C.h"
#include "context.h"
class pro1 : public QWidget
{
	Q_OBJECT

public:
	pro1(QWidget *parent = Q_NULLPTR);
public slots:
	// button call back
	void start();
	void pause();
	void initmat();
	void exit();
signals:
	//参数传递信号 同时启动多线程
	void transconp(contextmat *);
private:
	Ui::pro1Class ui;
};
