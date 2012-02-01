#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "ui_mainwindow.h"

class MainWindow : public QMainWindow, private Ui::MainWindow {
    Q_OBJECT

public slots:
    void onDigitalValueUpdated(qreal value);
    
public:
    explicit MainWindow(QWidget *parent = 0);
    
private slots:
    void on_minLevelSlider_sliderMoved(int position);

    void on_maxLevelSlider_sliderMoved(int position);

private:
    void centerOnScreen();
};

#endif // MAINWINDOW_H
