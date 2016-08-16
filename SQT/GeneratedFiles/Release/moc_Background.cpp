/****************************************************************************
** Meta object code from reading C++ file 'Background.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Background/Background.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Background.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Background_t {
    QByteArrayData data[11];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Background_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Background_t qt_meta_stringdata_Background = {
    {
QT_MOC_LITERAL(0, 0, 10), // "Background"
QT_MOC_LITERAL(1, 11, 9), // "bindLayer"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "Layer*"
QT_MOC_LITERAL(4, 29, 5), // "layer"
QT_MOC_LITERAL(5, 35, 11), // "unbindLayer"
QT_MOC_LITERAL(6, 47, 16), // "layerTransformed"
QT_MOC_LITERAL(7, 64, 12), // "cameraZoomed"
QT_MOC_LITERAL(8, 77, 11), // "zoom_factor"
QT_MOC_LITERAL(9, 89, 10), // "updateFond"
QT_MOC_LITERAL(10, 100, 11) // "updateLines"

    },
    "Background\0bindLayer\0\0Layer*\0layer\0"
    "unbindLayer\0layerTransformed\0cameraZoomed\0"
    "zoom_factor\0updateFond\0updateLines"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Background[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       5,    1,   47,    2, 0x08 /* Private */,
       6,    0,   50,    2, 0x08 /* Private */,
       7,    1,   51,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       9,    0,   54,    2, 0x00 /* Private */,
      10,    0,   55,    2, 0x00 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    8,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Background::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Background *_t = static_cast<Background *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->bindLayer((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 1: _t->unbindLayer((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 2: _t->layerTransformed(); break;
        case 3: _t->cameraZoomed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 4: _t->updateFond(); break;
        case 5: _t->updateLines(); break;
        default: ;
        }
    }
}

const QMetaObject Background::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Background.data,
      qt_meta_data_Background,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Background::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Background::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Background.stringdata0))
        return static_cast<void*>(const_cast< Background*>(this));
    return QObject::qt_metacast(_clname);
}

int Background::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
