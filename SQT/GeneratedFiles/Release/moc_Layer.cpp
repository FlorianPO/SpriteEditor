/****************************************************************************
** Meta object code from reading C++ file 'Layer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Layer/Layer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Layer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CLayer_t {
    QByteArrayData data[13];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CLayer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CLayer_t qt_meta_stringdata_CLayer = {
    {
QT_MOC_LITERAL(0, 0, 6), // "CLayer"
QT_MOC_LITERAL(1, 7, 12), // "layerChanged"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 12), // "layerVisible"
QT_MOC_LITERAL(4, 34, 14), // "layerUnvisible"
QT_MOC_LITERAL(5, 49, 13), // "layerSelected"
QT_MOC_LITERAL(6, 63, 15), // "layerUnselected"
QT_MOC_LITERAL(7, 79, 12), // "layerDropped"
QT_MOC_LITERAL(8, 92, 4), // "show"
QT_MOC_LITERAL(9, 97, 4), // "hide"
QT_MOC_LITERAL(10, 102, 6), // "select"
QT_MOC_LITERAL(11, 109, 8), // "unselect"
QT_MOC_LITERAL(12, 118, 4) // "drop"

    },
    "CLayer\0layerChanged\0\0layerVisible\0"
    "layerUnvisible\0layerSelected\0"
    "layerUnselected\0layerDropped\0show\0"
    "hide\0select\0unselect\0drop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CLayer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x06 /* Public */,
       3,    0,   70,    2, 0x06 /* Public */,
       4,    0,   71,    2, 0x06 /* Public */,
       5,    0,   72,    2, 0x06 /* Public */,
       6,    0,   73,    2, 0x06 /* Public */,
       7,    0,   74,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   75,    2, 0x0a /* Public */,
       9,    0,   76,    2, 0x0a /* Public */,
      10,    0,   77,    2, 0x0a /* Public */,
      11,    0,   78,    2, 0x0a /* Public */,
      12,    0,   79,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
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
    QMetaType::Void,

       0        // eod
};

void CLayer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CLayer *_t = static_cast<CLayer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->layerChanged(); break;
        case 1: _t->layerVisible(); break;
        case 2: _t->layerUnvisible(); break;
        case 3: _t->layerSelected(); break;
        case 4: _t->layerUnselected(); break;
        case 5: _t->layerDropped(); break;
        case 6: _t->show(); break;
        case 7: _t->hide(); break;
        case 8: _t->select(); break;
        case 9: _t->unselect(); break;
        case 10: _t->drop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CLayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLayer::layerChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (CLayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLayer::layerVisible)) {
                *result = 1;
            }
        }
        {
            typedef void (CLayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLayer::layerUnvisible)) {
                *result = 2;
            }
        }
        {
            typedef void (CLayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLayer::layerSelected)) {
                *result = 3;
            }
        }
        {
            typedef void (CLayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLayer::layerUnselected)) {
                *result = 4;
            }
        }
        {
            typedef void (CLayer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLayer::layerDropped)) {
                *result = 5;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CLayer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CLayer.data,
      qt_meta_data_CLayer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CLayer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CLayer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CLayer.stringdata0))
        return static_cast<void*>(const_cast< CLayer*>(this));
    return QObject::qt_metacast(_clname);
}

int CLayer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void CLayer::layerChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void CLayer::layerVisible()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void CLayer::layerUnvisible()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void CLayer::layerSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void CLayer::layerUnselected()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void CLayer::layerDropped()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
