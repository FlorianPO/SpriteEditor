/****************************************************************************
** Meta object code from reading C++ file 'AnimationRect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Animation/AnimationRect/AnimationRect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnimationRect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AnimationRect_t {
    QByteArrayData data[13];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnimationRect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnimationRect_t qt_meta_stringdata_AnimationRect = {
    {
QT_MOC_LITERAL(0, 0, 13), // "AnimationRect"
QT_MOC_LITERAL(1, 14, 11), // "rectChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "sf::IntRect"
QT_MOC_LITERAL(4, 39, 4), // "rect"
QT_MOC_LITERAL(5, 44, 12), // "frameChanged"
QT_MOC_LITERAL(6, 57, 16), // "animationVisible"
QT_MOC_LITERAL(7, 74, 18), // "animationUnvisible"
QT_MOC_LITERAL(8, 93, 7), // "setRect"
QT_MOC_LITERAL(9, 101, 8), // "setFrame"
QT_MOC_LITERAL(10, 110, 5), // "frame"
QT_MOC_LITERAL(11, 116, 4), // "show"
QT_MOC_LITERAL(12, 121, 4) // "hide"

    },
    "AnimationRect\0rectChanged\0\0sf::IntRect\0"
    "rect\0frameChanged\0animationVisible\0"
    "animationUnvisible\0setRect\0setFrame\0"
    "frame\0show\0hide"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnimationRect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,
       6,    0,   60,    2, 0x06 /* Public */,
       7,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   62,    2, 0x0a /* Public */,
       9,    1,   65,    2, 0x0a /* Public */,
      11,    0,   68,    2, 0x0a /* Public */,
      12,    0,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AnimationRect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnimationRect *_t = static_cast<AnimationRect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->rectChanged((*reinterpret_cast< const sf::IntRect(*)>(_a[1]))); break;
        case 1: _t->frameChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->animationVisible(); break;
        case 3: _t->animationUnvisible(); break;
        case 4: _t->setRect((*reinterpret_cast< const sf::IntRect(*)>(_a[1]))); break;
        case 5: _t->setFrame((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->show(); break;
        case 7: _t->hide(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (AnimationRect::*_t)(const sf::IntRect & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimationRect::rectChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (AnimationRect::*_t)(int ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimationRect::frameChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (AnimationRect::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimationRect::animationVisible)) {
                *result = 2;
            }
        }
        {
            typedef void (AnimationRect::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&AnimationRect::animationUnvisible)) {
                *result = 3;
            }
        }
    }
}

const QMetaObject AnimationRect::staticMetaObject = {
    { &SignalListObject::staticMetaObject, qt_meta_stringdata_AnimationRect.data,
      qt_meta_data_AnimationRect,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AnimationRect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnimationRect::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AnimationRect.stringdata0))
        return static_cast<void*>(const_cast< AnimationRect*>(this));
    return SignalListObject::qt_metacast(_clname);
}

int AnimationRect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SignalListObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void AnimationRect::rectChanged(const sf::IntRect & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< AnimationRect *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AnimationRect::frameChanged(int _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< AnimationRect *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void AnimationRect::animationVisible()const
{
    QMetaObject::activate(const_cast< AnimationRect *>(this), &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void AnimationRect::animationUnvisible()const
{
    QMetaObject::activate(const_cast< AnimationRect *>(this), &staticMetaObject, 3, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
