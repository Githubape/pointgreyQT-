/********************************************************************************
** Form generated from reading UI file 'pro1.ui'
**
** Created by: Qt User Interface Compiler version 5.13.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PRO1_H
#define UI_PRO1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>
#include "matview.h"

QT_BEGIN_NAMESPACE

class Ui_pro1Class
{
public:
    matview *openGLWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;

    void setupUi(QWidget *pro1Class)
    {
        if (pro1Class->objectName().isEmpty())
            pro1Class->setObjectName(QString::fromUtf8("pro1Class"));
        pro1Class->resize(600, 500);
        openGLWidget = new matview(pro1Class);
        openGLWidget->setObjectName(QString::fromUtf8("openGLWidget"));
        openGLWidget->setGeometry(QRect(0, 0, 500, 500));
        pushButton = new QPushButton(pro1Class);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(500, 120, 93, 28));
        pushButton_2 = new QPushButton(pro1Class);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(500, 190, 93, 28));
        pushButton_3 = new QPushButton(pro1Class);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(500, 40, 93, 28));
        pushButton_4 = new QPushButton(pro1Class);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(500, 250, 93, 28));

        retranslateUi(pro1Class);
        QObject::connect(pushButton, SIGNAL(clicked()), pro1Class, SLOT(start()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), pro1Class, SLOT(pause()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), pro1Class, SLOT(initmat()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), pro1Class, SLOT(exit()));

        QMetaObject::connectSlotsByName(pro1Class);
    } // setupUi

    void retranslateUi(QWidget *pro1Class)
    {
        pro1Class->setWindowTitle(QCoreApplication::translate("pro1Class", "pro1", nullptr));
        pushButton->setText(QCoreApplication::translate("pro1Class", "\345\274\200\345\247\213", nullptr));
        pushButton_2->setText(QCoreApplication::translate("pro1Class", "\346\232\202\345\201\234", nullptr));
        pushButton_3->setText(QCoreApplication::translate("pro1Class", "\346\211\223\345\274\200\347\233\270\346\234\272", nullptr));
        pushButton_4->setText(QCoreApplication::translate("pro1Class", "\351\200\200\345\207\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class pro1Class: public Ui_pro1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PRO1_H
