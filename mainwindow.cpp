#include "mainwindow.h"
#include "ui_mainwindow.h"


using namespace cv;
bool connected = false;
bool hsvSegmentation=false;


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->bt_Disconnect->setDisabled(true);

    this->readFileHSV();

    /*Inicialização GraphicsView FlightInstruments*/
    flighIntrument_compass = new QGraphicsScene(this);
    flighIntrument_ADI = new QGraphicsScene(this);
    connect_indicator = new QGraphicsScene(this);

    flighIntrument_compass->setSceneRect(0,0,250,250);
    flighIntrument_ADI->setSceneRect(0,0,250,250);
    connect_indicator->setSceneRect(0,0,70,70);


    ui->graphicsView_compass->setScene(flighIntrument_compass);
    ui->graphicsView_compass->setStyleSheet("background: transparent; border: transparent;");

    ui->graphicsView_adi->setStyleSheet("background: transparent; border: transparent;");
    ui->graphicsView_adi->setScene(flighIntrument_ADI);

    ui->graphicsView_indicator->setScene(connect_indicator);
    ui->graphicsView_indicator->setBackgroundBrush(Qt::red);


    ui->graphicsView_image->setStyleSheet("background: transparent");


    compass = new QCompass();
    adi = new QAdi();

    flighIntrument_compass->addItem(compass);
    flighIntrument_ADI->addItem(adi);

    /*GrapicsView Imagem Inicialização*/
    camera = new QGraphicsScene(this);
    ui->graphicsView_image->setScene(camera);

    //compass->setYaw(30);

    /*Inicialização Gamepad*/
    pad = new Gamepad();
    pad->openJoystick();
    connect(pad, SIGNAL(sendJoystick(QVector<int16_t>)),this,SLOT(readJoystick(QVector<int16_t>)));
    //compass->setYaw(330);
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Nosso algoritmo
cv::Mat MainWindow::OurVisonAlgorithm()
{
    Mat matHSV;
    Mat matThreshold;


    //Algoritmo de Processamento de Imagem
    cv::cvtColor(matOriginal,matHSV,COLOR_BGR2HSV_FULL);
    inRange(matHSV,Scalar(lowH,lowS,lowV),Scalar(highH,highS,highV),matThreshold);

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

    return matThreshold;
}

void MainWindow::processFrameAndUpdateGUI()
{
    Mat matThreshold;
    Mat matHSV2;
    Mat matGray;
    QGraphicsPixmapItem* item1, *item2;
    double positionX,positionY;

    compass->setAlt(10);

    if(connected)
    {
        //t.start();
        if(cameraPC==true)
        {
           capWebcam.read(matOriginal);
           Size size(640,360);
           cv::resize(matOriginal,matOriginal,size);

        }
        else
        {
            if(ui->checkBox_cameraF->isChecked())
            {
                ardrone.setCamera(0);
            }
            else if(ui->checkBox_cameraD->isChecked())
            {
                ardrone.setCamera(1);
            }

            /*Recebe Imagem do ARDrone*/
            matOriginal = ardrone.getImage();
        }

        if(hsvSegmentation)
        {
            hsvwindows->receiveImage(matOriginal);
        }

        //Converter para rgb para apresentar no qt, não é necessário para o processamento
        cv::cvtColor(matOriginal, matRGB, COLOR_BGR2RGB);
        cv::cvtColor(matRGB,matGray,COLOR_RGB2GRAY);
        cv::cvtColor(matRGB,matHSV2,COLOR_RGB2HSV_FULL);

        //Algoritmo de Processamento de Imagem
        matThreshold=OurVisonAlgorithm();

         //Detect contours
         std::vector<std::vector<cv::Point> > contours;
         cv::findContours(matThreshold.clone(), contours, cv::RETR_CCOMP, cv::CHAIN_APPROX_SIMPLE);
         vector<Vec4i> hierarchy;

      // Find largest contour
      int contour_index = -1;
      int i;
      double max_area = 0.0;

      /*for (i = 0; i < contours.size(); i++)
      {
          double area = fabs(cv::contourArea(contours[i]));
          if (area > max_area)
          {
              contour_index = i;
              max_area = area;
          }
       }*/

       /*if (contour_index >= 0){
           Moments oMoments = cv::moments(contours[contour_index], true);

           double dM01 = oMoments.m01;
           double dM10 = oMoments.m10;
           double area = oMoments.m00;

           if(contour_index >= 0)
           {
              positionX = dM10 / area;
              positionY = dM01 / area;
           }
       }*/

        /*if(ui->checkBox_ball->isChecked())
        {
           if (contour_index >= 0) {

             //Apresentar linhas na imagem
             cv::circle(matRGB,Point(positionX,positionY),10,Scalar(0,255,0),2);
             cv::line(matRGB,Point(positionX,0),Point(positionX,360),Scalar(0,255,0),2);
             cv::line(matRGB,Point(0,positionY),Point(640,positionY),Scalar(0,255,0),2);

                //cv::drawContours( matRGB, contours, contour_index, Qt::red, 2, 8, hierarchy, 0, Point() );

             cv::Rect rect = cv::boundingRect(contours[contour_index]);
             cv::rectangle(matRGB, rect, cv::Scalar(0, 255, 0));
            }

           //cv::arrowedLine(matRGB,Point(320,170),Point(320,150),Scalar(0,255,0),2,8,0,0.6);
        }*/

        /*Imagem a apresentar*/
        if(ui->checkBox_th_image->isChecked())
        {
            /*Apresentar imagem na QGraphicsView*/
            QImage qimgProcessed_thresholded((uchar*)matThreshold.data, matThreshold.cols,matThreshold.rows,matGray.step, QImage::Format_Indexed8);
            item2 = new QGraphicsPixmapItem(QPixmap::fromImage(qimgProcessed_thresholded));

            camera->clear();
            camera->addItem(item2);
        }
        else
        {
            /*Apresentar imagem na QGraphicsView*/
            QImage qimgOriginal((uchar*)matRGB.data, matRGB.cols,matRGB.rows,matRGB.step, QImage::Format_RGB888);
            item1 = new QGraphicsPixmapItem(QPixmap::fromImage(qimgOriginal));

            camera->clear();
            camera->addItem(item1);
        }

        /*if(ui->checkBox_3->isChecked())
        {
            QPoint centroide;

            centroide.setX(positionX);
            centroide.setY(positionY);

            this->followMode(centroide);
        }*/
    }
}

/*void MainWindow::followMode(QPoint centroide)
{
    qDebug() << "X:" << centroide.x() << "Y:" << centroide.y();
    double vz=0,vr=0, vx=0,vy=0;
    int k1=0.5;
    int k2=0.3;

    /*Velocidade para controlar a altura do drone*/
    //vz = k1 * ((centroide.y()-(360-centroide.y()))/360);

    /*Permite rodar o drone para a esquerda e para a direita*/
    //vr = k2 * ((centroide.x()-(640-centroide.x()))/640);


    //this->Move(vx,vy,vz,vr);

//}

void MainWindow::readFileHSV()
{
    /*Ler Parametros HSV*/
    QString Filename = "HSVValues.txt";
    QFile file;


    file.setFileName(Filename);
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug()<<"Erro: "<<file.errorString();
        highH=179;
        highS=255;
        highV=255;
        lowH=0;
        lowS=0;
        lowV=0;
        return;
    }

    QTextStream in(&file);
    int i=0;

    while(!in.atEnd())
    {
        QString line = in.readLine();
        i++;

        //qDebug() <<"i:" <<i<<line;

        switch(i)
        {
        case 1:
            highH = ConverterLineToint(line);
            //qDebug() << highH;
            break;
        case 2:
            lowH = ConverterLineToint(line);
            //qDebug() << lowH;
            break;
        case 3:
            highS = ConverterLineToint(line);
            //qDebug() << highS;
            break;
        case 4:
            lowS = ConverterLineToint(line);
            //qDebug() << lowS;
            break;
        case 5:
            highV = ConverterLineToint(line);
            //qDebug() << highV;
            break;
        case 6:
            lowV = ConverterLineToint(line);
            //qDebug() << lowV;
            break;
        default:
             //qDebug()<<"Parametro não existe";
             break;
        }
    }
    file.close();
}

int MainWindow::ConverterLineToint(QString line)
{
    line.remove(0,line.indexOf(":")+1);
    int value = line.toInt();

    //qDebug() << "Value:"<<value;
    return value;
}

void MainWindow::Move(double vx, double vy, double vz, double vr)
{
    ardrone.move3D(vx, vy, vz, vr);
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    double vx = 0.0, vy = 0.0, vz = 0.0, vr = 0.0;

    switch ( event->key() )
        {
            case Qt::Key_W:
                qDebug() << "UP";
                vz =  1.0;
                this->Move(vx,vy,vz,vr);
                break;
            case Qt::Key_S:
                qDebug() << "DOWN";
                vz =  -1.0;
                this->Move(vx,vy,vz,vr);
                break;
            case Qt::Key_A:
                qDebug() << "LEFT";
                vy =  1.0;
                this->Move(vx,vy,vz,vr);
                break;
            case Qt::Key_D:
                qDebug() << "RIGHT";
                vy =  -1.0;
                this->Move(vx,vy,vz,vr);
                break;
            case Qt::Key_T:
                qDebug() << "Takeoff";
                ardrone.takeoff();
                break;
            case Qt::Key_L:
                qDebug() << "Landing";
                ardrone.landing();
                break;
            case Qt::Key_E:
                qDebug() << "Emergency";
                ardrone.emergency();
                 break;
            default:
                qDebug() << event->key() << endl;
                break;
        }

}

void MainWindow::getBatteryPercentage()
{
    double battery;

    battery = ardrone.getBatteryPercentage();

    //qDebug() << "Battery Percentage:" << ardrone.getBatteryPercentage();
    ui->label_battery_2->setText(QString::number(battery));
}

void MainWindow::on_bt_connect_clicked()
{
    ui->bt_Disconnect->setEnabled(true);
    ui->bt_connect->setDisabled(true);

    if (!ardrone.open()) {
        qDebug() << "Failed to initialize ARDrone";

        capWebcam.open(0);
        if(capWebcam.isOpened()==false)
        {
            qDebug() << "Failed to initialize pc webcam";
            return;
        }
        cameraPC = true;
    }
    else
    {
        cameraPC = false;
    }

    //pad->openJoystick();


    this->getBatteryPercentage();


    timer = new QTimer(this);
    timer2 = new QTimer(this);

    connect(timer, SIGNAL(timeout()),this,SLOT(processFrameAndUpdateGUI()));
    connect(timer2, SIGNAL(timeout()),this,SLOT(getBatteryPercentage()));
    //connect(pad, SIGNAL(sendJoystick(int16_t[])),this,SLOT(readJoystick(int16_t[])));

    timer->start(1);
    timer2->start(300);

    connected = true;


    //Função iniciar comunicação com o ARDrone
    ui->graphicsView_indicator->setBackgroundBrush(Qt::green);
}

void MainWindow::setHSV(int hH, int lH, int hS, int lS, int hV, int lV)
{
   hsvSegmentation = false;

    highH = hH;
    lowH = lH;
    //qDebug() << "HighH:" << highH << "LowH:" << lowH;

    highS = hS;
    lowS = lS;
    //qDebug() << "HighS:" << highS << "LowS:" << lowH;

    highV = hV;
    lowV = lV;
    //qDebug() << "HighV:" << highV << "LowV:" << lowV;


}

void MainWindow::readJoystick(QVector<int16_t> values)
{
    int i;
    double vx = 0.0, vy = 0.0, vz = 0.0, vr = 0.0;

    if(values.at(0)==1)
    {
        cv::imwrite("Image.jpg",matOriginal);
        qDebug() << "Image Saved";
    }
    else if(values.at(1)==1)
    {
        vz= -1.0;
        this->Move(vx,vy,vz,vr);
    }
    else if(values.at(3)==1)
    {
        vz= 1.0;
        this->Move(vx,vy,vz,vr);
    }
    else if(values.at(4)==1)
    {
        ardrone.landing();
    }
    else if(values.at(5)==1)
    {
        ardrone.takeoff();
    }
    else if(values.at(6)==1)
    {
        vr=1.0;
        this->Move(vx,vy,vz,vr);
    }
    else if(values.at(7)==1)
    {
        vr=-1.0;
        this->Move(vx,vy,vz,vr);
    }
    else if(values.at(9)==1)
    {
        ardrone.emergency();
    }
    else if(values.at(11)==32767) //direita
    {
        //qDebug() << "Para a Direita";
        vy=-1.0;
        this->Move(vx,vy,vz,vr);
    }
    else if(values.at(11)==-32768) //esquera
    {
        //qDebug() << "Para a Esquerda";
        vy=1.0;
        this->Move(vx,vy,vz,vr);
    }
    else if(values.at(12)==32767) //baixo
    {
        //qDebug() << "Para trás";
        vx=-1.0;
        this->Move(vx,vy,vz,vr);
    }
    else if(values.at(12)==-32768) //cima
    {
        //qDebug() << "Para frente";
        vx=1.0;
         this->Move(vx,vy,vz,vr);
    }

    qDebug() << "Vx:" << vx << "Vy:" << vy << "Vz:" << vz << "Vr:" << vr;
    //this->Move(vx,vy,vz,vr);
    //ardrone.move(vx,vy,vr);
}

void MainWindow::on_bt_Disconnect_clicked()
{
    connected = false;
    ui->bt_Disconnect->setDisabled(true);
    ui->bt_connect->setEnabled(true);

    //Desligar Comunicação com o ARDrone
    ui->graphicsView_indicator->setBackgroundBrush(Qt::red);
}

void MainWindow::on_bt_hsv_segmentation_clicked()
{
    hsvSegmentation = true;

    //HSVWindows hsvwindows;
    //hsvwindows.setModal(true);
    //hsvwindows.receiveImage(matOriginal);
    //hsvwindows.exec();

    hsvwindows = new HSVWindows(this);
    hsvwindows->setHSV(highH,lowH,highS,lowS,highV,lowV);
    connect(hsvwindows, SIGNAL(setHSVMainWindow(int,int,int,int,int,int)),this,SLOT(setHSV(int,int,int,int,int,int)));

    hsvwindows->show();


}

void MainWindow::on_pushButton_2_clicked()
{
    //qDebug() << "HighH:" << highH << "LowH:" << lowH;
    //qDebug() << "HighS:" << highS << "LowS:" << lowS;
    //qDebug() << "HighV:" << highV << "LowV:" << lowV;

    ardrone.setFlatTrim();
}

void MainWindow::on_bt_takeoff_2_clicked()
{
    ardrone.takeoff();
}

void MainWindow::on_bt_landing_2_clicked()
{
    ardrone.landing();
}

void MainWindow::on_bt_emergency_2_clicked()
{
    ardrone.emergency();
}


/*Calibração FlatTrim*/
void MainWindow::on_pushButton_clicked()
{
    ardrone.setFlatTrim();
}

/*Calibração Magnetometer*/
void MainWindow::on_pushButton_3_clicked()
{
    ardrone.setCalibration(0);
}
