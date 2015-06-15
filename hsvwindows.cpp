#include "hsvwindows.h"
#include "ui_hsvwindows.h"


using namespace cv;


HSVWindows::HSVWindows(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HSVWindows)
{
    ui->setupUi(this);

    highH=179;
    highS=255;
    highV=255;
    lowH=0;
    lowS=0;
    lowV=0;

    /*GrapicsView Imagem Inicialização*/
    camera = new QGraphicsScene(this);
    ui->graphicsView->setScene(camera);

    camera_threshold = new QGraphicsScene(this);
    ui->graphicsView_2->setScene(camera_threshold);

    //Slide H
    ui->highH_slider->setRange(0,179);
    ui->highH_slider->setValue(highH);
    ui->lowH_slider->setRange(0,179);
    ui->lowH_slider->setValue(lowH);

    //Slide S
    ui->highS_slider->setRange(0,255);
    ui->highS_slider->setValue(highS);
    ui->lowS_slider->setRange(0,255);
    ui->lowS_slider->setValue(lowS);

    //Slide V
    ui->highV_slider->setRange(0,255);
    ui->highV_slider->setValue(highV);
    ui->lowV_slider->setRange(0,255);
    ui->lowV_slider->setValue(lowV);
}

HSVWindows::~HSVWindows()
{
    delete ui;
}

void HSVWindows::receiveImage(cv::Mat image)
{
    Mat matHSV, matThreshold;
    Mat matRGB; //Para o qt;
    Mat matHSV2;
    Mat matGray;


    /*Receber a imagem da outra janela*/
    matOriginal = image.clone();

    //Converter para rgb para apresentar no qt, não é necessário para o processamento
    cv::cvtColor(matOriginal, matRGB, COLOR_BGR2RGB);
    cv::cvtColor(matRGB,matGray,COLOR_RGB2GRAY);
    cv::cvtColor(matRGB,matHSV2,COLOR_RGB2HSV_FULL);

    Mat hsv[3];

    //Segmentação da imagem.
    cv::cvtColor(matOriginal,matHSV,COLOR_BGR2HSV_FULL);
    inRange(matHSV,Scalar(lowH,lowS,lowV),Scalar(highH,highS,highV),matThreshold);

    //cv::adaptiveThreshold(matOriginal,matThreshold,Scalar(lowH,lowS,lowV),Scalar(highH,highS,highV),);

    //Filter
        if(ui->checkBox_filter1->isChecked())
        {
            erode(matThreshold, matThreshold, getStructuringElement(MORPH_RECT, Size(3, 3)),Point(-1,-1),5);
            dilate( matThreshold, matThreshold, getStructuringElement(MORPH_RECT, Size(3, 3)) );

            dilate( matThreshold, matThreshold, getStructuringElement(MORPH_RECT, Size(3, 3)));
            erode(matThreshold, matThreshold, getStructuringElement(MORPH_RECT, Size(3, 3)),Point(-1,-1),5);
        }

        if(ui->checkBox_filter2->isChecked())
        {
            erode(matThreshold, matThreshold, getStructuringElement(MORPH_RECT, Size(3, 3)),Point(-1,-1),3);
            dilate( matThreshold, matThreshold, getStructuringElement(MORPH_RECT, Size(3, 3)),Point(-1,-1),5);

            dilate( matThreshold, matThreshold, getStructuringElement(MORPH_RECT, Size(3, 3)),Point(-1,-1),5);
            erode(matThreshold, matThreshold, getStructuringElement(MORPH_RECT, Size(3, 3)),Point(-1,-1),3);
        }

        if(ui->checkBox_filter3->isChecked())
        {
            erode(matThreshold, matThreshold, getStructuringElement(MORPH_RECT, Size(3, 3)));
            dilate( matThreshold, matThreshold, getStructuringElement(MORPH_RECT, Size(3, 3)));

            dilate( matThreshold, matThreshold, getStructuringElement(MORPH_RECT, Size(3, 3)));
            erode(matThreshold, matThreshold, getStructuringElement(MORPH_RECT, Size(3, 3)));
        }

        if(ui->checkBox_filter4->isChecked())
        {
            morphologyEx(matThreshold,matThreshold,MORPH_OPEN,getStructuringElement(MORPH_RECT, Size(3, 3)));
            morphologyEx(matThreshold,matThreshold,MORPH_CLOSE,getStructuringElement(MORPH_RECT, Size(3, 3)));
        }


    /*Apresentar imagem na QGraphicsView*/
    QImage qimgOriginal((uchar*)matRGB.data, matRGB.cols,matRGB.rows,matRGB.step, QImage::Format_RGB888);
    QGraphicsPixmapItem* item1 = new QGraphicsPixmapItem(QPixmap::fromImage(qimgOriginal));

    QImage qimgProcessed_thresholded((uchar*)matThreshold.data, matThreshold.cols,matThreshold.rows,matGray.step, QImage::Format_Indexed8);
    QGraphicsPixmapItem* item2 = new QGraphicsPixmapItem(QPixmap::fromImage(qimgProcessed_thresholded));


    camera->clear();
    camera->addItem(item1);
    camera_threshold->clear();
    camera_threshold->addItem(item2);
}

void HSVWindows::saveFile()
{
    /*Gravar num ficheiro*/
    QString Filename = "HSVValues.txt";
    QFile file;

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Save", "Save to "+Filename+"?",QMessageBox::Yes|QMessageBox::No);

    if(reply==QMessageBox::Yes)
    {
        QString high_H = QString::number(highH);
        QString low_H = QString::number(lowH);

        QString high_S = QString::number(highS);
        QString low_S = QString::number(lowS);

        QString high_V = QString::number(highV);
        QString low_V = QString::number(lowV);


        file.setFileName(Filename);
        if(!file.open(QIODevice::ReadWrite | QIODevice::Truncate | QIODevice::Text)){
            QMessageBox::information(0, "error", file.errorString());
        }

        QTextStream out(&file);

        out << "HMAX:"+high_H << '\n';
        out << "HMIN:"+low_H << '\n';

        out << "SMAX:"+high_S << '\n';
        out << "SMIN:"+low_S << '\n';

        out << "VMAX:"+high_V << '\n';
        out << "VMIN:"+low_V << '\n';

        file.close();
    }
    else
    {

    }
}

void HSVWindows::setHSV(int hH, int lH, int hS, int lS, int hV, int lV)
{
    highH=hH;
    lowH=lH;
    highS=hS;
    lowS=lS;
    highV=hV;
    lowV=lV;

    //Slide H
    ui->highH_slider->setRange(0,179);
    ui->highH_slider->setValue(highH);
    ui->lowH_slider->setRange(0,179);
    ui->lowH_slider->setValue(lowH);

    //Slide S
    ui->highS_slider->setRange(0,255);
    ui->highS_slider->setValue(highS);
    ui->lowS_slider->setRange(0,255);
    ui->lowS_slider->setValue(lowS);

    //Slide V
    ui->highV_slider->setRange(0,255);
    ui->highV_slider->setValue(highV);
    ui->lowV_slider->setRange(0,255);
    ui->lowV_slider->setValue(lowV);
}

void HSVWindows::on_highH_slider_valueChanged(int value)
{
    highH=value;
    ui->highH_label->setText(QString::number(highH));
    //qDebug() << highH;
}

void HSVWindows::on_lowH_slider_valueChanged(int value)
{
    lowH=value;
    ui->lowH_label->setText(QString::number(lowH));
    //qDebug() << lowH;
}

void HSVWindows::on_highS_slider_valueChanged(int value)
{
    highS=value;
    ui->highS_label->setText(QString::number(highS));
    //qDebug() << highS;
}

void HSVWindows::on_lowS_slider_valueChanged(int value)
{
    lowS=value;
    ui->lowS_label->setText(QString::number(lowS));
    //qDebug() << lowS;
}

void HSVWindows::on_highV_slider_valueChanged(int value)
{
    highV=value;
    ui->highV_label->setText(QString::number(highV));
    //qDebug() << highV;
}

void HSVWindows::on_lowV_slider_valueChanged(int value)
{
    lowV=value;
    ui->lowV_label->setText(QString::number(lowV));
    //qDebug() << lowV;
}

void HSVWindows::on_pushButton_clicked()
{
   this->saveFile();
   emit setHSVMainWindow(highH,lowH,highS,lowS,highV,lowV);
   //qDebug() << "Aqui";
   this->close();
}
