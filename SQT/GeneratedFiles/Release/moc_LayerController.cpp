/****************************************************************************
** Meta object code from reading C++ file 'LayerController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Layer/LayerController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LayerController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CLayerController_t {
    QByteArrayData data[18];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CLayerController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CLayerController_t qt_meta_stringdata_CLayerController = {
    {
QT_MOC_LITERAL(0, 0, 16), // "CLayerController"
QT_MOC_LITERAL(1, 17, 12), // "layerCreated"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "CLayer*"
QT_MOC_LITERAL(4, 39, 12), // "layerDeleted"
QT_MOC_LITERAL(5, 52, 18), // "firstLayerSelected"
QT_MOC_LITERAL(6, 71, 20), // "firstLayerUnselected"
QT_MOC_LITERAL(7, 92, 12), // "onlyOneLayer"
QT_MOC_LITERAL(8, 105, 16), // "moreThanOneLayer"
QT_MOC_LITERAL(9, 122, 11), // "createLayer"
QT_MOC_LITERAL(10, 134, 12), // "sf::Texture*"
QT_MOC_LITERAL(11, 147, 11), // "texture_var"
QT_MOC_LITERAL(12, 159, 11), // "selectLayer"
QT_MOC_LITERAL(13, 171, 5), // "layer"
QT_MOC_LITERAL(14, 177, 11), // "deleteLayer"
QT_MOC_LITERAL(15, 189, 9), // "fuseLayer"
QT_MOC_LITERAL(16, 199, 9), // "layer_src"
QT_MOC_LITERAL(17, 209, 9) // "layer_dst"

    },
    "CLayerController\0layerCreated\0\0CLayer*\0"
    "layerDeleted\0firstLayerSelected\0"
    "firstLayerUnselected\0onlyOneLayer\0"
    "moreThanOneLayer\0createLayer\0sf::Texture*\0"
    "texture_var\0selectLayer\0layer\0deleteLayer\0"
    "fuseLayer\0layer_src\0layer_dst"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CLayerController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       6,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,
       5,    1,   90,    2, 0x06 /* Public */,
       6,    1,   93,    2, 0x06 /* Public */,
       7,    0,   96,    2, 0x06 /* Public */,
       8,    0,   97,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    1,   98,    2, 0x0a /* Public */,
       9,    0,  101,    2, 0x2a /* Public | MethodCloned */,
      12,    1,  102,    2, 0x0a /* Public */,
      12,    0,  105,    2, 0x2a /* Public | MethodCloned */,
      14,    1,  106,    2, 0x0a /* Public */,
      14,    0,  109,    2, 0x2a /* Public | MethodCloned */,
      15,    2,  110,    2, 0x0a /* Public */,
      15,    0,  115,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 10,   11,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,   13,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 3,   16,   17,
    QMetaType::Void,

       0        // eod
};

void CLayerController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CLayerController *_t = static_cast<CLayerController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->layerCreated((*reinterpret_cast< CLayer*(*)>(_a[1]))); break;
        case 1: _t->layerDeleted((*reinterpret_cast< CLayer*(*)>(_a[1]))); break;
        case 2: _t->firstLayerSelected((*reinterpret_cast< CLayer*(*)>(_a[1]))); break;
        case 3: _t->firstLayerUnselected((*reinterpret_cast< CLayer*(*)>(_a[1]))); break;
        case 4: _t->onlyOneLayer(); break;
        case 5: _t->moreThanOneLayer(); break;
        case 6: _t->createLayer((*reinterpret_cast< sf::Texture*(*)>(_a[1]))); break;
        case 7: _t->createLayer(); break;
        case 8: _t->selectLayer((*reinterpret_cast< CLayer*(*)>(_a[1]))); break;
        case 9: _t->selectLayer(); break;
        case 10: _t->deleteLayer((*reinterpret_cast< CLayer*(*)>(_a[1]))); break;
        case 11: _t->deleteLayer(); break;
        case 12: _t->fuseLayer((*reinterpret_cast< CLayer*(*)>(_a[1])),(*reinterpret_cast< CLayer*(*)>(_a[2]))); break;
        case 13: _t->fuseLayer(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CLayerController::*_t)(CLayer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLayerController::layerCreated)) {
                *result = 0;
            }
        }
        {
            typedef void (CLayerController::*_t)(CLayer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLayerController::layerDeleted)) {
                *result = 1;
            }
        }
        {
            typedef void (CLayerController::*_t)(CLayer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLayerController::firstLayerSelected)) {
                *result = 2;
            }
        }
        {
            typedef void (CLayerController::*_t)(CLayer * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLayerController::firstLayerUnselected)) {
                *result = 3;
            }
        }
        {
            typedef void (CLayerController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLayerController::onlyOneLayer)) {
                *result = 4;
            }
        }
        {
            typedef void (CLayerController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CLayerController::moreThanOneLayer)) {
                *result = 5;
            }
        }
    }
}

const QMetaObject CLayerController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CLayerController.data,
      qt_meta_data_CLayerController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CLayerController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CLayerController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CLayerController.stringdata0))
        return static_cast<void*>(const_cast< CLayerController*>(this));
    return QObject::qt_metacast(_clname);
}

int CLayerController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void CLayerController::layerCreated(CLayer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CLayerController::layerDeleted(CLayer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CLayerController::firstLayerSelected(CLayer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void CLayerController::firstLayerUnselected(CLayer * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void CLayerController::onlyOneLayer()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void CLayerController::moreThanOneLayer()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
