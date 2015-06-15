#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <QKeyEvent>
#include <QPoint>
#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include "ardrone/ardrone.h"
#include "qcompass.h"
#include "qadi.h"
#include "hsvwindows.h"
#include "gamepad.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QTimer *timer;
    QTimer *timer2;
    //Parametros lidos;
    int highH, highS, highV;
    int lowH, lowS, lowV;
    bool cameraPC = false;

public slots:
     void setHSV(int hH,int lH, int hS, int lS, int hV, int lV);
     void readJoystick(QVector<int16_t> values);

private:
    Ui::MainWindow *ui;
    cv::VideoCapture capWebcam;


    QCompass *compass;
    QAdi *adi;
    HSVWindows *hsvwindows;
    Gamepad *pad;
    ARDrone ardrone;

    cv::Mat matOriginal;
    cv::Mat matRGB;
    //QImage qimgOriginal;

    /*GraphicsScenes*/
    QGraphicsScene *flighIntrument_compass;
    QGraphicsScene *flighIntrument_ADI;
    QGraphicsScene *connect_indicator;
    QGraphicsScene *camera;
    void readFileHSV();
    int ConverterLineToint(QString line);
    void Move(double vx, double vy, double vz, double vr);
    void keyPressEvent(QKeyEvent *event);
    //void followMode(QPoint centroide);

private slots:
    cv::Mat OurVisonAlgorithm();
    void processFrameAndUpdateGUI();
    void getBatteryPercentage();

    /*Eventos Butões*/
    void on_bt_connect_clicked();
    void on_bt_Disconnect_clicked();
    void on_bt_hsv_segmentation_clicked();
    void on_pushButton_2_clicked();
    void on_bt_takeoff_2_clicked();
    void on_bt_landing_2_clicked();
    void on_bt_emergency_2_clicked();
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();
};

#endif // MAINWINDOW_H
