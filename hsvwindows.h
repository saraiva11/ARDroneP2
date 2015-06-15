#ifndef HSVWINDOWS_H
#define HSVWINDOWS_H

#include <QDialog>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QMessageBox>
#include <QTextStream>
#include <opencv2/opencv.hpp>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

namespace Ui {
class HSVWindows;
}

class HSVWindows : public QDialog
{
    Q_OBJECT

public:
    explicit HSVWindows(QWidget *parent = 0);
    ~HSVWindows();
    void receiveImage(cv::Mat image);
    void setHSV(int hH, int lH, int hS, int lS, int hV, int lV);

signals:
    void setHSVMainWindow(int hH,int lH, int hS, int lS, int hV, int lV);

private slots:
    void on_highH_slider_valueChanged(int value);
    void on_lowH_slider_valueChanged(int value);
    void on_highS_slider_valueChanged(int value);
    void on_lowS_slider_valueChanged(int value);
    void on_highV_slider_valueChanged(int value);
    void on_lowV_slider_valueChanged(int value);

    void on_pushButton_clicked();

private:
    Ui::HSVWindows *ui;

    QGraphicsScene *camera;
    QGraphicsScene *camera_threshold;

    cv::Mat matOriginal;

    //Parametros lidos;
    int highH, highS, highV;
    int lowH, lowS, lowV;
    void saveFile();
};

#endif // HSVWINDOWS_H
