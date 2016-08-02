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
    QByteArrayData data[30];
    char stringdata0[358];
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
QT_MOC_LITERAL(5, 50, 12), // "layerOrdered"
QT_MOC_LITERAL(6, 63, 3), // "src"
QT_MOC_LITERAL(7, 67, 3), // "dst"
QT_MOC_LITERAL(8, 71, 18), // "firstLayerSelected"
QT_MOC_LITERAL(9, 90, 20), // "firstLayerUnselected"
QT_MOC_LITERAL(10, 111, 12), // "onlyOneLayer"
QT_MOC_LITERAL(11, 124, 16), // "moreThanOneLayer"
QT_MOC_LITERAL(12, 141, 18), // "layerSelectedMoved"
QT_MOC_LITERAL(13, 160, 12), // "sf::Vector2f"
QT_MOC_LITERAL(14, 173, 8), // "position"
QT_MOC_LITERAL(15, 182, 19), // "layerSelectedScaled"
QT_MOC_LITERAL(16, 202, 4), // "size"
QT_MOC_LITERAL(17, 207, 19), // "_layerSelectedMoved"
QT_MOC_LITERAL(18, 227, 20), // "_layerSelectedScaled"
QT_MOC_LITERAL(19, 248, 11), // "createLayer"
QT_MOC_LITERAL(20, 260, 10), // "sf::Image*"
QT_MOC_LITERAL(21, 271, 5), // "image"
QT_MOC_LITERAL(22, 277, 11), // "deleteLayer"
QT_MOC_LITERAL(23, 289, 5), // "layer"
QT_MOC_LITERAL(24, 295, 9), // "dropLayer"
QT_MOC_LITERAL(25, 305, 9), // "fuseLayer"
QT_MOC_LITERAL(26, 315, 9), // "layer_src"
QT_MOC_LITERAL(27, 325, 9), // "layer_dst"
QT_MOC_LITERAL(28, 335, 11), // "selectLayer"
QT_MOC_LITERAL(29, 347, 10) // "orderLayer"

    },
    "LayerController\0layerCreated\0\0Layer*\0"
    "layerDeleted\0layerOrdered\0src\0dst\0"
    "firstLayerSelected\0firstLayerUnselected\0"
    "onlyOneLayer\0moreThanOneLayer\0"
    "layerSelectedMoved\0sf::Vector2f\0"
    "position\0layerSelectedScaled\0size\0"
    "_layerSelectedMoved\0_layerSelectedScaled\0"
    "createLayer\0sf::Image*\0image\0deleteLayer\0"
    "layer\0dropLayer\0fuseLayer\0layer_src\0"
    "layer_dst\0selectLayer\0orderLayer"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LayerController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      22,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  124,    2, 0x06 /* Public */,
       4,    1,  127,    2, 0x06 /* Public */,
       5,    2,  130,    2, 0x06 /* Public */,
       8,    1,  135,    2, 0x06 /* Public */,
       9,    1,  138,    2, 0x06 /* Public */,
      10,    0,  141,    2, 0x06 /* Public */,
      11,    0,  142,    2, 0x06 /* Public */,
      12,    1,  143,    2, 0x06 /* Public */,
      15,    1,  146,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      17,    1,  149,    2, 0x08 /* Private */,
      18,    1,  152,    2, 0x08 /* Private */,
      19,    1,  155,    2, 0x0a /* Public */,
      19,    0,  158,    2, 0x2a /* Public | MethodCloned */,
      22,    1,  159,    2, 0x0a /* Public */,
      22,    0,  162,    2, 0x2a /* Public | MethodCloned */,
      24,    1,  163,    2, 0x0a /* Public */,
      24,    0,  166,    2, 0x2a /* Public | MethodCloned */,
      25,    2,  167,    2, 0x0a /* Public */,
      25,    0,  172,    2, 0x0a /* Public */,
      28,    1,  173,    2, 0x0a /* Public */,
      28,    0,  176,    2, 0x2a /* Public | MethodCloned */,
      29,    2,  177,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   16,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, 0x80000000 | 13,   16,
    QMetaType::Void, 0x80000000 | 20,   21,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   23,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   23,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   26,   27,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   23,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    6,    7,

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
        case 2: _t->layerOrdered((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->firstLayerSelected((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 4: _t->firstLayerUnselected((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 5: _t->onlyOneLayer(); break;
        case 6: _t->moreThanOneLayer(); break;
        case 7: _t->layerSelectedMoved((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 8: _t->layerSelectedScaled((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 9: _t->_layerSelectedMoved((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 10: _t->_layerSelectedScaled((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 11: _t->createLayer((*reinterpret_cast< sf::Image*(*)>(_a[1]))); break;
        case 12: _t->createLayer(); break;
        case 13: _t->deleteLayer((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 14: _t->deleteLayer(); break;
        case 15: _t->dropLayer((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 16: _t->dropLayer(); break;
        case 17: _t->fuseLayer((*reinterpret_cast< Layer*(*)>(_a[1])),(*reinterpret_cast< Layer*(*)>(_a[2]))); break;
        case 18: _t->fuseLayer(); break;
        case 19: _t->selectLayer((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 20: _t->selectLayer(); break;
        case 21: _t->orderLayer((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
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
            typedef void (LayerController::*_t)(int , int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::layerOrdered)) {
                *result = 2;
            }
        }
        {
            typedef void (LayerController::*_t)(Layer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::firstLayerSelected)) {
                *result = 3;
            }
        }
        {
            typedef void (LayerController::*_t)(Layer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::firstLayerUnselected)) {
                *result = 4;
            }
        }
        {
            typedef void (LayerController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::onlyOneLayer)) {
                *result = 5;
            }
        }
        {
            typedef void (LayerController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::moreThanOneLayer)) {
                *result = 6;
            }
        }
        {
            typedef void (LayerController::*_t)(sf::Vector2f );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::layerSelectedMoved)) {
                *result = 7;
            }
        }
        {
            typedef void (LayerController::*_t)(sf::Vector2f );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&LayerController::layerSelectedScaled)) {
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
        if (_id < 22)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 22;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 22)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 22;
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
void LayerController::layerOrdered(int _t1, int _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void LayerController::firstLayerSelected(Layer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void LayerController::firstLayerUnselected(Layer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void LayerController::onlyOneLayer()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void LayerController::moreThanOneLayer()
{
    QMetaObject::activate(this, &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void LayerController::layerSelectedMoved(sf::Vector2f _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void LayerController::layerSelectedScaled(sf::Vector2f _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_END_MOC_NAMESPACE
