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
    QByteArrayData data[25];
    char stringdata0[281];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LayerController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LayerController_t qt_meta_stringdata_LayerController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "LayerController"
QT_MOC_LITERAL(1, 16, 12), // "layerCreated"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "Layer*"
QT_MOC_LITERAL(4, 37, 12), // "layerDeleted"
QT_MOC_LITERAL(5, 50, 13), // "layerSelected"
QT_MOC_LITERAL(6, 64, 15), // "layerUnselected"
QT_MOC_LITERAL(7, 80, 12), // "layerOrdered"
QT_MOC_LITERAL(8, 93, 3), // "src"
QT_MOC_LITERAL(9, 97, 3), // "dst"
QT_MOC_LITERAL(10, 101, 18), // "firstLayerSelected"
QT_MOC_LITERAL(11, 120, 20), // "firstLayerUnselected"
QT_MOC_LITERAL(12, 141, 12), // "onlyOneLayer"
QT_MOC_LITERAL(13, 154, 16), // "moreThanOneLayer"
QT_MOC_LITERAL(14, 171, 11), // "createLayer"
QT_MOC_LITERAL(15, 183, 10), // "sf::Image*"
QT_MOC_LITERAL(16, 194, 5), // "image"
QT_MOC_LITERAL(17, 200, 11), // "deleteLayer"
QT_MOC_LITERAL(18, 212, 5), // "layer"
QT_MOC_LITERAL(19, 218, 9), // "dropLayer"
QT_MOC_LITERAL(20, 228, 9), // "fuseLayer"
QT_MOC_LITERAL(21, 238, 9), // "layer_src"
QT_MOC_LITERAL(22, 248, 9), // "layer_dst"
QT_MOC_LITERAL(23, 258, 11), // "selectLayer"
QT_MOC_LITERAL(24, 270, 10) // "orderLayer"

    },
    "LayerController\0layerCreated\0\0Layer*\0"
    "layerDeleted\0layerSelected\0layerUnselected\0"
    "layerOrdered\0src\0dst\0firstLayerSelected\0"
    "firstLayerUnselected\0onlyOneLayer\0"
    "moreThanOneLayer\0createLayer\0sf::Image*\0"
    "image\0deleteLayer\0layer\0dropLayer\0"
    "fuseLayer\0layer_src\0layer_dst\0selectLayer\0"
    "orderLayer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LayerController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      20,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  114,    2, 0x06 /* Public */,
       4,    1,  117,    2, 0x06 /* Public */,
       5,    1,  120,    2, 0x06 /* Public */,
       6,    1,  123,    2, 0x06 /* Public */,
       7,    2,  126,    2, 0x06 /* Public */,
      10,    1,  131,    2, 0x06 /* Public */,
      11,    1,  134,    2, 0x06 /* Public */,
      12,    0,  137,    2, 0x06 /* Public */,
      13,    0,  138,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  139,    2, 0x0a /* Public */,
      14,    0,  142,    2, 0x2a /* Public | MethodCloned */,
      17,    1,  143,    2, 0x0a /* Public */,
      17,    0,  146,    2, 0x2a /* Public | MethodCloned */,
      19,    1,  147,    2, 0x0a /* Public */,
      19,    0,  150,    2, 0x2a /* Public | MethodCloned */,
      20,    2,  151,    2, 0x0a /* Public */,
      20,    0,  156,    2, 0x0a /* Public */,
      23,    1,  157,    2, 0x0a /* Public */,
      23,    0,  160,    2, 0x2a /* Public | MethodCloned */,
      24,    2,  161,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 15,   16,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   18,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   21,   22,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   18,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    8,    9,

       0        // eod
};

void LayerController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LayerController *_t = static_cast<LayerController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->layerCreated((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 1: _t->layerDeleted((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 2: _t->layerSelected((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 3: _t->layerUnselected((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 4: _t->layerOrdered((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->firstLayerSelected((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 6: _t->firstLayerUnselected((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 7: _t->onlyOneLayer(); break;
        case 8: _t->moreThanOneLayer(); break;
        case 9: _t->createLayer((*reinterpret_cast< sf::Image*(*)>(_a[1]))); break;
        case 10: _t->createLayer(); break;
        case 11: _t->deleteLayer((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 12: _t->deleteLayer(); break;
        case 13: _t->dropLayer((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 14: _t->dropLayer(); break;
        case 15: _t->fuseLayer((*reinterpret_cast< Layer*(*)>(_a[1])),(*reinterpret_cast< Layer*(*)>(_a[2]))); break;
        case 16: _t->fuseLayer(); break;
        case 17: _t->selectLayer((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 18: _t->selectLayer(); break;
        case 19: _t->orderLayer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (LayerController::*_t)(Layer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::layerCreated)) {
                *result = 0;
            }
        }
        {
            typedef void (LayerController::*_t)(Layer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::layerDeleted)) {
                *result = 1;
            }
        }
        {
            typedef void (LayerController::*_t)(Layer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::layerSelected)) {
                *result = 2;
            }
        }
        {
            typedef void (LayerController::*_t)(Layer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::layerUnselected)) {
                *result = 3;
            }
        }
        {
            typedef void (LayerController::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::layerOrdered)) {
                *result = 4;
            }
        }
        {
            typedef void (LayerController::*_t)(Layer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::firstLayerSelected)) {
                *result = 5;
            }
        }
        {
            typedef void (LayerController::*_t)(Layer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::firstLayerUnselected)) {
                *result = 6;
            }
        }
        {
            typedef void (LayerController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::onlyOneLayer)) {
                *result = 7;
            }
        }
        {
            typedef void (LayerController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::moreThanOneLayer)) {
                *result = 8;
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
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 20;
    }
    return _id;
}

// SIGNAL 0
void LayerController::layerCreated(Layer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void LayerController::layerDeleted(Layer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void LayerController::layerSelected(Layer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LayerController::layerUnselected(Layer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LayerController::layerOrdered(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void LayerController::firstLayerSelected(Layer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void LayerController::firstLayerUnselected(Layer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void LayerController::onlyOneLayer()
{
    QMetaObject::activate(this, &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void LayerController::moreThanOneLayer()
{
    QMetaObject::activate(this, &staticMetaObject, 8, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
