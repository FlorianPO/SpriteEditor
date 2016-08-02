/****************************************************************************
** Meta object code from reading C++ file 'CopyController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Copy/CopyController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CopyController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CopyController_t {
    QByteArrayData data[17];
    char stringdata0[152];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CopyController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CopyController_t qt_meta_stringdata_CopyController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "CopyController"
QT_MOC_LITERAL(1, 15, 11), // "copyCreated"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "Copy*"
QT_MOC_LITERAL(4, 34, 11), // "copyDeleted"
QT_MOC_LITERAL(5, 46, 11), // "copyDropped"
QT_MOC_LITERAL(6, 58, 4), // "copy"
QT_MOC_LITERAL(7, 63, 3), // "cut"
QT_MOC_LITERAL(8, 67, 5), // "paste"
QT_MOC_LITERAL(9, 73, 10), // "createCopy"
QT_MOC_LITERAL(10, 84, 9), // "sf::Image"
QT_MOC_LITERAL(11, 94, 5), // "image"
QT_MOC_LITERAL(12, 100, 12), // "sf::Vector2f"
QT_MOC_LITERAL(13, 113, 8), // "position"
QT_MOC_LITERAL(14, 122, 10), // "deleteCopy"
QT_MOC_LITERAL(15, 133, 9), // "applyCopy"
QT_MOC_LITERAL(16, 143, 8) // "dropCopy"

    },
    "CopyController\0copyCreated\0\0Copy*\0"
    "copyDeleted\0copyDropped\0copy\0cut\0paste\0"
    "createCopy\0sf::Image\0image\0sf::Vector2f\0"
    "position\0deleteCopy\0applyCopy\0dropCopy"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CopyController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   79,    2, 0x06 /* Public */,
       4,    1,   82,    2, 0x06 /* Public */,
       5,    1,   85,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   88,    2, 0x0a /* Public */,
       7,    0,   89,    2, 0x0a /* Public */,
       8,    0,   90,    2, 0x0a /* Public */,
       9,    2,   91,    2, 0x0a /* Public */,
      14,    1,   96,    2, 0x0a /* Public */,
      14,    0,   99,    2, 0x2a /* Public | MethodCloned */,
      15,    1,  100,    2, 0x0a /* Public */,
      15,    0,  103,    2, 0x2a /* Public | MethodCloned */,
      16,    1,  104,    2, 0x0a /* Public */,
      16,    0,  107,    2, 0x2a /* Public | MethodCloned */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 10, 0x80000000 | 12,   11,   13,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    6,
    QMetaType::Void,

       0        // eod
};

void CopyController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CopyController *_t = static_cast<CopyController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->copyCreated((*reinterpret_cast< Copy*(*)>(_a[1]))); break;
        case 1: _t->copyDeleted((*reinterpret_cast< Copy*(*)>(_a[1]))); break;
        case 2: _t->copyDropped((*reinterpret_cast< Copy*(*)>(_a[1]))); break;
        case 3: _t->copy(); break;
        case 4: _t->cut(); break;
        case 5: _t->paste(); break;
        case 6: _t->createCopy((*reinterpret_cast< const sf::Image(*)>(_a[1])),(*reinterpret_cast< sf::Vector2f(*)>(_a[2]))); break;
        case 7: _t->deleteCopy((*reinterpret_cast< Copy*(*)>(_a[1]))); break;
        case 8: _t->deleteCopy(); break;
        case 9: _t->applyCopy((*reinterpret_cast< Copy*(*)>(_a[1]))); break;
        case 10: _t->applyCopy(); break;
        case 11: _t->dropCopy((*reinterpret_cast< Copy*(*)>(_a[1]))); break;
        case 12: _t->dropCopy(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CopyController::*_t)(Copy * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CopyController::copyCreated)) {
                *result = 0;
            }
        }
        {
            typedef void (CopyController::*_t)(Copy * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CopyController::copyDeleted)) {
                *result = 1;
            }
        }
        {
            typedef void (CopyController::*_t)(Copy * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CopyController::copyDropped)) {
                *result = 2;
            }
        }
    }
}

const QMetaObject CopyController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CopyController.data,
      qt_meta_data_CopyController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CopyController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CopyController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CopyController.stringdata0))
        return static_cast<void*>(const_cast< CopyController*>(this));
    return QObject::qt_metacast(_clname);
}

int CopyController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 13)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 13;
    }
    return _id;
}

// SIGNAL 0
void CopyController::copyCreated(Copy * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void CopyController::copyDeleted(Copy * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void CopyController::copyDropped(Copy * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_END_MOC_NAMESPACE
