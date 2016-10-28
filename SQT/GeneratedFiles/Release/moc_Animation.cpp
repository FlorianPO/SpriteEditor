/****************************************************************************
** Meta object code from reading C++ file 'Animation.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../Source Files/Application/Animation/Animation.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Animation.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Animation_t {
    QByteArrayData data[23];
    char stringdata0[233];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Animation_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Animation_t qt_meta_stringdata_Animation = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Animation"
QT_MOC_LITERAL(1, 10, 11), // "nameChanged"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 16), // "animationChanged"
QT_MOC_LITERAL(4, 40, 16), // "animationVisible"
QT_MOC_LITERAL(5, 57, 18), // "animationUnvisible"
QT_MOC_LITERAL(6, 76, 12), // "layerChanged"
QT_MOC_LITERAL(7, 89, 5), // "Layer"
QT_MOC_LITERAL(8, 95, 19), // "createAnimationRect"
QT_MOC_LITERAL(9, 115, 11), // "sf::IntRect"
QT_MOC_LITERAL(10, 127, 4), // "rect"
QT_MOC_LITERAL(11, 132, 8), // "setLayer"
QT_MOC_LITERAL(12, 141, 5), // "layer"
QT_MOC_LITERAL(13, 147, 12), // "dropSelected"
QT_MOC_LITERAL(14, 160, 7), // "setName"
QT_MOC_LITERAL(15, 168, 4), // "name"
QT_MOC_LITERAL(16, 173, 11), // "setPosition"
QT_MOC_LITERAL(17, 185, 12), // "sf::Vector2f"
QT_MOC_LITERAL(18, 198, 8), // "position"
QT_MOC_LITERAL(19, 207, 8), // "setScale"
QT_MOC_LITERAL(20, 216, 6), // "factor"
QT_MOC_LITERAL(21, 223, 4), // "show"
QT_MOC_LITERAL(22, 228, 4) // "hide"

    },
    "Animation\0nameChanged\0\0animationChanged\0"
    "animationVisible\0animationUnvisible\0"
    "layerChanged\0Layer\0createAnimationRect\0"
    "sf::IntRect\0rect\0setLayer\0layer\0"
    "dropSelected\0setName\0name\0setPosition\0"
    "sf::Vector2f\0position\0setScale\0factor\0"
    "show\0hide"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Animation[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       3,    0,   87,    2, 0x06 /* Public */,
       4,    0,   88,    2, 0x06 /* Public */,
       5,    0,   89,    2, 0x06 /* Public */,
       6,    1,   90,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   93,    2, 0x0a /* Public */,
       8,    0,   96,    2, 0x2a /* Public | MethodCloned */,
      11,    1,   97,    2, 0x0a /* Public */,
      13,    0,  100,    2, 0x0a /* Public */,
      14,    1,  101,    2, 0x0a /* Public */,
      16,    1,  104,    2, 0x0a /* Public */,
      19,    1,  107,    2, 0x0a /* Public */,
      21,    0,  110,    2, 0x0a /* Public */,
      22,    0,  111,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,   12,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, 0x80000000 | 17,   18,
    QMetaType::Void, QMetaType::Float,   20,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Animation::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Animation *_t = static_cast<Animation *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->nameChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->animationChanged(); break;
        case 2: _t->animationVisible(); break;
        case 3: _t->animationUnvisible(); break;
        case 4: _t->layerChanged((*reinterpret_cast< const Layer(*)>(_a[1]))); break;
        case 5: _t->createAnimationRect((*reinterpret_cast< const sf::IntRect(*)>(_a[1]))); break;
        case 6: _t->createAnimationRect(); break;
        case 7: _t->setLayer((*reinterpret_cast< const Layer(*)>(_a[1]))); break;
        case 8: _t->dropSelected(); break;
        case 9: _t->setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 10: _t->setPosition((*reinterpret_cast< const sf::Vector2f(*)>(_a[1]))); break;
        case 11: _t->setScale((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 12: _t->show(); break;
        case 13: _t->hide(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (Animation::*_t)(const QString & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Animation::nameChanged)) {
                *result = 0;
            }
        }
        {
            typedef void (Animation::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Animation::animationChanged)) {
                *result = 1;
            }
        }
        {
            typedef void (Animation::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Animation::animationVisible)) {
                *result = 2;
            }
        }
        {
            typedef void (Animation::*_t)() const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Animation::animationUnvisible)) {
                *result = 3;
            }
        }
        {
            typedef void (Animation::*_t)(const Layer & ) const;
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&Animation::layerChanged)) {
                *result = 4;
            }
        }
    }
}

const QMetaObject Animation::staticMetaObject = {
    { &SignalListObject::staticMetaObject, qt_meta_stringdata_Animation.data,
      qt_meta_data_Animation,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Animation::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Animation::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Animation.stringdata0))
        return static_cast<void*>(const_cast< Animation*>(this));
    return SignalListObject::qt_metacast(_clname);
}

int Animation::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SignalListObject::qt_metacall(_c, _id, _a);
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
void Animation::nameChanged(const QString & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Animation *>(this), &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Animation::animationChanged()const
{
    QMetaObject::activate(const_cast< Animation *>(this), &staticMetaObject, 1, Q_NULLPTR);
}

// SIGNAL 2
void Animation::animationVisible()const
{
    QMetaObject::activate(const_cast< Animation *>(this), &staticMetaObject, 2, Q_NULLPTR);
}

// SIGNAL 3
void Animation::animationUnvisible()const
{
    QMetaObject::activate(const_cast< Animation *>(this), &staticMetaObject, 3, Q_NULLPTR);
}

// SIGNAL 4
void Animation::layerChanged(const Layer & _t1)const
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(const_cast< Animation *>(this), &staticMetaObject, 4, _a);
}
QT_END_MOC_NAMESPACE
