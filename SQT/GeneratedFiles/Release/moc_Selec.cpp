/****************************************************************************
** Meta object code from reading C++ file 'Selec.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Selec/Selec.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Selec.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CSelec_t {
    QByteArrayData data[28];
    char stringdata0[373];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CSelec_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CSelec_t qt_meta_stringdata_CSelec = {
    {
QT_MOC_LITERAL(0, 0, 6), // "CSelec"
QT_MOC_LITERAL(1, 7, 16), // "selectionUpdated"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 4), // "mode"
QT_MOC_LITERAL(4, 30, 16), // "selectionCreated"
QT_MOC_LITERAL(5, 47, 16), // "selectionDeleted"
QT_MOC_LITERAL(6, 64, 17), // "selectionInverted"
QT_MOC_LITERAL(7, 82, 19), // "selectionUninverted"
QT_MOC_LITERAL(8, 102, 13), // "cadreXChanged"
QT_MOC_LITERAL(9, 116, 13), // "cadreYChanged"
QT_MOC_LITERAL(10, 130, 13), // "cadreWChanged"
QT_MOC_LITERAL(11, 144, 13), // "cadreHChanged"
QT_MOC_LITERAL(12, 158, 15), // "createSelection"
QT_MOC_LITERAL(13, 174, 11), // "sf::IntRect"
QT_MOC_LITERAL(14, 186, 4), // "rect"
QT_MOC_LITERAL(15, 191, 29), // "std::vector<CTool::line_conf>"
QT_MOC_LITERAL(16, 221, 6), // "conf_l"
QT_MOC_LITERAL(17, 228, 9), // "sf::Image"
QT_MOC_LITERAL(18, 238, 5), // "image"
QT_MOC_LITERAL(19, 244, 15), // "deleteSelection"
QT_MOC_LITERAL(20, 260, 12), // "addSelection"
QT_MOC_LITERAL(21, 273, 12), // "subSelection"
QT_MOC_LITERAL(22, 286, 18), // "intersectSelection"
QT_MOC_LITERAL(23, 305, 15), // "invertSelection"
QT_MOC_LITERAL(24, 321, 17), // "uninvertSelection"
QT_MOC_LITERAL(25, 339, 16), // "const sf::Image*"
QT_MOC_LITERAL(26, 356, 12), // "sumSelection"
QT_MOC_LITERAL(27, 369, 3) // "add"

    },
    "CSelec\0selectionUpdated\0\0mode\0"
    "selectionCreated\0selectionDeleted\0"
    "selectionInverted\0selectionUninverted\0"
    "cadreXChanged\0cadreYChanged\0cadreWChanged\0"
    "cadreHChanged\0createSelection\0sf::IntRect\0"
    "rect\0std::vector<CTool::line_conf>\0"
    "conf_l\0sf::Image\0image\0deleteSelection\0"
    "addSelection\0subSelection\0intersectSelection\0"
    "invertSelection\0uninvertSelection\0"
    "const sf::Image*\0sumSelection\0add"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CSelec[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      24,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  134,    2, 0x06 /* Public */,
       1,    0,  137,    2, 0x26 /* Public | MethodCloned */,
       4,    0,  138,    2, 0x06 /* Public */,
       5,    0,  139,    2, 0x06 /* Public */,
       6,    0,  140,    2, 0x06 /* Public */,
       7,    0,  141,    2, 0x06 /* Public */,
       8,    1,  142,    2, 0x06 /* Public */,
       9,    1,  145,    2, 0x06 /* Public */,
      10,    1,  148,    2, 0x06 /* Public */,
      11,    1,  151,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    2,  154,    2, 0x0a /* Public */,
      12,    3,  159,    2, 0x0a /* Public */,
      19,    0,  166,    2, 0x0a /* Public */,
      20,    2,  167,    2, 0x0a /* Public */,
      20,    3,  172,    2, 0x0a /* Public */,
      21,    2,  179,    2, 0x0a /* Public */,
      21,    3,  184,    2, 0x0a /* Public */,
      22,    2,  191,    2, 0x0a /* Public */,
      22,    3,  196,    2, 0x0a /* Public */,
      23,    0,  203,    2, 0x0a /* Public */,
      24,    0,  204,    2, 0x0a /* Public */,
      12,    2,  205,    2, 0x08 /* Private */,
      26,    3,  210,    2, 0x08 /* Private */,
      22,    2,  217,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15,   14,   16,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 17, 0x80000000 | 15,   14,   18,   16,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15,   14,   16,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 17, 0x80000000 | 15,   14,   18,   16,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 15,   14,   16,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 17, 0x80000000 | 15,   14,   18,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 25,   14,   18,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 25, QMetaType::Bool,   14,   18,   27,
    QMetaType::Void, 0x80000000 | 13, 0x80000000 | 25,   14,   18,

       0        // eod
};

void CSelec::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CSelec *_t = static_cast<CSelec *>(_o);
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
        case 10: _t->createSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const std::vector<CTool::line_conf>(*)>(_a[2]))); break;
        case 11: _t->createSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image(*)>(_a[2])),(*reinterpret_cast< const std::vector<CTool::line_conf>(*)>(_a[3]))); break;
        case 12: _t->deleteSelection(); break;
        case 13: _t->addSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const std::vector<CTool::line_conf>(*)>(_a[2]))); break;
        case 14: _t->addSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image(*)>(_a[2])),(*reinterpret_cast< const std::vector<CTool::line_conf>(*)>(_a[3]))); break;
        case 15: _t->subSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const std::vector<CTool::line_conf>(*)>(_a[2]))); break;
        case 16: _t->subSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image(*)>(_a[2])),(*reinterpret_cast< const std::vector<CTool::line_conf>(*)>(_a[3]))); break;
        case 17: _t->intersectSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const std::vector<CTool::line_conf>(*)>(_a[2]))); break;
        case 18: _t->intersectSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image(*)>(_a[2])),(*reinterpret_cast< const std::vector<CTool::line_conf>(*)>(_a[3]))); break;
        case 19: _t->invertSelection(); break;
        case 20: _t->uninvertSelection(); break;
        case 21: _t->createSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image*(*)>(_a[2]))); break;
        case 22: _t->sumSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image*(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3]))); break;
        case 23: _t->intersectSelection((*reinterpret_cast< sf::IntRect(*)>(_a[1])),(*reinterpret_cast< const sf::Image*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (CSelec::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSelec::selectionUpdated)) {
                *result = 0;
            }
        }
        {
            typedef void (CSelec::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSelec::selectionCreated)) {
                *result = 2;
            }
        }
        {
            typedef void (CSelec::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSelec::selectionDeleted)) {
                *result = 3;
            }
        }
        {
            typedef void (CSelec::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSelec::selectionInverted)) {
                *result = 4;
            }
        }
        {
            typedef void (CSelec::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSelec::selectionUninverted)) {
                *result = 5;
            }
        }
        {
            typedef void (CSelec::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSelec::cadreXChanged)) {
                *result = 6;
            }
        }
        {
            typedef void (CSelec::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSelec::cadreYChanged)) {
                *result = 7;
            }
        }
        {
            typedef void (CSelec::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSelec::cadreWChanged)) {
                *result = 8;
            }
        }
        {
            typedef void (CSelec::*_t)(int );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&CSelec::cadreHChanged)) {
                *result = 9;
            }
        }
    }
}

const QMetaObject CSelec::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_CSelec.data,
      qt_meta_data_CSelec,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *CSelec::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CSelec::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_CSelec.stringdata0))
        return static_cast<void*>(const_cast< CSelec*>(this));
    return QObject::qt_metacast(_clname);
}

int CSelec::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 24)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 24;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 24)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 24;
    }
    return _id;
}

// SIGNAL 0
void CSelec::selectionUpdated(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 2
void CSelec::selectionCreated()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void CSelec::selectionDeleted()
{
    QMetaObject::activate(this, &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void CSelec::selectionInverted()
{
    QMetaObject::activate(this, &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void CSelec::selectionUninverted()
{
    QMetaObject::activate(this, &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void CSelec::cadreXChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}

// SIGNAL 7
void CSelec::cadreYChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void CSelec::cadreWChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}

// SIGNAL 9
void CSelec::cadreHChanged(int _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 9, _a);
}
QT_END_MOC_NAMESPACE
