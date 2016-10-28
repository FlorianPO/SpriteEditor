/****************************************************************************
** Meta object code from reading C++ file 'LayerController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Layer/LayerController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LayerController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LayerController_t {
    QByteArrayData data[14];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LayerController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LayerController_t qt_meta_stringdata_LayerController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "LayerController"
QT_MOC_LITERAL(1, 16, 13), // "layerSelected"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 6), // "Layer&"
QT_MOC_LITERAL(4, 38, 15), // "layerUnselected"
QT_MOC_LITERAL(5, 54, 11), // "createLayer"
QT_MOC_LITERAL(6, 66, 10), // "sf::Image&"
QT_MOC_LITERAL(7, 77, 5), // "image"
QT_MOC_LITERAL(8, 83, 9), // "dropLayer"
QT_MOC_LITERAL(9, 93, 5), // "layer"
QT_MOC_LITERAL(10, 99, 9), // "fuseLayer"
QT_MOC_LITERAL(11, 109, 9), // "layer_src"
QT_MOC_LITERAL(12, 119, 9), // "layer_dst"
QT_MOC_LITERAL(13, 129, 11) // "selectLayer"

    },
    "LayerController\0layerSelected\0\0Layer&\0"
    "layerUnselected\0createLayer\0sf::Image&\0"
    "image\0dropLayer\0layer\0fuseLayer\0"
    "layer_src\0layer_dst\0selectLayer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LayerController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x06 /* Public */,
       4,    1,   67,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   70,    2, 0x0a /* Public */,
       5,    0,   73,    2, 0x0a /* Public */,
       8,    1,   74,    2, 0x0a /* Public */,
       8,    0,   77,    2, 0x0a /* Public */,
      10,    2,   78,    2, 0x0a /* Public */,
      10,    0,   83,    2, 0x0a /* Public */,
      13,    1,   84,    2, 0x0a /* Public */,
      13,    0,   87,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   11,   12,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    9,
    QMetaType::Void,

       0        // eod
};

void LayerController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LayerController *_t = static_cast<LayerController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->layerSelected((*reinterpret_cast< Layer(*)>(_a[1]))); break;
        case 1: _t->layerUnselected((*reinterpret_cast< Layer(*)>(_a[1]))); break;
        case 2: _t->createLayer((*reinterpret_cast< sf::Image(*)>(_a[1]))); break;
        case 3: _t->createLayer(); break;
        case 4: _t->dropLayer((*reinterpret_cast< Layer(*)>(_a[1]))); break;
        case 5: _t->dropLayer(); break;
        case 6: _t->fuseLayer((*reinterpret_cast< Layer(*)>(_a[1])),(*reinterpret_cast< Layer(*)>(_a[2]))); break;
        case 7: _t->fuseLayer(); break;
        case 8: _t->selectLayer((*reinterpret_cast< Layer(*)>(_a[1]))); break;
        case 9: _t->selectLayer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LayerController::*_t)(Layer & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::layerSelected)) {
                *result = 0;
            }
        }
        {
            typedef void (LayerController::*_t)(Layer & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::layerUnselected)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject LayerController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_LayerController.data,
      qt_meta_data_LayerController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LayerController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LayerController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LayerController.stringdata0))
        return static_cast<void*>(const_cast< LayerController*>(this));
    return QObject::qt_metacast(_clname);
}

int LayerController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void LayerController::layerSelected(Layer & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< LayerController *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LayerController::layerUnselected(Layer & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< LayerController *>(this), &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
