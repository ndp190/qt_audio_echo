/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Wed Feb 1 21:09:37 2012
**      by: Qt User Interface Compiler version 4.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QProgressBar>
#include <QtGui/QSlider>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QProgressBar *digitalValueBar;
    QSlider *minLevelSlider;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QSlider *maxLevelSlider;
    QLabel *label_6;
    QLabel *maxLevel_Lb;
    QLabel *minLevel_Lb;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(680, 84);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        digitalValueBar = new QProgressBar(centralWidget);
        digitalValueBar->setObjectName(QString::fromUtf8("digitalValueBar"));
        digitalValueBar->setGeometry(QRect(10, 10, 660, 20));
        digitalValueBar->setValue(0);
        digitalValueBar->setTextVisible(true);
        digitalValueBar->setInvertedAppearance(false);
        minLevelSlider = new QSlider(centralWidget);
        minLevelSlider->setObjectName(QString::fromUtf8("minLevelSlider"));
        minLevelSlider->setEnabled(true);
        minLevelSlider->setGeometry(QRect(210, 40, 401, 20));
        minLevelSlider->setMaximum(100);
        minLevelSlider->setValue(10);
        minLevelSlider->setOrientation(Qt::Horizontal);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 81, 19));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(150, 40, 51, 19));
        label_2->setStyleSheet(QString::fromUtf8(""));
        label_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(620, 40, 51, 21));
        label_3->setStyleSheet(QString::fromUtf8(""));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 60, 81, 19));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(620, 60, 51, 20));
        label_5->setStyleSheet(QString::fromUtf8(""));
        label_5->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxLevelSlider = new QSlider(centralWidget);
        maxLevelSlider->setObjectName(QString::fromUtf8("maxLevelSlider"));
        maxLevelSlider->setGeometry(QRect(210, 60, 401, 20));
        maxLevelSlider->setMaximum(100);
        maxLevelSlider->setValue(100);
        maxLevelSlider->setOrientation(Qt::Horizontal);
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 60, 51, 19));
        label_6->setStyleSheet(QString::fromUtf8(""));
        label_6->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        maxLevel_Lb = new QLabel(centralWidget);
        maxLevel_Lb->setObjectName(QString::fromUtf8("maxLevel_Lb"));
        maxLevel_Lb->setGeometry(QRect(90, 60, 51, 19));
        maxLevel_Lb->setStyleSheet(QString::fromUtf8("color : #993333;"));
        maxLevel_Lb->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        minLevel_Lb = new QLabel(centralWidget);
        minLevel_Lb->setObjectName(QString::fromUtf8("minLevel_Lb"));
        minLevel_Lb->setGeometry(QRect(90, 40, 51, 19));
        minLevel_Lb->setStyleSheet(QString::fromUtf8("color : #993333;"));
        minLevel_Lb->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Audio Echo Demo", 0, QApplication::UnicodeUTF8));
        digitalValueBar->setFormat(QApplication::translate("MainWindow", "%p%", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWindow", "Min level:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "0%", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("MainWindow", "100%", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("MainWindow", "Max level:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("MainWindow", "100%", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("MainWindow", "0%", 0, QApplication::UnicodeUTF8));
        maxLevel_Lb->setText(QApplication::translate("MainWindow", "100%", 0, QApplication::UnicodeUTF8));
        minLevel_Lb->setText(QApplication::translate("MainWindow", "10%", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
