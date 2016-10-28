/****************************************************************************
** Meta object code from reading C++ file 'AnimationController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Animation/AnimationController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AnimationController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AnimationController_t {
    QByteArrayData data[9];
    char stringdata0[100];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AnimationController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AnimationController_t qt_meta_stringdata_AnimationController = {
    {
QT_MOC_LITERAL(0, 0, 19), // "AnimationController"
QT_MOC_LITERAL(1, 20, 5), // "moved"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 12), // "sf::Vector2f"
QT_MOC_LITERAL(4, 40, 12), // "new_position"
QT_MOC_LITERAL(5, 53, 6), // "zoomed"
QT_MOC_LITERAL(6, 60, 10), // "new_factor"
QT_MOC_LITERAL(7, 71, 15), // "createAnimation"
QT_MOC_LITERAL(8, 87, 12) // "dropSelected"

    },
    "AnimationController\0moved\0\0sf::Vector2f\0"
    "new_position\0zoomed\0new_factor\0"
    "createAnimation\0dropSelected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AnimationController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x08 /* Private */,
       5,    1,   37,    2, 0x08 /* Private */,
       7,    0,   40,    2, 0x0a /* Public */,
       8,    0,   41,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Float,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AnimationController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AnimationController *_t = static_cast<AnimationController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moved((*reinterpret_cast< const sf::Vector2f(*)>(_a[1]))); break;
        case 1: _t->zoomed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 2: _t->createAnimation(); break;
        case 3: _t->dropSelected(); break;
        default: ;
        }
    }
}

const QMetaObject AnimationController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_AnimationController.data,
      qt_meta_data_AnimationController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *AnimationController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AnimationController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_AnimationController.stringdata0))
        return static_cast<void*>(const_cast< AnimationController*>(this));
    return QObject::qt_metacast(_clname);
}

int AnimationController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
