#include <QtGui>
#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent){
    setupUi(this);
    centerOnScreen();
    initAudioReader();
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

void MainWindow::initAudioReader(){
    audioReader = new AudioReader(this);

    audioReader->setMinLevel(qreal(minLevelSlider->value())/100);
    audioReader->setMaxLevel(qreal(maxLevelSlider->value())/100);

    connect(audioReader, SIGNAL(levelUpdated(qreal)),
            this, SLOT(onInputLevelUpdated(qreal)));
}

void MainWindow::onInputLevelUpdated(qreal value){
    int levelValue = (int)qRound(value*100);

    if (levelValue > digitalValueBar->maximum()){
        levelValue = digitalValueBar->maximum();
    }

    digitalValueBar->setValue(levelValue);
}

void MainWindow::on_minLevelSlider_sliderMoved(int position){
    audioReader->setMinLevel(qreal(position)/100);
    minLevel_Lb->setText(QString::number(position)+"%");
}

void MainWindow::on_maxLevelSlider_sliderMoved(int position){
    audioReader->setMaxLevel(qreal(position)/100);
    maxLevel_Lb->setText(QString::number(position)+"%");
}
