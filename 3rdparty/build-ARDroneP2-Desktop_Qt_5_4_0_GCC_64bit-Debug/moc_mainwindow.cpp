/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ARDroneP2/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[20];
    char stringdata[285];
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
QT_MOC_LITERAL(9, 37, 17), // "OurVisonAlgorithm"
QT_MOC_LITERAL(10, 55, 7), // "cv::Mat"
QT_MOC_LITERAL(11, 63, 24), // "processFrameAndUpdateGUI"
QT_MOC_LITERAL(12, 88, 20), // "getBatteryPercentage"
QT_MOC_LITERAL(13, 109, 21), // "on_bt_connect_clicked"
QT_MOC_LITERAL(14, 131, 24), // "on_bt_Disconnect_clicked"
QT_MOC_LITERAL(15, 156, 30), // "on_bt_hsv_segmentation_clicked"
QT_MOC_LITERAL(16, 187, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(17, 211, 23), // "on_bt_takeoff_2_clicked"
QT_MOC_LITERAL(18, 235, 23), // "on_bt_landing_2_clicked"
QT_MOC_LITERAL(19, 259, 25) // "on_bt_emergency_2_clicked"

    },
    "MainWindow\0setHSV\0\0hH\0lH\0hS\0lS\0hV\0lV\0"
    "OurVisonAlgorithm\0cv::Mat\0"
    "processFrameAndUpdateGUI\0getBatteryPercentage\0"
    "on_bt_connect_clicked\0on_bt_Disconnect_clicked\0"
    "on_bt_hsv_segmentation_clicked\0"
    "on_pushButton_2_clicked\0on_bt_takeoff_2_clicked\0"
    "on_bt_landing_2_clicked\0"
    "on_bt_emergency_2_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    6,   69,    2, 0x0a /* Public */,
       9,    0,   82,    2, 0x08 /* Private */,
      11,    0,   83,    2, 0x08 /* Private */,
      12,    0,   84,    2, 0x08 /* Private */,
      13,    0,   85,    2, 0x08 /* Private */,
      14,    0,   86,    2, 0x08 /* Private */,
      15,    0,   87,    2, 0x08 /* Private */,
      16,    0,   88,    2, 0x08 /* Private */,
      17,    0,   89,    2, 0x08 /* Private */,
      18,    0,   90,    2, 0x08 /* Private */,
      19,    0,   91,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,    8,
    0x80000000 | 10,
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
        case 1: { cv::Mat _r = _t->OurVisonAlgorithm();
            if (_a[0]) *reinterpret_cast< cv::Mat*>(_a[0]) = _r; }  break;
        case 2: _t->processFrameAndUpdateGUI(); break;
        case 3: _t->getBatteryPercentage(); break;
        case 4: _t->on_bt_connect_clicked(); break;
        case 5: _t->on_bt_Disconnect_clicked(); break;
        case 6: _t->on_bt_hsv_segmentation_clicked(); break;
        case 7: _t->on_pushButton_2_clicked(); break;
        case 8: _t->on_bt_takeoff_2_clicked(); break;
        case 9: _t->on_bt_landing_2_clicked(); break;
        case 10: _t->on_bt_emergency_2_clicked(); break;
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
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
