/****************************************************************************
** Meta object code from reading C++ file 'CameraController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Camera/CameraController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CameraController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CameraController_t {
    QByteArrayData data[7];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CameraController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CameraController_t qt_meta_stringdata_CameraController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CameraController"
QT_MOC_LITERAL(1, 17, 5), // "moved"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "sf::Vector2f"
QT_MOC_LITERAL(4, 37, 8), // "position"
QT_MOC_LITERAL(5, 46, 6), // "zoomed"
QT_MOC_LITERAL(6, 53, 11) // "zoom_factor"

    },
    "CameraController\0moved\0\0sf::Vector2f\0"
    "position\0zoomed\0zoom_factor"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CameraController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x06 /* Public */,
       5,    1,   27,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, QMetaType::Float,    6,

       0        // eod
};

void CameraController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CameraController *_t = static_cast<CameraController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->moved((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 1: _t->zoomed((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CameraController::*_t)(sf::Vector2f ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraController::moved)) {
                *result = 0;
            }
        }
        {
            typedef void (CameraController::*_t)(float ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CameraController::zoomed)) {
                *result = 1;
            }
        }
    }
}

const QMetaObject CameraController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CameraController.data,
      qt_meta_data_CameraController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CameraController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CameraController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CameraController.stringdata0))
        return static_cast<void*>(const_cast< CameraController*>(this));
    if (!strcmp(_clname, "sf::View"))
        return static_cast< sf::View*>(const_cast< CameraController*>(this));
    return QObject::qt_metacast(_clname);
}

int CameraController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void CameraController::moved(sf::Vector2f _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< CameraController *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CameraController::zoomed(float _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< CameraController *>(this), &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE
