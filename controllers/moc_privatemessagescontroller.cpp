/****************************************************************************
** Meta object code from reading C++ file 'privatemessagescontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "privatemessagescontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'privatemessagescontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PrivateMessagesController_t {
    QByteArrayData data[11];
    char stringdata[78];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_PrivateMessagesController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_PrivateMessagesController_t qt_meta_stringdata_PrivateMessagesController = {
    {
QT_MOC_LITERAL(0, 0, 25),
QT_MOC_LITERAL(1, 26, 5),
QT_MOC_LITERAL(2, 32, 0),
QT_MOC_LITERAL(3, 33, 6),
QT_MOC_LITERAL(4, 40, 4),
QT_MOC_LITERAL(5, 45, 2),
QT_MOC_LITERAL(6, 48, 5),
QT_MOC_LITERAL(7, 54, 6),
QT_MOC_LITERAL(8, 61, 4),
QT_MOC_LITERAL(9, 66, 4),
QT_MOC_LITERAL(10, 71, 6)
    },
    "PrivateMessagesController\0inbox\0\0"
    "outbox\0show\0pk\0entry\0create\0edit\0save\0"
    "remove"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrivateMessagesController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x0a /* Public */,
       3,    0,   55,    2, 0x0a /* Public */,
       4,    1,   56,    2, 0x0a /* Public */,
       6,    0,   59,    2, 0x0a /* Public */,
       7,    0,   60,    2, 0x0a /* Public */,
       8,    1,   61,    2, 0x0a /* Public */,
       9,    1,   64,    2, 0x0a /* Public */,
      10,    1,   67,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void PrivateMessagesController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        PrivateMessagesController *_t = static_cast<PrivateMessagesController *>(_o);
        switch (_id) {
        case 0: _t->inbox(); break;
        case 1: _t->outbox(); break;
        case 2: _t->show((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->entry(); break;
        case 4: _t->create(); break;
        case 5: _t->edit((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 6: _t->save((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->remove((*reinterpret_cast< const QString(*)>(_a[1]))); break;
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
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
