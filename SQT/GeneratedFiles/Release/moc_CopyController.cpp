/****************************************************************************
** Meta object code from reading C++ file 'CopyController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Copy/CopyController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CopyController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CopyController_t {
    QByteArrayData data[12];
    char stringdata0[131];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CopyController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CopyController_t qt_meta_stringdata_CopyController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CopyController"
QT_MOC_LITERAL(1, 15, 11), // "copyCreated"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 6), // "CCopy*"
QT_MOC_LITERAL(4, 35, 11), // "copyApplied"
QT_MOC_LITERAL(5, 47, 15), // "copyTransformed"
QT_MOC_LITERAL(6, 63, 8), // "new_copy"
QT_MOC_LITERAL(7, 72, 9), // "sf::Image"
QT_MOC_LITERAL(8, 82, 5), // "image"
QT_MOC_LITERAL(9, 88, 12), // "_copyCreated"
QT_MOC_LITERAL(10, 101, 12), // "_copyApplied"
QT_MOC_LITERAL(11, 114, 16) // "_copyTransformed"

    },
    "CopyController\0copyCreated\0\0CCopy*\0"
    "copyApplied\0copyTransformed\0new_copy\0"
    "sf::Image\0image\0_copyCreated\0_copyApplied\0"
    "_copyTransformed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CopyController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,
       5,    1,   55,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   58,    2, 0x0a /* Public */,
       9,    1,   61,    2, 0x0a /* Public */,
      10,    1,   64,    2, 0x0a /* Public */,
      11,    1,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

       0        // eod
};

void CopyController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CopyController *_t = static_cast<CopyController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->copyCreated((*reinterpret_cast< CCopy*(*)>(_a[1]))); break;
        case 1: _t->copyApplied((*reinterpret_cast< CCopy*(*)>(_a[1]))); break;
        case 2: _t->copyTransformed((*reinterpret_cast< CCopy*(*)>(_a[1]))); break;
        case 3: _t->new_copy((*reinterpret_cast< const sf::Image(*)>(_a[1]))); break;
        case 4: _t->_copyCreated((*reinterpret_cast< CCopy*(*)>(_a[1]))); break;
        case 5: _t->_copyApplied((*reinterpret_cast< CCopy*(*)>(_a[1]))); break;
        case 6: _t->_copyTransformed((*reinterpret_cast< CCopy*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CopyController::*_t)(CCopy * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CopyController::copyCreated)) {
                *result = 0;
            }
        }
        {
            typedef void (CopyController::*_t)(CCopy * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CopyController::copyApplied)) {
                *result = 1;
            }
        }
        {
            typedef void (CopyController::*_t)(CCopy * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CopyController::copyTransformed)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject CopyController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CopyController.data,
      qt_meta_data_CopyController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CopyController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CopyController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CopyController.stringdata0))
        return static_cast<void*>(const_cast< CopyController*>(this));
    return QObject::qt_metacast(_clname);
}

int CopyController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void CopyController::copyCreated(CCopy * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CopyController::copyApplied(CCopy * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CopyController::copyTransformed(CCopy * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
