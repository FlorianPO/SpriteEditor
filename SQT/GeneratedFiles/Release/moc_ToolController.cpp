/****************************************************************************
** Meta object code from reading C++ file 'ToolController.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Tool/ToolController.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ToolController.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ToolController_t {
    QByteArrayData data[8];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ToolController_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ToolController_t qt_meta_stringdata_ToolController = {
    {
QT_MOC_LITERAL(0, 0, 14), // "ToolController"
QT_MOC_LITERAL(1, 15, 12), // "toolSelected"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "Tool*"
QT_MOC_LITERAL(4, 35, 10), // "selectTool"
QT_MOC_LITERAL(5, 46, 7), // "tool_id"
QT_MOC_LITERAL(6, 54, 15), // "nTol::tool_enum"
QT_MOC_LITERAL(7, 70, 4) // "tool"

    },
    "ToolController\0toolSelected\0\0Tool*\0"
    "selectTool\0tool_id\0nTol::tool_enum\0"
    "tool"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ToolController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   32,    2, 0x0a /* Public */,
       4,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void ToolController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        ToolController *_t = static_cast<ToolController *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->toolSelected((*reinterpret_cast< Tool*(*)>(_a[1]))); break;
        case 1: _t->selectTool((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->selectTool((*reinterpret_cast< nTol::tool_enum(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (ToolController::*_t)(Tool * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&ToolController::toolSelected)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject ToolController::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ToolController.data,
      qt_meta_data_ToolController,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *ToolController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ToolController::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_ToolController.stringdata0))
        return static_cast<void*>(const_cast< ToolController*>(this));
    return QObject::qt_metacast(_clname);
}

int ToolController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void ToolController::toolSelected(Tool * _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
