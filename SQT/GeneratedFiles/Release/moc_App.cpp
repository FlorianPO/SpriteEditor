/****************************************************************************
** Meta object code from reading C++ file 'App.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/App.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'App.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_App_t {
    QByteArrayData data[9];
    char stringdata0[86];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_App_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_App_t qt_meta_stringdata_App = {
    {
QT_MOC_LITERAL(0, 0, 3), // "App"
QT_MOC_LITERAL(1, 4, 10), // "cadreMoved"
QT_MOC_LITERAL(2, 15, 0), // ""
QT_MOC_LITERAL(3, 16, 11), // "cadreScaled"
QT_MOC_LITERAL(4, 28, 12), // "cameraZoomed"
QT_MOC_LITERAL(5, 41, 11), // "zoom_factor"
QT_MOC_LITERAL(6, 53, 11), // "cameraMoved"
QT_MOC_LITERAL(7, 65, 9), // "gererFond"
QT_MOC_LITERAL(8, 75, 10) // "gererLines"

    },
    "App\0cadreMoved\0\0cadreScaled\0cameraZoomed\0"
    "zoom_factor\0cameraMoved\0gererFond\0"
    "gererLines"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_App[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    1,   46,    2, 0x08 /* Private */,
       6,    0,   49,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
       7,    0,   50,    2, 0x00 /* Private */,
       8,    0,   51,    2, 0x00 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Float,    5,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void App::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        App *_t = static_cast<App *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->cadreMoved(); break;
        case 1: _t->cadreScaled(); break;
        case 2: _t->cameraZoomed((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->cameraMoved(); break;
        case 4: _t->gererFond(); break;
        case 5: _t->gererLines(); break;
        default: ;
        }
    }
}

const QMetaObject App::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_App.data,
      qt_meta_data_App,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *App::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *App::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_App.stringdata0))
        return static_cast<void*>(const_cast< App*>(this));
    return QObject::qt_metacast(_clname);
}

int App::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
