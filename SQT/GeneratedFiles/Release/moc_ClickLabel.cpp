/****************************************************************************
** Meta object code from reading C++ file 'ClickLabel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Widget/Various/Label/ClickLabel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ClickLabel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ClickLabel_t {
    QByteArrayData data[8];
    char stringdata0[64];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ClickLabel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ClickLabel_t qt_meta_stringdata_ClickLabel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ClickLabel"
QT_MOC_LITERAL(1, 11, 12), // "valueChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 5), // "value"
QT_MOC_LITERAL(4, 31, 7), // "focusIn"
QT_MOC_LITERAL(5, 39, 8), // "focusOut"
QT_MOC_LITERAL(6, 48, 3), // "run"
QT_MOC_LITERAL(7, 52, 11) // "changeValue"

    },
    "ClickLabel\0valueChanged\0\0value\0focusIn\0"
    "focusOut\0run\0changeValue"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ClickLabel[] = {

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
       4,    0,   42,    2, 0x06 /* Public */,
       5,    0,   43,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   44,    2, 0x08 /* Private */,
       7,    1,   45,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void ClickLabel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ClickLabel *_t = static_cast<ClickLabel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->focusIn(); break;
        case 2: _t->focusOut(); break;
        case 3: _t->run(); break;
        case 4: _t->changeValue((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ClickLabel::*_t)(int ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClickLabel::valueChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (ClickLabel::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClickLabel::focusIn)) {
                *result = 1;
            }
        }
        {
            typedef void (ClickLabel::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ClickLabel::focusOut)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject ClickLabel::staticMetaObject = {
    { &ViewLabel::staticMetaObject, qt_meta_stringdata_ClickLabel.data,
      qt_meta_data_ClickLabel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ClickLabel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClickLabel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ClickLabel.stringdata0))
        return static_cast<void*>(const_cast< ClickLabel*>(this));
    return ViewLabel::qt_metacast(_clname);
}

int ClickLabel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ViewLabel::qt_metacall(_c, _id, _a);
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
void ClickLabel::valueChanged(int _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< ClickLabel *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ClickLabel::focusIn()const
{
    QMetaObject::activate(const_cast< ClickLabel *>(this), &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ClickLabel::focusOut()const
{
    QMetaObject::activate(const_cast< ClickLabel *>(this), &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
