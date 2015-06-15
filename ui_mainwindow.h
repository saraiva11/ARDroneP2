/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_4;
    QPushButton *bt_takeoff_2;
    QPushButton *bt_landing_2;
    QPushButton *bt_emergency_2;
    QPushButton *bt_Disconnect;
    QGraphicsView *graphicsView_indicator;
    QPushButton *bt_connect;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_ball;
    QLabel *label_battery_2;
    QLabel *label;
    QPushButton *pushButton;
    QLabel *label_2;
    QPushButton *pushButton_3;
    QGroupBox *groupBox;
    QCheckBox *checkBox_cameraF;
    QCheckBox *checkBox_cameraD;
    QCheckBox *checkBox_th_image;
    QGroupBox *groupBox_2;
    QCheckBox *checkBox_4;
    QCheckBox *checkBox_5;
    QPushButton *bt_hsv_segmentation;
    QPushButton *pushButton_2;
    QCheckBox *checkBox_6;
    QCheckBox *checkBox_filter;
    QCheckBox *checkBox_filter1;
    QCheckBox *checkBox_filter2;
    QCheckBox *checkBox_filter3;
    QCheckBox *checkBox_filter4;
    QGraphicsView *graphicsView_adi;
    QGraphicsView *graphicsView_image;
    QGraphicsView *graphicsView_compass;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 765);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        groupBox_4->setGeometry(QRect(670, 20, 341, 231));
        bt_takeoff_2 = new QPushButton(groupBox_4);
        bt_takeoff_2->setObjectName(QStringLiteral("bt_takeoff_2"));
        bt_takeoff_2->setGeometry(QRect(10, 140, 99, 27));
        bt_landing_2 = new QPushButton(groupBox_4);
        bt_landing_2->setObjectName(QStringLiteral("bt_landing_2"));
        bt_landing_2->setGeometry(QRect(110, 140, 99, 27));
        bt_emergency_2 = new QPushButton(groupBox_4);
        bt_emergency_2->setObjectName(QStringLiteral("bt_emergency_2"));
        bt_emergency_2->setGeometry(QRect(210, 140, 99, 27));
        bt_Disconnect = new QPushButton(groupBox_4);
        bt_Disconnect->setObjectName(QStringLiteral("bt_Disconnect"));
        bt_Disconnect->setGeometry(QRect(20, 80, 99, 27));
        graphicsView_indicator = new QGraphicsView(groupBox_4);
        graphicsView_indicator->setObjectName(QStringLiteral("graphicsView_indicator"));
        graphicsView_indicator->setGeometry(QRect(160, 59, 41, 41));
        graphicsView_indicator->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_indicator->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        bt_connect = new QPushButton(groupBox_4);
        bt_connect->setObjectName(QStringLiteral("bt_connect"));
        bt_connect->setGeometry(QRect(20, 40, 99, 27));
        checkBox_3 = new QCheckBox(groupBox_4);
        checkBox_3->setObjectName(QStringLiteral("checkBox_3"));
        checkBox_3->setGeometry(QRect(20, 190, 121, 22));
        checkBox_ball = new QCheckBox(groupBox_4);
        checkBox_ball->setObjectName(QStringLiteral("checkBox_ball"));
        checkBox_ball->setGeometry(QRect(150, 190, 131, 22));
        label_battery_2 = new QLabel(groupBox_4);
        label_battery_2->setObjectName(QStringLiteral("label_battery_2"));
        label_battery_2->setGeometry(QRect(170, 60, 41, 31));
        QFont font;
        font.setPointSize(15);
        label_battery_2->setFont(font);
        label = new QLabel(groupBox_4);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 40, 67, 17));
        pushButton = new QPushButton(groupBox_4);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(220, 40, 121, 27));
        label_2 = new QLabel(groupBox_4);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(220, 10, 81, 17));
        pushButton_3 = new QPushButton(groupBox_4);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(220, 70, 121, 27));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(670, 270, 321, 111));
        checkBox_cameraF = new QCheckBox(groupBox);
        checkBox_cameraF->setObjectName(QStringLiteral("checkBox_cameraF"));
        checkBox_cameraF->setGeometry(QRect(20, 30, 141, 22));
        checkBox_cameraD = new QCheckBox(groupBox);
        checkBox_cameraD->setObjectName(QStringLiteral("checkBox_cameraD"));
        checkBox_cameraD->setGeometry(QRect(20, 70, 151, 22));
        checkBox_th_image = new QCheckBox(groupBox);
        checkBox_th_image->setObjectName(QStringLiteral("checkBox_th_image"));
        checkBox_th_image->setGeometry(QRect(180, 30, 161, 22));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(680, 400, 321, 291));
        checkBox_4 = new QCheckBox(groupBox_2);
        checkBox_4->setObjectName(QStringLiteral("checkBox_4"));
        checkBox_4->setGeometry(QRect(20, 30, 141, 22));
        checkBox_5 = new QCheckBox(groupBox_2);
        checkBox_5->setObjectName(QStringLiteral("checkBox_5"));
        checkBox_5->setGeometry(QRect(20, 70, 151, 22));
        bt_hsv_segmentation = new QPushButton(groupBox_2);
        bt_hsv_segmentation->setObjectName(QStringLiteral("bt_hsv_segmentation"));
        bt_hsv_segmentation->setGeometry(QRect(140, 30, 141, 27));
        pushButton_2 = new QPushButton(groupBox_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(170, 70, 111, 27));
        checkBox_6 = new QCheckBox(groupBox_2);
        checkBox_6->setObjectName(QStringLiteral("checkBox_6"));
        checkBox_6->setGeometry(QRect(180, 150, 121, 22));
        checkBox_filter = new QCheckBox(groupBox_2);
        checkBox_filter->setObjectName(QStringLiteral("checkBox_filter"));
        checkBox_filter->setGeometry(QRect(180, 180, 111, 22));
        checkBox_filter1 = new QCheckBox(groupBox_2);
        checkBox_filter1->setObjectName(QStringLiteral("checkBox_filter1"));
        checkBox_filter1->setGeometry(QRect(20, 150, 97, 22));
        checkBox_filter2 = new QCheckBox(groupBox_2);
        checkBox_filter2->setObjectName(QStringLiteral("checkBox_filter2"));
        checkBox_filter2->setGeometry(QRect(20, 180, 97, 22));
        checkBox_filter3 = new QCheckBox(groupBox_2);
        checkBox_filter3->setObjectName(QStringLiteral("checkBox_filter3"));
        checkBox_filter3->setGeometry(QRect(20, 210, 97, 22));
        checkBox_filter4 = new QCheckBox(groupBox_2);
        checkBox_filter4->setObjectName(QStringLiteral("checkBox_filter4"));
        checkBox_filter4->setGeometry(QRect(20, 240, 97, 22));
        graphicsView_adi = new QGraphicsView(centralWidget);
        graphicsView_adi->setObjectName(QStringLiteral("graphicsView_adi"));
        graphicsView_adi->setGeometry(QRect(400, 430, 252, 252));
        graphicsView_adi->setStyleSheet(QStringLiteral("border:none;"));
        graphicsView_adi->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_adi->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_image = new QGraphicsView(centralWidget);
        graphicsView_image->setObjectName(QStringLiteral("graphicsView_image"));
        graphicsView_image->setEnabled(true);
        graphicsView_image->setGeometry(QRect(10, 20, 640, 360));
        graphicsView_image->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_image->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_compass = new QGraphicsView(centralWidget);
        graphicsView_compass->setObjectName(QStringLiteral("graphicsView_compass"));
        graphicsView_compass->setGeometry(QRect(10, 430, 252, 252));
        graphicsView_compass->setStyleSheet(QStringLiteral("border:none;"));
        graphicsView_compass->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_compass->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        groupBox_4->setTitle(QApplication::translate("MainWindow", "ARDrone Parameters:", 0));
        bt_takeoff_2->setText(QApplication::translate("MainWindow", "Take Off", 0));
        bt_landing_2->setText(QApplication::translate("MainWindow", "Landing", 0));
        bt_emergency_2->setText(QApplication::translate("MainWindow", "Emergency", 0));
        bt_Disconnect->setText(QApplication::translate("MainWindow", "Disconnect", 0));
        bt_connect->setText(QApplication::translate("MainWindow", "Connect", 0));
        checkBox_3->setText(QApplication::translate("MainWindow", "Follow Mode", 0));
        checkBox_ball->setText(QApplication::translate("MainWindow", "Detect Ball", 0));
        label_battery_2->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Battery:", 0));
        pushButton->setText(QApplication::translate("MainWindow", "FlatTrim", 0));
        label_2->setText(QApplication::translate("MainWindow", "Calibration:", 0));
        pushButton_3->setText(QApplication::translate("MainWindow", "Magnetometer", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Camera", 0));
        checkBox_cameraF->setText(QApplication::translate("MainWindow", "Camera Frontal", 0));
        checkBox_cameraD->setText(QApplication::translate("MainWindow", "Camera Inferior", 0));
        checkBox_th_image->setText(QApplication::translate("MainWindow", "Threshold Image", 0));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Vision Algorithms", 0));
        checkBox_4->setText(QApplication::translate("MainWindow", "HSV", 0));
        checkBox_5->setText(QApplication::translate("MainWindow", "YUV", 0));
        bt_hsv_segmentation->setText(QApplication::translate("MainWindow", "HSV Segmentation", 0));
        pushButton_2->setText(QApplication::translate("MainWindow", "Segmentation", 0));
        checkBox_6->setText(QApplication::translate("MainWindow", "Kalman Filter", 0));
        checkBox_filter->setText(QApplication::translate("MainWindow", "Noise Filter", 0));
        checkBox_filter1->setText(QApplication::translate("MainWindow", "Filter 1", 0));
        checkBox_filter2->setText(QApplication::translate("MainWindow", "Filter 2", 0));
        checkBox_filter3->setText(QApplication::translate("MainWindow", "Filter 3", 0));
        checkBox_filter4->setText(QApplication::translate("MainWindow", "Filter 4", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
