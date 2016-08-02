/****************************************************************************
** Meta object code from reading C++ file 'BrushController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Brush/BrushController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'BrushController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_BrushController_t {
    QByteArrayData data[21];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_BrushController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_BrushController_t qt_meta_stringdata_BrushController = {
    {
QT_MOC_LITERAL(0, 0, 15), // "BrushController"
QT_MOC_LITERAL(1, 16, 12), // "brushCreated"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 6), // "Brush*"
QT_MOC_LITERAL(4, 37, 12), // "sizeXChanged"
QT_MOC_LITERAL(5, 50, 12), // "sizeYChanged"
QT_MOC_LITERAL(6, 63, 14), // "opacityChanged"
QT_MOC_LITERAL(7, 78, 12), // "seuilChanged"
QT_MOC_LITERAL(8, 91, 11), // "createBrush"
QT_MOC_LITERAL(9, 103, 8), // "brush_id"
QT_MOC_LITERAL(10, 112, 16), // "nBrh::brush_enum"
QT_MOC_LITERAL(11, 129, 5), // "brush"
QT_MOC_LITERAL(12, 135, 11), // "selectBrush"
QT_MOC_LITERAL(13, 147, 10), // "changeSize"
QT_MOC_LITERAL(14, 158, 12), // "sf::Vector2i"
QT_MOC_LITERAL(15, 171, 5), // "value"
QT_MOC_LITERAL(16, 177, 11), // "changeSizeX"
QT_MOC_LITERAL(17, 189, 11), // "changeSizeY"
QT_MOC_LITERAL(18, 201, 13), // "changeOpacity"
QT_MOC_LITERAL(19, 215, 11), // "changeSeuil"
QT_MOC_LITERAL(20, 227, 13) // "displayCenter"

    },
    "BrushController\0brushCreated\0\0Brush*\0"
    "sizeXChanged\0sizeYChanged\0opacityChanged\0"
    "seuilChanged\0createBrush\0brush_id\0"
    "nBrh::brush_enum\0brush\0selectBrush\0"
    "changeSize\0sf::Vector2i\0value\0changeSizeX\0"
    "changeSizeY\0changeOpacity\0changeSeuil\0"
    "displayCenter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_BrushController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,
       4,    1,   97,    2, 0x06 /* Public */,
       5,    1,  100,    2, 0x06 /* Public */,
       6,    1,  103,    2, 0x06 /* Public */,
       7,    1,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,  109,    2, 0x0a /* Public */,
       8,    1,  112,    2, 0x0a /* Public */,
      12,    1,  115,    2, 0x0a /* Public */,
      12,    1,  118,    2, 0x0a /* Public */,
      12,    1,  121,    2, 0x0a /* Public */,
      13,    1,  124,    2, 0x0a /* Public */,
      16,    1,  127,    2, 0x0a /* Public */,
      17,    1,  130,    2, 0x0a /* Public */,
      18,    1,  133,    2, 0x0a /* Public */,
      19,    1,  136,    2, 0x0a /* Public */,
      20,    0,  139,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 3,   11,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,

       0        // eod
};

void BrushController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        BrushController *_t = static_cast<BrushController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->brushCreated((*reinterpret_cast< Brush*(*)>(_a[1]))); break;
        case 1: _t->sizeXChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sizeYChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->opacityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->seuilChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->createBrush((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->createBrush((*reinterpret_cast< nBrh::brush_enum(*)>(_a[1]))); break;
        case 7: _t->selectBrush((*reinterpret_cast< Brush*(*)>(_a[1]))); break;
        case 8: _t->selectBrush((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->selectBrush((*reinterpret_cast< nBrh::brush_enum(*)>(_a[1]))); break;
        case 10: _t->changeSize((*reinterpret_cast< sf::Vector2i(*)>(_a[1]))); break;
        case 11: _t->changeSizeX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->changeSizeY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->changeOpacity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->changeSeuil((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->displayCenter(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (BrushController::*_t)(Brush * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BrushController::brushCreated)) {
                *result = 0;
            }
        }
        {
            typedef void (BrushController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BrushController::sizeXChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (BrushController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BrushController::sizeYChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (BrushController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BrushController::opacityChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (BrushController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&BrushController::seuilChanged)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject BrushController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_BrushController.data,
      qt_meta_data_BrushController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *BrushController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *BrushController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_BrushController.stringdata0))
        return static_cast<void*>(const_cast< BrushController*>(this));
    if (!strcmp(_clname, "SignalInit"))
        return static_cast< SignalInit*>(const_cast< BrushController*>(this));
    return QObject::qt_metacast(_clname);
}

int BrushController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void BrushController::brushCreated(Brush * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void BrushController::sizeXChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void BrushController::sizeYChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void BrushController::opacityChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void BrushController::seuilChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
