/****************************************************************************
** Meta object code from reading C++ file 'privatemessagescontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "privatemessagescontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'privatemessagescontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PrivateMessagesController_t {
    QByteArrayData data[10];
    char stringdata[72];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PrivateMessagesController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PrivateMessagesController_t qt_meta_stringdata_PrivateMessagesController = {
    {
QT_MOC_LITERAL(0, 0, 25),
QT_MOC_LITERAL(1, 26, 5),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 4),
QT_MOC_LITERAL(4, 38, 2),
QT_MOC_LITERAL(5, 41, 5),
QT_MOC_LITERAL(6, 47, 6),
QT_MOC_LITERAL(7, 54, 4),
QT_MOC_LITERAL(8, 59, 4),
QT_MOC_LITERAL(9, 64, 6)
    },
    "PrivateMessagesController\0index\0\0show\0"
    "pk\0entry\0create\0edit\0save\0remove\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrivateMessagesController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x0a,
       3,    1,   50,    2, 0x0a,
       5,    0,   53,    2, 0x0a,
       6,    0,   54,    2, 0x0a,
       7,    1,   55,    2, 0x0a,
       8,    1,   58,    2, 0x0a,
       9,    1,   61,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString,    4,

       0        // eod
};

void PrivateMessagesController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PrivateMessagesController *_t = static_cast<PrivateMessagesController *>(_o);
        switch (_id) {
        case 0: _t->index(); break;
        case 1: _t->show((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->entry(); break;
        case 3: _t->create(); break;
        case 4: _t->edit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 5: _t->save((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->remove((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject PrivateMessagesController::staticMetaObject = {
    { &ApplicationController::staticMetaObject, qt_meta_stringdata_PrivateMessagesController.data,
      qt_meta_data_PrivateMessagesController,  qt_static_metacall, 0, 0}
};


const QMetaObject *PrivateMessagesController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrivateMessagesController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrivateMessagesController.stringdata))
        return static_cast<void*>(const_cast< PrivateMessagesController*>(this));
    return ApplicationController::qt_metacast(_clname);
}

int PrivateMessagesController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApplicationController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
