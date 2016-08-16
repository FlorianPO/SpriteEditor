/****************************************************************************
** Meta object code from reading C++ file 'Copy.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Copy/Copy.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Copy.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Copy_t {
    QByteArrayData data[11];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Copy_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Copy_t qt_meta_stringdata_Copy = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Copy"
QT_MOC_LITERAL(1, 5, 9), // "copyMoved"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 12), // "sf::Vector2f"
QT_MOC_LITERAL(4, 29, 10), // "topLeftPos"
QT_MOC_LITERAL(5, 40, 10), // "copyScaled"
QT_MOC_LITERAL(6, 51, 4), // "size"
QT_MOC_LITERAL(7, 56, 11), // "copyRotated"
QT_MOC_LITERAL(8, 68, 5), // "angle"
QT_MOC_LITERAL(9, 74, 10), // "emitStatus"
QT_MOC_LITERAL(10, 85, 11) // "updateLines"

    },
    "Copy\0copyMoved\0\0sf::Vector2f\0topLeftPos\0"
    "copyScaled\0size\0copyRotated\0angle\0"
    "emitStatus\0updateLines"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Copy[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    1,   42,    2, 0x06 /* Public */,
       7,    1,   45,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    0,   48,    2, 0x0a /* Public */,

 // methods: name, argc, parameters, tag, flags
      10,    0,   49,    2, 0x00 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void, QMetaType::Float,    8,

 // slots: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,

       0        // eod
};

void Copy::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Copy *_t = static_cast<Copy *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->copyMoved((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 1: _t->copyScaled((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 2: _t->copyRotated((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->emitStatus(); break;
        case 4: _t->updateLines(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Copy::*_t)(sf::Vector2f );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Copy::copyMoved)) {
                *result = 0;
            }
        }
        {
            typedef void (Copy::*_t)(sf::Vector2f );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Copy::copyScaled)) {
                *result = 1;
            }
        }
        {
            typedef void (Copy::*_t)(float );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Copy::copyRotated)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject Copy::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Copy.data,
      qt_meta_data_Copy,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Copy::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Copy::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Copy.stringdata0))
        return static_cast<void*>(const_cast< Copy*>(this));
    return QObject::qt_metacast(_clname);
}

int Copy::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Copy::copyMoved(sf::Vector2f _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Copy::copyScaled(sf::Vector2f _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Copy::copyRotated(float _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
