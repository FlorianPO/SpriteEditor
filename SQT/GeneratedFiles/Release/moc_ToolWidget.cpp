/****************************************************************************
** Meta object code from reading C++ file 'ToolWidget.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Widget/Gui/ToolOptionPanel/ToolWidget/ToolWidget.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ToolWidget.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ToolWidget_t {
    QByteArrayData data[9];
    char stringdata0[93];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToolWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToolWidget_t qt_meta_stringdata_ToolWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "ToolWidget"
QT_MOC_LITERAL(1, 11, 11), // "sizeChanged"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 12), // "sf::Vector2i"
QT_MOC_LITERAL(4, 37, 12), // "sizeXChanged"
QT_MOC_LITERAL(5, 50, 12), // "sizeYChanged"
QT_MOC_LITERAL(6, 63, 8), // "selected"
QT_MOC_LITERAL(7, 72, 10), // "unselected"
QT_MOC_LITERAL(8, 83, 9) // "tabSelect"

    },
    "ToolWidget\0sizeChanged\0\0sf::Vector2i\0"
    "sizeXChanged\0sizeYChanged\0selected\0"
    "unselected\0tabSelect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolWidget[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x08 /* Private */,
       4,    1,   47,    2, 0x0a /* Public */,
       5,    1,   50,    2, 0x0a /* Public */,
       6,    0,   53,    2, 0x0a /* Public */,
       7,    0,   54,    2, 0x0a /* Public */,
       8,    0,   55,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void ToolWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ToolWidget *_t = static_cast<ToolWidget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sizeChanged((*reinterpret_cast< sf::Vector2i(*)>(_a[1]))); break;
        case 1: _t->sizeXChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->sizeYChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->selected(); break;
        case 4: _t->unselected(); break;
        case 5: _t->tabSelect(); break;
        default: ;
        }
    }
}

const QMetaObject ToolWidget::staticMetaObject = {
    { &TabObject::staticMetaObject, qt_meta_stringdata_ToolWidget.data,
      qt_meta_data_ToolWidget,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ToolWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ToolWidget.stringdata0))
        return static_cast<void*>(const_cast< ToolWidget*>(this));
    return TabObject::qt_metacast(_clname);
}

int ToolWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TabObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
