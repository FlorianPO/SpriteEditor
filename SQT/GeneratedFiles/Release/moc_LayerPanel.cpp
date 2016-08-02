/****************************************************************************
** Meta object code from reading C++ file 'LayerPanel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Widget/Gui/LayerPanel/LayerPanel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'LayerPanel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LayerPanel_t {
    QByteArrayData data[13];
    char stringdata0[173];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_LayerPanel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_LayerPanel_t qt_meta_stringdata_LayerPanel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "LayerPanel"
QT_MOC_LITERAL(1, 11, 12), // "layerCreated"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 6), // "Layer*"
QT_MOC_LITERAL(4, 32, 12), // "layerDeleted"
QT_MOC_LITERAL(5, 45, 12), // "onlyOneLayer"
QT_MOC_LITERAL(6, 58, 16), // "moreThanOneLayer"
QT_MOC_LITERAL(7, 75, 18), // "firstLayerSelected"
QT_MOC_LITERAL(8, 94, 20), // "firstLayerUnselected"
QT_MOC_LITERAL(9, 115, 16), // "selectionCreated"
QT_MOC_LITERAL(10, 132, 16), // "selectionDeleted"
QT_MOC_LITERAL(11, 149, 11), // "copyCreated"
QT_MOC_LITERAL(12, 161, 11) // "copyDropped"

    },
    "LayerPanel\0layerCreated\0\0Layer*\0"
    "layerDeleted\0onlyOneLayer\0moreThanOneLayer\0"
    "firstLayerSelected\0firstLayerUnselected\0"
    "selectionCreated\0selectionDeleted\0"
    "copyCreated\0copyDropped"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LayerPanel[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   64,    2, 0x08 /* Private */,
       4,    1,   67,    2, 0x08 /* Private */,
       5,    0,   70,    2, 0x08 /* Private */,
       6,    0,   71,    2, 0x08 /* Private */,
       7,    1,   72,    2, 0x08 /* Private */,
       8,    1,   75,    2, 0x08 /* Private */,
       9,    0,   78,    2, 0x08 /* Private */,
      10,    0,   79,    2, 0x08 /* Private */,
      11,    0,   80,    2, 0x08 /* Private */,
      12,    0,   81,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void LayerPanel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        LayerPanel *_t = static_cast<LayerPanel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->layerCreated((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 1: _t->layerDeleted((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 2: _t->onlyOneLayer(); break;
        case 3: _t->moreThanOneLayer(); break;
        case 4: _t->firstLayerSelected((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 5: _t->firstLayerUnselected((*reinterpret_cast< Layer*(*)>(_a[1]))); break;
        case 6: _t->selectionCreated(); break;
        case 7: _t->selectionDeleted(); break;
        case 8: _t->copyCreated(); break;
        case 9: _t->copyDropped(); break;
        default: ;
        }
    }
}

const QMetaObject LayerPanel::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_LayerPanel.data,
      qt_meta_data_LayerPanel,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *LayerPanel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LayerPanel::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_LayerPanel.stringdata0))
        return static_cast<void*>(const_cast< LayerPanel*>(this));
    return QWidget::qt_metacast(_clname);
}

int LayerPanel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
