/****************************************************************************
** Meta object code from reading C++ file 'ListObject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Widget/Various/Layout/ListObject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ListObject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ListObject_t {
    QByteArrayData data[19];
    char stringdata0[166];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ListObject_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ListObject_t qt_meta_stringdata_ListObject = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ListObject"
QT_MOC_LITERAL(1, 11, 7), // "deleted"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 7), // "dropped"
QT_MOC_LITERAL(4, 28, 9), // "undropped"
QT_MOC_LITERAL(5, 38, 8), // "selected"
QT_MOC_LITERAL(6, 47, 10), // "unselected"
QT_MOC_LITERAL(7, 58, 11), // "leftClicked"
QT_MOC_LITERAL(8, 70, 12), // "rightClicked"
QT_MOC_LITERAL(9, 83, 5), // "moved"
QT_MOC_LITERAL(10, 89, 4), // "drop"
QT_MOC_LITERAL(11, 94, 6), // "undrop"
QT_MOC_LITERAL(12, 101, 6), // "select"
QT_MOC_LITERAL(13, 108, 8), // "unselect"
QT_MOC_LITERAL(14, 117, 16), // "inverseSelection"
QT_MOC_LITERAL(15, 134, 5), // "_drop"
QT_MOC_LITERAL(16, 140, 7), // "_undrop"
QT_MOC_LITERAL(17, 148, 7), // "_select"
QT_MOC_LITERAL(18, 156, 9) // "_unselect"

    },
    "ListObject\0deleted\0\0dropped\0undropped\0"
    "selected\0unselected\0leftClicked\0"
    "rightClicked\0moved\0drop\0undrop\0select\0"
    "unselect\0inverseSelection\0_drop\0_undrop\0"
    "_select\0_unselect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ListObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   99,    2, 0x06 /* Public */,
       3,    0,  100,    2, 0x06 /* Public */,
       4,    0,  101,    2, 0x06 /* Public */,
       5,    0,  102,    2, 0x06 /* Public */,
       6,    0,  103,    2, 0x06 /* Public */,
       7,    0,  104,    2, 0x06 /* Public */,
       8,    0,  105,    2, 0x06 /* Public */,
       9,    0,  106,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    0,  107,    2, 0x0a /* Public */,
      11,    0,  108,    2, 0x0a /* Public */,
      12,    0,  109,    2, 0x0a /* Public */,
      13,    0,  110,    2, 0x0a /* Public */,
      14,    0,  111,    2, 0x0a /* Public */,
      15,    0,  112,    2, 0x08 /* Private */,
      16,    0,  113,    2, 0x08 /* Private */,
      17,    0,  114,    2, 0x08 /* Private */,
      18,    0,  115,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
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
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ListObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ListObject *_t = static_cast<ListObject *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->deleted(); break;
        case 1: _t->dropped(); break;
        case 2: _t->undropped(); break;
        case 3: _t->selected(); break;
        case 4: _t->unselected(); break;
        case 5: _t->leftClicked(); break;
        case 6: _t->rightClicked(); break;
        case 7: _t->moved(); break;
        case 8: _t->drop(); break;
        case 9: _t->undrop(); break;
        case 10: _t->select(); break;
        case 11: _t->unselect(); break;
        case 12: _t->inverseSelection(); break;
        case 13: _t->_drop(); break;
        case 14: _t->_undrop(); break;
        case 15: _t->_select(); break;
        case 16: _t->_unselect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ListObject::deleted)) {
                *result = 0;
            }
        }
        {
            typedef void (ListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ListObject::dropped)) {
                *result = 1;
            }
        }
        {
            typedef void (ListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ListObject::undropped)) {
                *result = 2;
            }
        }
        {
            typedef void (ListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ListObject::selected)) {
                *result = 3;
            }
        }
        {
            typedef void (ListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ListObject::unselected)) {
                *result = 4;
            }
        }
        {
            typedef void (ListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ListObject::leftClicked)) {
                *result = 5;
            }
        }
        {
            typedef void (ListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ListObject::rightClicked)) {
                *result = 6;
            }
        }
        {
            typedef void (ListObject::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ListObject::moved)) {
                *result = 7;
            }
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject ListObject::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_ListObject.data,
      qt_meta_data_ListObject,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ListObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ListObject::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ListObject.stringdata0))
        return static_cast<void*>(const_cast< ListObject*>(this));
    return QWidget::qt_metacast(_clname);
}

int ListObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void ListObject::deleted()const
{
    QMetaObject::activate(const_cast< ListObject *>(this), &staticMetaObject, 0, Q_NULLPTR);
}

// SIGNAL 1
void ListObject::dropped()const
{
    QMetaObject::activate(const_cast< ListObject *>(this), &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void ListObject::undropped()const
{
    QMetaObject::activate(const_cast< ListObject *>(this), &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void ListObject::selected()const
{
    QMetaObject::activate(const_cast< ListObject *>(this), &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void ListObject::unselected()const
{
    QMetaObject::activate(const_cast< ListObject *>(this), &staticMetaObject, 4, Q_NULLPTR);
}

// SIGNAL 5
void ListObject::leftClicked()const
{
    QMetaObject::activate(const_cast< ListObject *>(this), &staticMetaObject, 5, Q_NULLPTR);
}

// SIGNAL 6
void ListObject::rightClicked()const
{
    QMetaObject::activate(const_cast< ListObject *>(this), &staticMetaObject, 6, Q_NULLPTR);
}

// SIGNAL 7
void ListObject::moved()const
{
    QMetaObject::activate(const_cast< ListObject *>(this), &staticMetaObject, 7, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
