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
    QByteArrayData data[20];
    char stringdata0[187];
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
QT_MOC_LITERAL(4, 35, 13), // "layerSelected"
QT_MOC_LITERAL(5, 49, 15), // "layerUnselected"
QT_MOC_LITERAL(6, 65, 12), // "layerDropped"
QT_MOC_LITERAL(7, 78, 14), // "layerUndropped"
QT_MOC_LITERAL(8, 93, 10), // "layerMoved"
QT_MOC_LITERAL(9, 104, 12), // "sf::Vector2f"
QT_MOC_LITERAL(10, 117, 3), // "pos"
QT_MOC_LITERAL(11, 121, 11), // "layerScaled"
QT_MOC_LITERAL(12, 133, 4), // "size"
QT_MOC_LITERAL(13, 138, 10), // "emitStatus"
QT_MOC_LITERAL(14, 149, 4), // "show"
QT_MOC_LITERAL(15, 154, 4), // "hide"
QT_MOC_LITERAL(16, 159, 6), // "select"
QT_MOC_LITERAL(17, 166, 8), // "unselect"
QT_MOC_LITERAL(18, 175, 4), // "drop"
QT_MOC_LITERAL(19, 180, 6) // "undrop"

    },
    "Layer\0layerVisible\0\0layerUnvisible\0"
    "layerSelected\0layerUnselected\0"
    "layerDropped\0layerUndropped\0layerMoved\0"
    "sf::Vector2f\0pos\0layerScaled\0size\0"
    "emitStatus\0show\0hide\0select\0unselect\0"
    "drop\0undrop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Layer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x06 /* Public */,
       3,    0,   90,    2, 0x06 /* Public */,
       4,    0,   91,    2, 0x06 /* Public */,
       5,    0,   92,    2, 0x06 /* Public */,
       6,    0,   93,    2, 0x06 /* Public */,
       7,    0,   94,    2, 0x06 /* Public */,
       8,    1,   95,    2, 0x06 /* Public */,
      11,    1,   98,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      13,    0,  101,    2, 0x0a /* Public */,
      14,    0,  102,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x0a /* Public */,
      16,    0,  104,    2, 0x0a /* Public */,
      17,    0,  105,    2, 0x0a /* Public */,
      18,    0,  106,    2, 0x0a /* Public */,
      19,    0,  107,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   12,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
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
        case 2: _t->layerSelected(); break;
        case 3: _t->layerUnselected(); break;
        case 4: _t->layerDropped(); break;
        case 5: _t->layerUndropped(); break;
        case 6: _t->layerMoved((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 7: _t->layerScaled((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 8: _t->emitStatus(); break;
        case 9: _t->show(); break;
        case 10: _t->hide(); break;
        case 11: _t->select(); break;
        case 12: _t->unselect(); break;
        case 13: _t->drop(); break;
        case 14: _t->undrop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Layer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerVisible)) {
                *result = 0;
            }
        }
        {
            typedef void (Layer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerUnvisible)) {
                *result = 1;
            }
        }
        {
            typedef void (Layer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerSelected)) {
                *result = 2;
            }
        }
        {
            typedef void (Layer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerUnselected)) {
                *result = 3;
            }
        }
        {
            typedef void (Layer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerDropped)) {
                *result = 4;
            }
        }
        {
            typedef void (Layer::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerUndropped)) {
                *result = 5;
            }
        }
        {
            typedef void (Layer::*_t)(sf::Vector2f );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerMoved)) {
                *result = 6;
            }
        }
        {
            typedef void (Layer::*_t)(sf::Vector2f );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Layer::layerScaled)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject Layer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Layer.data,
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
    return QObject::qt_metacast(_clname);
}

int Layer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}

// SIGNAL 0
void Layer::layerVisible()
{
    QMetaObject::activate(this, &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void Layer::layerUnvisible()
{
    QMetaObject::activate(this, &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Layer::layerSelected()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Layer::layerUnselected()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Layer::layerDropped()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void Layer::layerUndropped()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void Layer::layerMoved(sf::Vector2f _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void Layer::layerScaled(sf::Vector2f _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
