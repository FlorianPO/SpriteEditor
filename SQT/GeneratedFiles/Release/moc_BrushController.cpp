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
struct qt_meta_stringdata_CBrushController_t {
    QByteArrayData data[20];
    char stringdata0[231];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CBrushController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CBrushController_t qt_meta_stringdata_CBrushController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CBrushController"
QT_MOC_LITERAL(1, 17, 12), // "brushCreated"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "CBrush*"
QT_MOC_LITERAL(4, 39, 12), // "sizeXChanged"
QT_MOC_LITERAL(5, 52, 12), // "sizeYChanged"
QT_MOC_LITERAL(6, 65, 14), // "opacityChanged"
QT_MOC_LITERAL(7, 80, 12), // "seuilChanged"
QT_MOC_LITERAL(8, 93, 11), // "createBrush"
QT_MOC_LITERAL(9, 105, 8), // "brush_id"
QT_MOC_LITERAL(10, 114, 18), // "CBrush::brush_enum"
QT_MOC_LITERAL(11, 133, 5), // "brush"
QT_MOC_LITERAL(12, 139, 11), // "selectBrush"
QT_MOC_LITERAL(13, 151, 10), // "changeSize"
QT_MOC_LITERAL(14, 162, 12), // "sf::Vector2i"
QT_MOC_LITERAL(15, 175, 5), // "value"
QT_MOC_LITERAL(16, 181, 11), // "changeSizeX"
QT_MOC_LITERAL(17, 193, 11), // "changeSizeY"
QT_MOC_LITERAL(18, 205, 13), // "changeOpacity"
QT_MOC_LITERAL(19, 219, 11) // "changeSeuil"

    },
    "CBrushController\0brushCreated\0\0CBrush*\0"
    "sizeXChanged\0sizeYChanged\0opacityChanged\0"
    "seuilChanged\0createBrush\0brush_id\0"
    "CBrush::brush_enum\0brush\0selectBrush\0"
    "changeSize\0sf::Vector2i\0value\0changeSizeX\0"
    "changeSizeY\0changeOpacity\0changeSeuil"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CBrushController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   89,    2, 0x06 /* Public */,
       4,    1,   92,    2, 0x06 /* Public */,
       5,    1,   95,    2, 0x06 /* Public */,
       6,    1,   98,    2, 0x06 /* Public */,
       7,    1,  101,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,  104,    2, 0x0a /* Public */,
       8,    1,  107,    2, 0x0a /* Public */,
      12,    1,  110,    2, 0x0a /* Public */,
      12,    1,  113,    2, 0x0a /* Public */,
      12,    1,  116,    2, 0x0a /* Public */,
      13,    1,  119,    2, 0x0a /* Public */,
      16,    1,  122,    2, 0x0a /* Public */,
      17,    1,  125,    2, 0x0a /* Public */,
      18,    1,  128,    2, 0x0a /* Public */,
      19,    1,  131,    2, 0x0a /* Public */,

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

       0        // eod
};

void CBrushController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CBrushController *_t = static_cast<CBrushController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->brushCreated((*reinterpret_cast< CBrush*(*)>(_a[1]))); break;
        case 1: _t->sizeXChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sizeYChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->opacityChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->seuilChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->createBrush((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->createBrush((*reinterpret_cast< CBrush::brush_enum(*)>(_a[1]))); break;
        case 7: _t->selectBrush((*reinterpret_cast< CBrush*(*)>(_a[1]))); break;
        case 8: _t->selectBrush((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->selectBrush((*reinterpret_cast< CBrush::brush_enum(*)>(_a[1]))); break;
        case 10: _t->changeSize((*reinterpret_cast< sf::Vector2i(*)>(_a[1]))); break;
        case 11: _t->changeSizeX((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->changeSizeY((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 13: _t->changeOpacity((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->changeSeuil((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CBrush* >(); break;
            }
            break;
        case 7:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< CBrush* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CBrushController::*_t)(CBrush * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBrushController::brushCreated)) {
                *result = 0;
            }
        }
        {
            typedef void (CBrushController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBrushController::sizeXChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (CBrushController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBrushController::sizeYChanged)) {
                *result = 2;
            }
        }
        {
            typedef void (CBrushController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBrushController::opacityChanged)) {
                *result = 3;
            }
        }
        {
            typedef void (CBrushController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CBrushController::seuilChanged)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject CBrushController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CBrushController.data,
      qt_meta_data_CBrushController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CBrushController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CBrushController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CBrushController.stringdata0))
        return static_cast<void*>(const_cast< CBrushController*>(this));
    return QObject::qt_metacast(_clname);
}

int CBrushController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void CBrushController::brushCreated(CBrush * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CBrushController::sizeXChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CBrushController::sizeYChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CBrushController::opacityChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CBrushController::seuilChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
