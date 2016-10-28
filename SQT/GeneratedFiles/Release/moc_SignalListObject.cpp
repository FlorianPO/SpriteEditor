/****************************************************************************
** Meta object code from reading C++ file 'SignalListObject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/SignalType/SignalListObject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SignalListObject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SignalListObject_t {
    QByteArrayData data[11];
    char stringdata0[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SignalListObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SignalListObject_t qt_meta_stringdata_SignalListObject = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SignalListObject"
QT_MOC_LITERAL(1, 17, 7), // "deleted"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 7), // "dropped"
QT_MOC_LITERAL(4, 34, 9), // "undropped"
QT_MOC_LITERAL(5, 44, 8), // "selected"
QT_MOC_LITERAL(6, 53, 10), // "unselected"
QT_MOC_LITERAL(7, 64, 4), // "drop"
QT_MOC_LITERAL(8, 69, 6), // "undrop"
QT_MOC_LITERAL(9, 76, 6), // "select"
QT_MOC_LITERAL(10, 83, 8) // "unselect"

    },
    "SignalListObject\0deleted\0\0dropped\0"
    "undropped\0selected\0unselected\0drop\0"
    "undrop\0select\0unselect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SignalListObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,
       5,    0,   62,    2, 0x06 /* Public */,
       6,    0,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    0,   64,    2, 0x0a /* Public */,
       8,    0,   65,    2, 0x0a /* Public */,
       9,    0,   66,    2, 0x0a /* Public */,
      10,    0,   67,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void SignalListObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SignalListObject *_t = static_cast<SignalListObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleted(); break;
        case 1: _t->dropped(); break;
        case 2: _t->undropped(); break;
        case 3: _t->selected(); break;
        case 4: _t->unselected(); break;
        case 5: _t->drop(); break;
        case 6: _t->undrop(); break;
        case 7: _t->select(); break;
        case 8: _t->unselect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SignalListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignalListObject::deleted)) {
                *result = 0;
            }
        }
        {
            typedef void (SignalListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignalListObject::dropped)) {
                *result = 1;
            }
        }
        {
            typedef void (SignalListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignalListObject::undropped)) {
                *result = 2;
            }
        }
        {
            typedef void (SignalListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignalListObject::selected)) {
                *result = 3;
            }
        }
        {
            typedef void (SignalListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SignalListObject::unselected)) {
                *result = 4;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject SignalListObject::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SignalListObject.data,
      qt_meta_data_SignalListObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SignalListObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SignalListObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SignalListObject.stringdata0))
        return static_cast<void*>(const_cast< SignalListObject*>(this));
    return QObject::qt_metacast(_clname);
}

int SignalListObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void SignalListObject::deleted()const
{
    QMetaObject::activate(const_cast< SignalListObject *>(this), &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void SignalListObject::dropped()const
{
    QMetaObject::activate(const_cast< SignalListObject *>(this), &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void SignalListObject::undropped()const
{
    QMetaObject::activate(const_cast< SignalListObject *>(this), &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void SignalListObject::selected()const
{
    QMetaObject::activate(const_cast< SignalListObject *>(this), &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void SignalListObject::unselected()const
{
    QMetaObject::activate(const_cast< SignalListObject *>(this), &staticMetaObject, 4, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
