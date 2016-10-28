/****************************************************************************
** Meta object code from reading C++ file 'SelectionController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Selection/SelectionController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SelectionController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SelectionController_t {
    QByteArrayData data[30];
    char stringdata0[400];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SelectionController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SelectionController_t qt_meta_stringdata_SelectionController = {
    {
QT_MOC_LITERAL(0, 0, 19), // "SelectionController"
QT_MOC_LITERAL(1, 20, 16), // "selectionUpdated"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 4), // "mode"
QT_MOC_LITERAL(4, 43, 16), // "selectionCreated"
QT_MOC_LITERAL(5, 60, 16), // "selectionDeleted"
QT_MOC_LITERAL(6, 77, 17), // "selectionInverted"
QT_MOC_LITERAL(7, 95, 19), // "selectionUninverted"
QT_MOC_LITERAL(8, 115, 14), // "selectionMoved"
QT_MOC_LITERAL(9, 130, 12), // "sf::Vector2f"
QT_MOC_LITERAL(10, 143, 15), // "selectionScaled"
QT_MOC_LITERAL(11, 159, 15), // "createSelection"
QT_MOC_LITERAL(12, 175, 11), // "sf::IntRect"
QT_MOC_LITERAL(13, 187, 4), // "rect"
QT_MOC_LITERAL(14, 192, 25), // "std::vector<nSet::o_line>"
QT_MOC_LITERAL(15, 218, 6), // "conf_l"
QT_MOC_LITERAL(16, 225, 9), // "sf::Image"
QT_MOC_LITERAL(17, 235, 5), // "image"
QT_MOC_LITERAL(18, 241, 15), // "deleteSelection"
QT_MOC_LITERAL(19, 257, 5), // "force"
QT_MOC_LITERAL(20, 263, 12), // "addSelection"
QT_MOC_LITERAL(21, 276, 12), // "subSelection"
QT_MOC_LITERAL(22, 289, 18), // "intersectSelection"
QT_MOC_LITERAL(23, 308, 15), // "invertSelection"
QT_MOC_LITERAL(24, 324, 17), // "uninvertSelection"
QT_MOC_LITERAL(25, 342, 11), // "deleteLayer"
QT_MOC_LITERAL(26, 354, 16), // "const sf::Image*"
QT_MOC_LITERAL(27, 371, 12), // "sumSelection"
QT_MOC_LITERAL(28, 384, 3), // "add"
QT_MOC_LITERAL(29, 388, 11) // "updateLines"

    },
    "SelectionController\0selectionUpdated\0"
    "\0mode\0selectionCreated\0selectionDeleted\0"
    "selectionInverted\0selectionUninverted\0"
    "selectionMoved\0sf::Vector2f\0selectionScaled\0"
    "createSelection\0sf::IntRect\0rect\0"
    "std::vector<nSet::o_line>\0conf_l\0"
    "sf::Image\0image\0deleteSelection\0force\0"
    "addSelection\0subSelection\0intersectSelection\0"
    "invertSelection\0uninvertSelection\0"
    "deleteLayer\0const sf::Image*\0sumSelection\0"
    "add\0updateLines"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SelectionController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      25,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  139,    2, 0x06 /* Public */,
       1,    0,  142,    2, 0x26 /* Public | MethodCloned */,
       4,    0,  143,    2, 0x06 /* Public */,
       5,    0,  144,    2, 0x06 /* Public */,
       6,    0,  145,    2, 0x06 /* Public */,
       7,    0,  146,    2, 0x06 /* Public */,
       8,    1,  147,    2, 0x06 /* Public */,
      10,    1,  150,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      11,    2,  153,    2, 0x0a /* Public */,
      11,    3,  158,    2, 0x0a /* Public */,
      18,    1,  165,    2, 0x0a /* Public */,
      18,    0,  168,    2, 0x2a /* Public | MethodCloned */,
      20,    2,  169,    2, 0x0a /* Public */,
      20,    3,  174,    2, 0x0a /* Public */,
      21,    2,  181,    2, 0x0a /* Public */,
      21,    3,  186,    2, 0x0a /* Public */,
      22,    2,  193,    2, 0x0a /* Public */,
      22,    3,  198,    2, 0x0a /* Public */,
      23,    0,  205,    2, 0x0a /* Public */,
      24,    0,  206,    2, 0x0a /* Public */,
      25,    0,  207,    2, 0x0a /* Public */,
      11,    2,  208,    2, 0x08 /* Private */,
      27,    3,  213,    2, 0x08 /* Private */,
      22,    2,  220,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      29,    0,  225,    2, 0x00 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 9,    2,
    QMetaType::Void, 0x80000000 | 9,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,   15,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 16, 0x80000000 | 14,   13,   17,   15,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,   15,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 16, 0x80000000 | 14,   13,   17,   15,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,   15,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 16, 0x80000000 | 14,   13,   17,   15,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 14,   13,   15,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 16, 0x80000000 | 14,   13,   17,   15,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 26,   13,   17,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 26, QMetaType::Bool,   13,   17,   28,
    QMetaType::Void, 0x80000000 | 12, 0x80000000 | 26,   13,   17,

 // methods: parameters
    QMetaType::Void,

       0        // eod
};

void SelectionController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SelectionController *_t = static_cast<SelectionController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->selectionUpdated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->selectionUpdated(); break;
        case 2: _t->selectionCreated(); break;
        case 3: _t->selectionDeleted(); break;
        case 4: _t->selectionInverted(); break;
        case 5: _t->selectionUninverted(); break;
        case 6: _t->selectionMoved((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 7: _t->selectionScaled((*reinterpret_cast< sf::Vector2f(*)>(_a[1]))); break;
        case 8: _t->createSelection((*reinterpret_cast< const sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[2]))); break;
        case 9: _t->createSelection((*reinterpret_cast< const sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image(*)>(_a[2])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[3]))); break;
        case 10: _t->deleteSelection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 11: _t->deleteSelection(); break;
        case 12: _t->addSelection((*reinterpret_cast< const sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[2]))); break;
        case 13: _t->addSelection((*reinterpret_cast< const sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image(*)>(_a[2])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[3]))); break;
        case 14: _t->subSelection((*reinterpret_cast< const sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[2]))); break;
        case 15: _t->subSelection((*reinterpret_cast< const sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image(*)>(_a[2])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[3]))); break;
        case 16: _t->intersectSelection((*reinterpret_cast< const sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[2]))); break;
        case 17: _t->intersectSelection((*reinterpret_cast< const sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image(*)>(_a[2])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[3]))); break;
        case 18: _t->invertSelection(); break;
        case 19: _t->uninvertSelection(); break;
        case 20: _t->deleteLayer(); break;
        case 21: _t->createSelection((*reinterpret_cast< const sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image*(*)>(_a[2]))); break;
        case 22: _t->sumSelection((*reinterpret_cast< const sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 23: _t->intersectSelection((*reinterpret_cast< const sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image*(*)>(_a[2]))); break;
        case 24: _t->updateLines(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SelectionController::*_t)(int ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::selectionUpdated)) {
                *result = 0;
            }
        }
        {
            typedef void (SelectionController::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::selectionCreated)) {
                *result = 2;
            }
        }
        {
            typedef void (SelectionController::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::selectionDeleted)) {
                *result = 3;
            }
        }
        {
            typedef void (SelectionController::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::selectionInverted)) {
                *result = 4;
            }
        }
        {
            typedef void (SelectionController::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::selectionUninverted)) {
                *result = 5;
            }
        }
        {
            typedef void (SelectionController::*_t)(sf::Vector2f ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::selectionMoved)) {
                *result = 6;
            }
        }
        {
            typedef void (SelectionController::*_t)(sf::Vector2f ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::selectionScaled)) {
                *result = 7;
            }
        }
    }
}

const QMetaObject SelectionController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SelectionController.data,
      qt_meta_data_SelectionController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SelectionController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SelectionController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SelectionController.stringdata0))
        return static_cast<void*>(const_cast< SelectionController*>(this));
    return QObject::qt_metacast(_clname);
}

int SelectionController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 25)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 25;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 25)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 25;
    }
    return _id;
}

// SIGNAL 0
void SelectionController::selectionUpdated(int _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< SelectionController *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 2
void SelectionController::selectionCreated()const
{
    QMetaObject::activate(const_cast< SelectionController *>(this), &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void SelectionController::selectionDeleted()const
{
    QMetaObject::activate(const_cast< SelectionController *>(this), &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void SelectionController::selectionInverted()const
{
    QMetaObject::activate(const_cast< SelectionController *>(this), &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void SelectionController::selectionUninverted()const
{
    QMetaObject::activate(const_cast< SelectionController *>(this), &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void SelectionController::selectionMoved(sf::Vector2f _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< SelectionController *>(this), &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SelectionController::selectionScaled(sf::Vector2f _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< SelectionController *>(this), &staticMetaObject, 7, _a);
}
QT_END_MOC_NAMESPACE
