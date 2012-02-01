#include <QtGui>

#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setupUi(this);
    centerOnScreen();
}

void MainWindow::centerOnScreen(){
    QDesktopWidget *desktop = QApplication::desktop();

    int screenWidth, width;
    int screenHeight, height;
    int x, y;
    QSize windowSize;

    screenWidth = desktop->width();
    screenHeight = desktop->height();

    windowSize = size();
    width = windowSize.width();
    height = windowSize.height();

    x = (screenWidth - width) / 2;
    y = (screenHeight - height) / 2;
    y -= 50;

    move (x, y);
}

void MainWindow::onDigitalValueUpdated(qreal value){
    this->digitalValueBar->setValue(((int)qCeil(value*100))%100);
}

void MainWindow::on_minLevelSlider_sliderMoved(int position){
    Q_UNUSED(position);
}

void MainWindow::on_maxLevelSlider_sliderMoved(int position){
    Q_UNUSED(position);
}
