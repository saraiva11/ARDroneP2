/****************************************************************************
** Meta object code from reading C++ file 'hsvwindows.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.4.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "hsvwindows.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hsvwindows.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.4.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_HSVWindows_t {
    QByteArrayData data[17];
    char stringdata[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HSVWindows_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HSVWindows_t qt_meta_stringdata_HSVWindows = {
    {
QT_MOC_LITERAL(0, 0, 10), // "HSVWindows"
QT_MOC_LITERAL(1, 11, 16), // "setHSVMainWindow"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 2), // "hH"
QT_MOC_LITERAL(4, 32, 2), // "lH"
QT_MOC_LITERAL(5, 35, 2), // "hS"
QT_MOC_LITERAL(6, 38, 2), // "lS"
QT_MOC_LITERAL(7, 41, 2), // "hV"
QT_MOC_LITERAL(8, 44, 2), // "lV"
QT_MOC_LITERAL(9, 47, 28), // "on_highH_slider_valueChanged"
QT_MOC_LITERAL(10, 76, 5), // "value"
QT_MOC_LITERAL(11, 82, 27), // "on_lowH_slider_valueChanged"
QT_MOC_LITERAL(12, 110, 28), // "on_highS_slider_valueChanged"
QT_MOC_LITERAL(13, 139, 27), // "on_lowS_slider_valueChanged"
QT_MOC_LITERAL(14, 167, 28), // "on_highV_slider_valueChanged"
QT_MOC_LITERAL(15, 196, 27), // "on_lowV_slider_valueChanged"
QT_MOC_LITERAL(16, 224, 21) // "on_pushButton_clicked"

    },
    "HSVWindows\0setHSVMainWindow\0\0hH\0lH\0"
    "hS\0lS\0hV\0lV\0on_highH_slider_valueChanged\0"
    "value\0on_lowH_slider_valueChanged\0"
    "on_highS_slider_valueChanged\0"
    "on_lowS_slider_valueChanged\0"
    "on_highV_slider_valueChanged\0"
    "on_lowV_slider_valueChanged\0"
    "on_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HSVWindows[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    6,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   67,    2, 0x08 /* Private */,
      11,    1,   70,    2, 0x08 /* Private */,
      12,    1,   73,    2, 0x08 /* Private */,
      13,    1,   76,    2, 0x08 /* Private */,
      14,    1,   79,    2, 0x08 /* Private */,
      15,    1,   82,    2, 0x08 /* Private */,
      16,    0,   85,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,    3,    4,    5,    6,    7,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,

       0        // eod
};

void HSVWindows::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HSVWindows *_t = static_cast<HSVWindows *>(_o);
        switch (_id) {
        case 0: _t->setHSVMainWindow((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4])),(*reinterpret_cast< int(*)>(_a[5])),(*reinterpret_cast< int(*)>(_a[6]))); break;
        case 1: _t->on_highH_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_lowH_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->on_highS_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->on_lowS_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_highV_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_lowV_slider_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (HSVWindows::*_t)(int , int , int , int , int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&HSVWindows::setHSVMainWindow)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject HSVWindows::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_HSVWindows.data,
      qt_meta_data_HSVWindows,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *HSVWindows::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HSVWindows::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_HSVWindows.stringdata))
        return static_cast<void*>(const_cast< HSVWindows*>(this));
    return QDialog::qt_metacast(_clname);
}

int HSVWindows::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void HSVWindows::setHSVMainWindow(int _t1, int _t2, int _t3, int _t4, int _t5, int _t6)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)), const_cast<void*>(reinterpret_cast<const void*>(&_t5)), const_cast<void*>(reinterpret_cast<const void*>(&_t6)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
