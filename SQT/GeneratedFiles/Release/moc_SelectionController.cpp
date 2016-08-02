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
    QByteArrayData data[31];
    char stringdata0[412];
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
QT_MOC_LITERAL(8, 115, 13), // "cadreXChanged"
QT_MOC_LITERAL(9, 129, 13), // "cadreYChanged"
QT_MOC_LITERAL(10, 143, 13), // "cadreWChanged"
QT_MOC_LITERAL(11, 157, 13), // "cadreHChanged"
QT_MOC_LITERAL(12, 171, 15), // "createSelection"
QT_MOC_LITERAL(13, 187, 11), // "sf::IntRect"
QT_MOC_LITERAL(14, 199, 4), // "rect"
QT_MOC_LITERAL(15, 204, 25), // "std::vector<nSet::o_line>"
QT_MOC_LITERAL(16, 230, 6), // "conf_l"
QT_MOC_LITERAL(17, 237, 9), // "sf::Image"
QT_MOC_LITERAL(18, 247, 5), // "image"
QT_MOC_LITERAL(19, 253, 15), // "deleteSelection"
QT_MOC_LITERAL(20, 269, 5), // "force"
QT_MOC_LITERAL(21, 275, 12), // "addSelection"
QT_MOC_LITERAL(22, 288, 12), // "subSelection"
QT_MOC_LITERAL(23, 301, 18), // "intersectSelection"
QT_MOC_LITERAL(24, 320, 15), // "invertSelection"
QT_MOC_LITERAL(25, 336, 17), // "uninvertSelection"
QT_MOC_LITERAL(26, 354, 11), // "deleteLayer"
QT_MOC_LITERAL(27, 366, 16), // "const sf::Image*"
QT_MOC_LITERAL(28, 383, 12), // "sumSelection"
QT_MOC_LITERAL(29, 396, 3), // "add"
QT_MOC_LITERAL(30, 400, 11) // "updateLines"

    },
    "SelectionController\0selectionUpdated\0"
    "\0mode\0selectionCreated\0selectionDeleted\0"
    "selectionInverted\0selectionUninverted\0"
    "cadreXChanged\0cadreYChanged\0cadreWChanged\0"
    "cadreHChanged\0createSelection\0sf::IntRect\0"
    "rect\0std::vector<nSet::o_line>\0conf_l\0"
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
      27,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  149,    2, 0x06 /* Public */,
       1,    0,  152,    2, 0x26 /* Public | MethodCloned */,
       4,    0,  153,    2, 0x06 /* Public */,
       5,    0,  154,    2, 0x06 /* Public */,
       6,    0,  155,    2, 0x06 /* Public */,
       7,    0,  156,    2, 0x06 /* Public */,
       8,    1,  157,    2, 0x06 /* Public */,
       9,    1,  160,    2, 0x06 /* Public */,
      10,    1,  163,    2, 0x06 /* Public */,
      11,    1,  166,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    2,  169,    2, 0x0a /* Public */,
      12,    3,  174,    2, 0x0a /* Public */,
      19,    1,  181,    2, 0x0a /* Public */,
      19,    0,  184,    2, 0x2a /* Public | MethodCloned */,
      21,    2,  185,    2, 0x0a /* Public */,
      21,    3,  190,    2, 0x0a /* Public */,
      22,    2,  197,    2, 0x0a /* Public */,
      22,    3,  202,    2, 0x0a /* Public */,
      23,    2,  209,    2, 0x0a /* Public */,
      23,    3,  214,    2, 0x0a /* Public */,
      24,    0,  221,    2, 0x0a /* Public */,
      25,    0,  222,    2, 0x0a /* Public */,
      26,    0,  223,    2, 0x0a /* Public */,
      12,    2,  224,    2, 0x08 /* Private */,
      28,    3,  229,    2, 0x08 /* Private */,
      23,    2,  236,    2, 0x08 /* Private */,

 // methods: name, argc, parameters, tag, flags
      30,    0,  241,    2, 0x00 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15,   14,   16,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 17, 0x80000000 | 15,   14,   18,   16,
    QMetaType::Void, QMetaType::Bool,   20,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15,   14,   16,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 17, 0x80000000 | 15,   14,   18,   16,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15,   14,   16,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 17, 0x80000000 | 15,   14,   18,   16,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15,   14,   16,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 17, 0x80000000 | 15,   14,   18,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 27,   14,   18,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 27, QMetaType::Bool,   14,   18,   29,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 27,   14,   18,

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
        case 6: _t->cadreXChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->cadreYChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->cadreWChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->cadreHChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->createSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[2]))); break;
        case 11: _t->createSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image(*)>(_a[2])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[3]))); break;
        case 12: _t->deleteSelection((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->deleteSelection(); break;
        case 14: _t->addSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[2]))); break;
        case 15: _t->addSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image(*)>(_a[2])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[3]))); break;
        case 16: _t->subSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[2]))); break;
        case 17: _t->subSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image(*)>(_a[2])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[3]))); break;
        case 18: _t->intersectSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[2]))); break;
        case 19: _t->intersectSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image(*)>(_a[2])),(*reinterpret_cast< const std::vector<nSet::o_line>(*)>(_a[3]))); break;
        case 20: _t->invertSelection(); break;
        case 21: _t->uninvertSelection(); break;
        case 22: _t->deleteLayer(); break;
        case 23: _t->createSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image*(*)>(_a[2]))); break;
        case 24: _t->sumSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 25: _t->intersectSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image*(*)>(_a[2]))); break;
        case 26: _t->updateLines(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SelectionController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::selectionUpdated)) {
                *result = 0;
            }
        }
        {
            typedef void (SelectionController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::selectionCreated)) {
                *result = 2;
            }
        }
        {
            typedef void (SelectionController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::selectionDeleted)) {
                *result = 3;
            }
        }
        {
            typedef void (SelectionController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::selectionInverted)) {
                *result = 4;
            }
        }
        {
            typedef void (SelectionController::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::selectionUninverted)) {
                *result = 5;
            }
        }
        {
            typedef void (SelectionController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::cadreXChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (SelectionController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::cadreYChanged)) {
                *result = 7;
            }
        }
        {
            typedef void (SelectionController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::cadreWChanged)) {
                *result = 8;
            }
        }
        {
            typedef void (SelectionController::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SelectionController::cadreHChanged)) {
                *result = 9;
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
    if (!strcmp(_clname, "SignalInit"))
        return static_cast< SignalInit*>(const_cast< SelectionController*>(this));
    return QObject::qt_metacast(_clname);
}

int SelectionController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 27)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 27;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 27)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 27;
    }
    return _id;
}

// SIGNAL 0
void SelectionController::selectionUpdated(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void SelectionController::selectionCreated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void SelectionController::selectionDeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void SelectionController::selectionInverted()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void SelectionController::selectionUninverted()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void SelectionController::cadreXChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void SelectionController::cadreYChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void SelectionController::cadreWChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void SelectionController::cadreHChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
