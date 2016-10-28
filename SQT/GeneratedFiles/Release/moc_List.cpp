/****************************************************************************
** Meta object code from reading C++ file 'List.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Widget/Various/Layout/List.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'List.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_List_t {
    QByteArrayData data[22];
    char stringdata0[293];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_List_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_List_t qt_meta_stringdata_List = {
    {
QT_MOC_LITERAL(0, 0, 4), // "List"
QT_MOC_LITERAL(1, 5, 6), // "undoed"
QT_MOC_LITERAL(2, 12, 0), // ""
QT_MOC_LITERAL(3, 13, 12), // "elementMoved"
QT_MOC_LITERAL(4, 26, 3), // "src"
QT_MOC_LITERAL(5, 30, 3), // "dst"
QT_MOC_LITERAL(6, 34, 9), // "reordered"
QT_MOC_LITERAL(7, 44, 19), // "firstObjectSelected"
QT_MOC_LITERAL(8, 64, 11), // "ListObject&"
QT_MOC_LITERAL(9, 76, 16), // "noObjectSelected"
QT_MOC_LITERAL(10, 93, 14), // "objectSelected"
QT_MOC_LITERAL(11, 108, 17), // "oneObjectSelected"
QT_MOC_LITERAL(12, 126, 23), // "noMoreOneObjectSelected"
QT_MOC_LITERAL(13, 150, 25), // "moreThanOneObjectSelected"
QT_MOC_LITERAL(14, 176, 21), // "firstObjectUnselected"
QT_MOC_LITERAL(15, 198, 8), // "noObject"
QT_MOC_LITERAL(16, 207, 13), // "onlyOneObject"
QT_MOC_LITERAL(17, 221, 17), // "moreThanOneObject"
QT_MOC_LITERAL(18, 239, 11), // "moveElement"
QT_MOC_LITERAL(19, 251, 12), // "dropSelected"
QT_MOC_LITERAL(20, 264, 13), // "stopUndoStack"
QT_MOC_LITERAL(21, 278, 14) // "startUndoStack"

    },
    "List\0undoed\0\0elementMoved\0src\0dst\0"
    "reordered\0firstObjectSelected\0ListObject&\0"
    "noObjectSelected\0objectSelected\0"
    "oneObjectSelected\0noMoreOneObjectSelected\0"
    "moreThanOneObjectSelected\0"
    "firstObjectUnselected\0noObject\0"
    "onlyOneObject\0moreThanOneObject\0"
    "moveElement\0dropSelected\0stopUndoStack\0"
    "startUndoStack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_List[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      13,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    2,  100,    2, 0x06 /* Public */,
       6,    0,  105,    2, 0x06 /* Public */,
       7,    1,  106,    2, 0x06 /* Public */,
       9,    0,  109,    2, 0x06 /* Public */,
      10,    0,  110,    2, 0x06 /* Public */,
      11,    1,  111,    2, 0x06 /* Public */,
      12,    0,  114,    2, 0x06 /* Public */,
      13,    0,  115,    2, 0x06 /* Public */,
      14,    1,  116,    2, 0x06 /* Public */,
      15,    0,  119,    2, 0x06 /* Public */,
      16,    0,  120,    2, 0x06 /* Public */,
      17,    0,  121,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      18,    2,  122,    2, 0x0a /* Public */,
      19,    0,  127,    2, 0x0a /* Public */,
      20,    0,  128,    2, 0x0a /* Public */,
      21,    0,  129,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void List::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        List *_t = static_cast<List *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->undoed(); break;
        case 1: _t->elementMoved((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->reordered(); break;
        case 3: _t->firstObjectSelected((*reinterpret_cast< ListObject(*)>(_a[1]))); break;
        case 4: _t->noObjectSelected(); break;
        case 5: _t->objectSelected(); break;
        case 6: _t->oneObjectSelected((*reinterpret_cast< ListObject(*)>(_a[1]))); break;
        case 7: _t->noMoreOneObjectSelected(); break;
        case 8: _t->moreThanOneObjectSelected(); break;
        case 9: _t->firstObjectUnselected((*reinterpret_cast< ListObject(*)>(_a[1]))); break;
        case 10: _t->noObject(); break;
        case 11: _t->onlyOneObject(); break;
        case 12: _t->moreThanOneObject(); break;
        case 13: _t->moveElement((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->dropSelected(); break;
        case 15: _t->stopUndoStack(); break;
        case 16: _t->startUndoStack(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (List::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::undoed)) {
                *result = 0;
            }
        }
        {
            typedef void (List::*_t)(int , int ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::elementMoved)) {
                *result = 1;
            }
        }
        {
            typedef void (List::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::reordered)) {
                *result = 2;
            }
        }
        {
            typedef void (List::*_t)(ListObject & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::firstObjectSelected)) {
                *result = 3;
            }
        }
        {
            typedef void (List::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::noObjectSelected)) {
                *result = 4;
            }
        }
        {
            typedef void (List::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::objectSelected)) {
                *result = 5;
            }
        }
        {
            typedef void (List::*_t)(ListObject & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::oneObjectSelected)) {
                *result = 6;
            }
        }
        {
            typedef void (List::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::noMoreOneObjectSelected)) {
                *result = 7;
            }
        }
        {
            typedef void (List::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::moreThanOneObjectSelected)) {
                *result = 8;
            }
        }
        {
            typedef void (List::*_t)(ListObject & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::firstObjectUnselected)) {
                *result = 9;
            }
        }
        {
            typedef void (List::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::noObject)) {
                *result = 10;
            }
        }
        {
            typedef void (List::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::onlyOneObject)) {
                *result = 11;
            }
        }
        {
            typedef void (List::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&List::moreThanOneObject)) {
                *result = 12;
            }
        }
    }
}

const QMetaObject List::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_List.data,
      qt_meta_data_List,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *List::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *List::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_List.stringdata0))
        return static_cast<void*>(const_cast< List*>(this));
    return QObject::qt_metacast(_clname);
}

int List::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void List::undoed()const
{
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void List::elementMoved(int _t1, int _t2)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 1, _a);
}

// SIGNAL 2
void List::reordered()const
{
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void List::firstObjectSelected(ListObject & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 3, _a);
}

// SIGNAL 4
void List::noObjectSelected()const
{
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void List::objectSelected()const
{
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void List::oneObjectSelected(ListObject & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 6, _a);
}

// SIGNAL 7
void List::noMoreOneObjectSelected()const
{
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 7, Q_NULLPTR);
}

// SIGNAL 8
void List::moreThanOneObjectSelected()const
{
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 8, Q_NULLPTR);
}

// SIGNAL 9
void List::firstObjectUnselected(ListObject & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 9, _a);
}

// SIGNAL 10
void List::noObject()const
{
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 10, Q_NULLPTR);
}

// SIGNAL 11
void List::onlyOneObject()const
{
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 11, Q_NULLPTR);
}

// SIGNAL 12
void List::moreThanOneObject()const
{
    QMetaObject::activate(const_cast< List *>(this), &staticMetaObject, 12, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
