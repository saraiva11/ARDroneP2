/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[25];
    char stringdata[368];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 6), // "setHSV"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 2), // "hH"
QT_MOC_LITERAL(4, 22, 2), // "lH"
QT_MOC_LITERAL(5, 25, 2), // "hS"
QT_MOC_LITERAL(6, 28, 2), // "lS"
QT_MOC_LITERAL(7, 31, 2), // "hV"
QT_MOC_LITERAL(8, 34, 2), // "lV"
QT_MOC_LITERAL(9, 37, 12), // "readJoystick"
QT_MOC_LITERAL(10, 50, 16), // "QVector<int16_t>"
QT_MOC_LITERAL(11, 67, 6), // "values"
QT_MOC_LITERAL(12, 74, 17), // "OurVisonAlgorithm"
QT_MOC_LITERAL(13, 92, 7), // "cv::Mat"
QT_MOC_LITERAL(14, 100, 24), // "processFrameAndUpdateGUI"
QT_MOC_LITERAL(15, 125, 20), // "getBatteryPercentage"
QT_MOC_LITERAL(16, 146, 21), // "on_bt_connect_clicked"
QT_MOC_LITERAL(17, 168, 24), // "on_bt_Disconnect_clicked"
QT_MOC_LITERAL(18, 193, 30), // "on_bt_hsv_segmentation_clicked"
QT_MOC_LITERAL(19, 224, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(20, 248, 23), // "on_bt_takeoff_2_clicked"
QT_MOC_LITERAL(21, 272, 23), // "on_bt_landing_2_clicked"
QT_MOC_LITERAL(22, 296, 25), // "on_bt_emergency_2_clicked"
QT_MOC_LITERAL(23, 322, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(24, 344, 23) // "on_pushButton_3_clicked"

    },
    "MainWindow\0setHSV\0\0hH\0lH\0hS\0lS\0hV\0lV\0"
    "readJoystick\0QVector<int16_t>\0values\0"
    "OurVisonAlgorithm\0cv::Mat\0"
    "processFrameAndUpdateGUI\0getBatteryPercentage\0"
    "on_bt_connect_clicked\0on_bt_Disconnect_clicked\0"
    "on_bt_hsv_segmentation_clicked\0"
    "on_pushButton_2_clicked\0on_bt_takeoff_2_clicked\0"
    "on_bt_landing_2_clicked\0"
    "on_bt_emergency_2_clicked\0"
    "on_pushButton_clicked\0on_pushButton_3_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    6,   84,    2, 0x0a /* Public */,
       9,    1,   97,    2, 0x0a /* Public */,
      12,    0,  100,    2, 0x08 /* Private */,
      14,    0,  101,    2, 0x08 /* Private */,
      15,    0,  102,    2, 0x08 /* Private */,
      16,    0,  103,    2, 0x08 /* Private */,
      17,    0,  104,    2, 0x08 /* Private */,
      18,    0,  105,    2, 0x08 /* Private */,
      19,    0,  106,    2, 0x08 /* Private */,
      20,    0,  107,    2, 0x08 /* Private */,
      21,    0,  108,    2, 0x08 /* Private */,
      22,    0,  109,    2, 0x08 /* Private */,
      23,    0,  110,    2, 0x08 /* Private */,
      24,    0,  111,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,    8,
    QMetaType::Void, 0x80000000 | 10,   11,
    0x80000000 | 13,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: _t->setHSV((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 1: _t->readJoystick((*reinterpret_cast< QVector<int16_t>(*)>(_a[1]))); break;
        case 2: { cv::Mat _r = _t->OurVisonAlgorithm();
            if (_a[0]) *reinterpret_cast< cv::Mat*>(_a[0]) = _r; }  break;
        case 3: _t->processFrameAndUpdateGUI(); break;
        case 4: _t->getBatteryPercentage(); break;
        case 5: _t->on_bt_connect_clicked(); break;
        case 6: _t->on_bt_Disconnect_clicked(); break;
        case 7: _t->on_bt_hsv_segmentation_clicked(); break;
        case 8: _t->on_pushButton_2_clicked(); break;
        case 9: _t->on_bt_takeoff_2_clicked(); break;
        case 10: _t->on_bt_landing_2_clicked(); break;
        case 11: _t->on_bt_emergency_2_clicked(); break;
        case 12: _t->on_pushButton_clicked(); break;
        case 13: _t->on_pushButton_3_clicked(); break;
        default: ;
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
