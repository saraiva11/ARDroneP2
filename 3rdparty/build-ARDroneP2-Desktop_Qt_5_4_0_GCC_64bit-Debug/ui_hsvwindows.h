/********************************************************************************
** Form generated from reading UI file 'hsvwindows.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HSVWINDOWS_H
#define UI_HSVWINDOWS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HSVWindows
{
public:
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_11;
    QGraphicsView *graphicsView_2;
    QGraphicsView *graphicsView;
    QGroupBox *groupBox;
    QWidget *gridLayoutWidget_5;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_10;
    QLabel *label_4;
    QHBoxLayout *horizontalLayout_3;
    QSlider *highH_slider;
    QLabel *highH_label;
    QHBoxLayout *horizontalLayout_2;
    QSlider *lowH_slider;
    QLabel *lowH_label;
    QGridLayout *gridLayout_9;
    QLabel *label;
    QSpacerItem *verticalSpacer_5;
    QGridLayout *gridLayout_8;
    QGridLayout *gridLayout_14;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_6;
    QSlider *highV_slider;
    QLabel *highV_label;
    QGridLayout *gridLayout_15;
    QLabel *label_7;
    QHBoxLayout *horizontalLayout_7;
    QSlider *lowV_slider;
    QLabel *lowV_label;
    QSpacerItem *verticalSpacer_6;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_4;
    QGridLayout *gridLayout_13;
    QLabel *label_6;
    QHBoxLayout *horizontalLayout_4;
    QSlider *highS_slider;
    QLabel *highS_label;
    QGridLayout *gridLayout_12;
    QLabel *label_12;
    QHBoxLayout *horizontalLayout_5;
    QSlider *lowS_slider;
    QLabel *lowS_label;
    QSpacerItem *verticalSpacer_4;
    QLabel *x_position;
    QLabel *y_position_2;
    QLabel *time_label;
    QPushButton *pushButton;

    void setupUi(QDialog *HSVWindows)
    {
        if (HSVWindows->objectName().isEmpty())
            HSVWindows->setObjectName(QStringLiteral("HSVWindows"));
        HSVWindows->resize(1316, 623);
        groupBox_2 = new QGroupBox(HSVWindows);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(0, 10, 1371, 895));
        gridLayoutWidget = new QWidget(groupBox_2);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(0, 30, 1301, 391));
        gridLayout_11 = new QGridLayout(gridLayoutWidget);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        gridLayout_11->setContentsMargins(0, 0, 0, 0);
        graphicsView_2 = new QGraphicsView(gridLayoutWidget);
        graphicsView_2->setObjectName(QStringLiteral("graphicsView_2"));
        graphicsView_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_11->addWidget(graphicsView_2, 0, 1, 1, 1);

        graphicsView = new QGraphicsView(gridLayoutWidget);
        graphicsView->setObjectName(QStringLiteral("graphicsView"));
        graphicsView->setEnabled(true);
        graphicsView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        graphicsView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        gridLayout_11->addWidget(graphicsView, 0, 0, 1, 1);

        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 430, 661, 441));
        gridLayoutWidget_5 = new QWidget(groupBox);
        gridLayoutWidget_5->setObjectName(QStringLiteral("gridLayoutWidget_5"));
        gridLayoutWidget_5->setGeometry(QRect(10, 30, 631, 131));
        gridLayout_6 = new QGridLayout(gridLayoutWidget_5);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        gridLayout_6->setContentsMargins(0, 0, 0, 0);
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        gridLayout_10 = new QGridLayout();
        gridLayout_10->setObjectName(QStringLiteral("gridLayout_10"));
        label_4 = new QLabel(gridLayoutWidget_5);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout_10->addWidget(label_4, 1, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        highH_slider = new QSlider(gridLayoutWidget_5);
        highH_slider->setObjectName(QStringLiteral("highH_slider"));
        highH_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_3->addWidget(highH_slider);

        highH_label = new QLabel(gridLayoutWidget_5);
        highH_label->setObjectName(QStringLiteral("highH_label"));

        horizontalLayout_3->addWidget(highH_label);


        gridLayout_10->addLayout(horizontalLayout_3, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_10, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lowH_slider = new QSlider(gridLayoutWidget_5);
        lowH_slider->setObjectName(QStringLiteral("lowH_slider"));
        lowH_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(lowH_slider);

        lowH_label = new QLabel(gridLayoutWidget_5);
        lowH_label->setObjectName(QStringLiteral("lowH_label"));

        horizontalLayout_2->addWidget(lowH_label);


        gridLayout_5->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName(QStringLiteral("gridLayout_9"));
        label = new QLabel(gridLayoutWidget_5);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_9->addWidget(label, 0, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_9, 0, 0, 1, 1);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_5->addItem(verticalSpacer_5, 3, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 1, 1, 1);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        gridLayout_14 = new QGridLayout();
        gridLayout_14->setObjectName(QStringLiteral("gridLayout_14"));
        label_15 = new QLabel(gridLayoutWidget_5);
        label_15->setObjectName(QStringLiteral("label_15"));

        gridLayout_14->addWidget(label_15, 0, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_14, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        highV_slider = new QSlider(gridLayoutWidget_5);
        highV_slider->setObjectName(QStringLiteral("highV_slider"));
        highV_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_6->addWidget(highV_slider);

        highV_label = new QLabel(gridLayoutWidget_5);
        highV_label->setObjectName(QStringLiteral("highV_label"));

        horizontalLayout_6->addWidget(highV_label);


        gridLayout_8->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        gridLayout_15 = new QGridLayout();
        gridLayout_15->setObjectName(QStringLiteral("gridLayout_15"));
        label_7 = new QLabel(gridLayoutWidget_5);
        label_7->setObjectName(QStringLiteral("label_7"));

        gridLayout_15->addWidget(label_7, 0, 0, 1, 1);


        gridLayout_8->addLayout(gridLayout_15, 2, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        lowV_slider = new QSlider(gridLayoutWidget_5);
        lowV_slider->setObjectName(QStringLiteral("lowV_slider"));
        lowV_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_7->addWidget(lowV_slider);

        lowV_label = new QLabel(gridLayoutWidget_5);
        lowV_label->setObjectName(QStringLiteral("lowV_label"));

        horizontalLayout_7->addWidget(lowV_label);


        gridLayout_8->addLayout(horizontalLayout_7, 3, 0, 1, 1);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_8->addItem(verticalSpacer_6, 4, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_8, 0, 3, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));

        gridLayout_6->addLayout(gridLayout_3, 0, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        gridLayout_13 = new QGridLayout();
        gridLayout_13->setObjectName(QStringLiteral("gridLayout_13"));
        label_6 = new QLabel(gridLayoutWidget_5);
        label_6->setObjectName(QStringLiteral("label_6"));

        gridLayout_13->addWidget(label_6, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_13, 2, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        highS_slider = new QSlider(gridLayoutWidget_5);
        highS_slider->setObjectName(QStringLiteral("highS_slider"));
        highS_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_4->addWidget(highS_slider);

        highS_label = new QLabel(gridLayoutWidget_5);
        highS_label->setObjectName(QStringLiteral("highS_label"));

        horizontalLayout_4->addWidget(highS_label);


        gridLayout_4->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        gridLayout_12 = new QGridLayout();
        gridLayout_12->setObjectName(QStringLiteral("gridLayout_12"));
        label_12 = new QLabel(gridLayoutWidget_5);
        label_12->setObjectName(QStringLiteral("label_12"));

        gridLayout_12->addWidget(label_12, 0, 0, 1, 1);


        gridLayout_4->addLayout(gridLayout_12, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        lowS_slider = new QSlider(gridLayoutWidget_5);
        lowS_slider->setObjectName(QStringLiteral("lowS_slider"));
        lowS_slider->setOrientation(Qt::Horizontal);

        horizontalLayout_5->addWidget(lowS_slider);

        lowS_label = new QLabel(gridLayoutWidget_5);
        lowS_label->setObjectName(QStringLiteral("lowS_label"));

        horizontalLayout_5->addWidget(lowS_label);


        gridLayout_4->addLayout(horizontalLayout_5, 3, 0, 1, 1);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_4->addItem(verticalSpacer_4, 4, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_4, 0, 2, 1, 1);

        x_position = new QLabel(groupBox);
        x_position->setObjectName(QStringLiteral("x_position"));
        x_position->setGeometry(QRect(910, 40, 66, 17));
        y_position_2 = new QLabel(groupBox);
        y_position_2->setObjectName(QStringLiteral("y_position_2"));
        y_position_2->setGeometry(QRect(910, 70, 66, 17));
        time_label = new QLabel(groupBox);
        time_label->setObjectName(QStringLiteral("time_label"));
        time_label->setGeometry(QRect(930, 100, 41, 17));
        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(1130, 570, 121, 27));

        retranslateUi(HSVWindows);

        QMetaObject::connectSlotsByName(HSVWindows);
    } // setupUi

    void retranslateUi(QDialog *HSVWindows)
    {
        HSVWindows->setWindowTitle(QApplication::translate("HSVWindows", "HSV Segmentation", 0));
        groupBox_2->setTitle(QApplication::translate("HSVWindows", "Video:", 0));
        groupBox->setTitle(QApplication::translate("HSVWindows", "Parameters:", 0));
        label_4->setText(QApplication::translate("HSVWindows", "LowH:", 0));
        highH_label->setText(QApplication::translate("HSVWindows", "0", 0));
        lowH_label->setText(QApplication::translate("HSVWindows", "0", 0));
        label->setText(QApplication::translate("HSVWindows", "HighH:", 0));
        label_15->setText(QApplication::translate("HSVWindows", "HighV:", 0));
        highV_label->setText(QApplication::translate("HSVWindows", "0", 0));
        label_7->setText(QApplication::translate("HSVWindows", "LowV:", 0));
        lowV_label->setText(QApplication::translate("HSVWindows", "0", 0));
        label_6->setText(QApplication::translate("HSVWindows", "LowS:", 0));
        highS_label->setText(QApplication::translate("HSVWindows", "0", 0));
        label_12->setText(QApplication::translate("HSVWindows", "HighS:", 0));
        lowS_label->setText(QApplication::translate("HSVWindows", "0", 0));
        x_position->setText(QString());
        y_position_2->setText(QString());
        time_label->setText(QApplication::translate("HSVWindows", "TextLabel", 0));
        pushButton->setText(QApplication::translate("HSVWindows", "Save File", 0));
    } // retranslateUi

};

namespace Ui {
    class HSVWindows: public Ui_HSVWindows {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HSVWINDOWS_H
