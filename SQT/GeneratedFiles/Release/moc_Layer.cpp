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
struct qt_meta_stringdata_Layer_t {
    QByteArrayData data[14];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Layer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Layer_t qt_meta_stringdata_Layer = {
    {
QT_MOC_LITERAL(0, 0, 5), // "Layer"
QT_MOC_LITERAL(1, 6, 12), // "layerVisible"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 14), // "layerUnvisible"
QT_MOC_LITERAL(4, 35, 10), // "layerMoved"
QT_MOC_LITERAL(5, 46, 12), // "sf::Vector2f"
QT_MOC_LITERAL(6, 59, 3), // "pos"
QT_MOC_LITERAL(7, 63, 11), // "layerScaled"
QT_MOC_LITERAL(8, 75, 4), // "size"
QT_MOC_LITERAL(9, 80, 12), // "layerUpdated"
QT_MOC_LITERAL(10, 93, 11), // "nameChanged"
QT_MOC_LITERAL(11, 105, 10), // "emitStatus"
QT_MOC_LITERAL(12, 116, 4), // "show"
QT_MOC_LITERAL(13, 121, 4) // "hide"

    },
    "Layer\0layerVisible\0\0layerUnvisible\0"
    "layerMoved\0sf::Vector2f\0pos\0layerScaled\0"
    "size\0layerUpdated\0nameChanged\0emitStatus\0"
    "show\0hide"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Layer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    1,   61,    2, 0x06 /* Public */,
       7,    1,   64,    2, 0x06 /* Public */,
       9,    0,   67,    2, 0x06 /* Public */,
      10,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    0,   71,    2, 0x0a /* Public */,
      12,    0,   72,    2, 0x0a /* Public */,
      13,    0,   73,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 5,    8,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Layer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Layer *_t = static_cast<Layer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->layerVisible(); break;
        case 1: _t->layerUnvisible(); break;
        case 2: _t->layerMoved((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 3: _t->layerScaled((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 4: _t->layerUpdated(); break;
        case 5: _t->nameChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->emitStatus(); break;
        case 7: _t->show(); break;
        case 8: _t->hide(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Layer::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerVisible)) {
                *result = 0;
            }
        }
        {
            typedef void (Layer::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerUnvisible)) {
                *result = 1;
            }
        }
        {
            typedef void (Layer::*_t)(sf::Vector2f ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerMoved)) {
                *result = 2;
            }
        }
        {
            typedef void (Layer::*_t)(sf::Vector2f ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerScaled)) {
                *result = 3;
            }
        }
        {
            typedef void (Layer::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerUpdated)) {
                *result = 4;
            }
        }
        {
            typedef void (Layer::*_t)(QString ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::nameChanged)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject Layer::staticMetaObject = {
    { &SignalListObject::staticMetaObject, qt_meta_stringdata_Layer.data,
      qt_meta_data_Layer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Layer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Layer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Layer.stringdata0))
        return static_cast<void*>(const_cast< Layer*>(this));
    return SignalListObject::qt_metacast(_clname);
}

int Layer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SignalListObject::qt_metacall(_c, _id, _a);
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
void Layer::layerVisible()const
{
    QMetaObject::activate(const_cast< Layer *>(this), &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Layer::layerUnvisible()const
{
    QMetaObject::activate(const_cast< Layer *>(this), &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Layer::layerMoved(sf::Vector2f _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Layer *>(this), &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Layer::layerScaled(sf::Vector2f _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Layer *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Layer::layerUpdated()const
{
    QMetaObject::activate(const_cast< Layer *>(this), &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Layer::nameChanged(QString _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Layer *>(this), &staticMetaObject, 5, _a);
}
QT_END_MOC_NAMESPACE
