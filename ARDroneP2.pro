#-------------------------------------------------
#
# Project created by QtCreator 2015-05-29T03:04:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ARDroneP2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    qcompass.cpp \
    qadi.cpp \
    hsvwindows.cpp \
    ardrone/ardrone.cpp \
    ardrone/command.cpp \
    ardrone/config.cpp \
    ardrone/navdata.cpp \
    ardrone/tcp.cpp \
    ardrone/udp.cpp \
    ardrone/version.cpp \
    ardrone/video.cpp \
    gamepad.cpp

HEADERS  += mainwindow.h \
    qcompass.h \
    qadi.h \
    hsvwindows.h \
    ardrone/ardrone.h \
    ardrone/uvlc.h \
    gamepad.h

FORMS    += mainwindow.ui \
    hsvwindows.ui


INCLUDEPATH += /usr/local/include


LIBS +=  -L/usr/local/lib
LIBS += -lopencv_calib3d -lopencv_core -lopencv_features2d -lopencv_flann -lopencv_highgui -lopencv_imgproc -lopencv_ml -lopencv_objdetect -lopencv_photo -lopencv_stitching -lopencv_superres -lopencv_ts -lopencv_video -lopencv_videostab
LIBS += -lm -lpthread -lavutil -lavformat -lavcodec -lswscale
LIBS += -lSDL2 -ldl -lpthread
