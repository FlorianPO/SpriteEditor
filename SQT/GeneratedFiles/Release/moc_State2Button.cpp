/****************************************************************************
** Meta object code from reading C++ file 'State2Button.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Widget/Various/StateButton/State2Button.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'State2Button.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_State2Button_t {
    QByteArrayData data[7];
    char stringdata0[60];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_State2Button_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_State2Button_t qt_meta_stringdata_State2Button = {
    {
QT_MOC_LITERAL(0, 0, 12), // "State2Button"
QT_MOC_LITERAL(1, 13, 7), // "enabled"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 8), // "disabled"
QT_MOC_LITERAL(4, 31, 13), // "buttonClicked"
QT_MOC_LITERAL(5, 45, 6), // "enable"
QT_MOC_LITERAL(6, 52, 7) // "disable"

    },
    "State2Button\0enabled\0\0disabled\0"
    "buttonClicked\0enable\0disable"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_State2Button[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,   41,    2, 0x08 /* Private */,
       5,    0,   42,    2, 0x0a /* Public */,
       6,    0,   43,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void State2Button::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        State2Button *_t = static_cast<State2Button *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->enabled(); break;
        case 1: _t->disabled(); break;
        case 2: _t->buttonClicked(); break;
        case 3: _t->enable(); break;
        case 4: _t->disable(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (State2Button::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State2Button::enabled)) {
                *result = 0;
            }
        }
        {
            typedef void (State2Button::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&State2Button::disabled)) {
                *result = 1;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject State2Button::staticMetaObject = {
    { &QPushButton::staticMetaObject, qt_meta_stringdata_State2Button.data,
      qt_meta_data_State2Button,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *State2Button::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *State2Button::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_State2Button.stringdata0))
        return static_cast<void*>(const_cast< State2Button*>(this));
    return QPushButton::qt_metacast(_clname);
}

int State2Button::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
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
void State2Button::enabled()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void State2Button::disabled()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
