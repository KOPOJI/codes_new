/****************************************************************************
** Meta object code from reading C++ file 'accountcontroller.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "accountcontroller.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'accountcontroller.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AccountController_t {
    QByteArrayData data[12];
    char stringdata[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AccountController_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AccountController_t qt_meta_stringdata_AccountController = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 5),
QT_MOC_LITERAL(2, 24, 0),
QT_MOC_LITERAL(3, 25, 4),
QT_MOC_LITERAL(4, 30, 5),
QT_MOC_LITERAL(5, 36, 6),
QT_MOC_LITERAL(6, 43, 12),
QT_MOC_LITERAL(7, 56, 7),
QT_MOC_LITERAL(8, 64, 15),
QT_MOC_LITERAL(9, 80, 6),
QT_MOC_LITERAL(10, 87, 11),
QT_MOC_LITERAL(11, 99, 17)
    },
    "AccountController\0users\0\0form\0login\0"
    "logout\0registration\0profile\0showUserProfile\0"
    "userId\0editProfile\0editProfileAvatar\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AccountController[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x0a,
       3,    0,   60,    2, 0x0a,
       4,    0,   61,    2, 0x0a,
       5,    0,   62,    2, 0x0a,
       6,    0,   63,    2, 0x0a,
       7,    0,   64,    2, 0x0a,
       8,    1,   65,    2, 0x0a,
      10,    0,   68,    2, 0x0a,
      11,    1,   69,    2, 0x0a,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    9,

       0        // eod
};

void AccountController::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AccountController *_t = static_cast<AccountController *>(_o);
        switch (_id) {
        case 0: _t->users(); break;
        case 1: _t->form(); break;
        case 2: _t->login(); break;
        case 3: _t->logout(); break;
        case 4: _t->registration(); break;
        case 5: _t->profile(); break;
        case 6: _t->showUserProfile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->editProfile(); break;
        case 8: _t->editProfileAvatar((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject AccountController::staticMetaObject = {
    { &ApplicationController::staticMetaObject, qt_meta_stringdata_AccountController.data,
      qt_meta_data_AccountController,  qt_static_metacall, 0, 0}
};


const QMetaObject *AccountController::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AccountController::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AccountController.stringdata))
        return static_cast<void*>(const_cast< AccountController*>(this));
    return ApplicationController::qt_metacast(_clname);
}

int AccountController::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = ApplicationController::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
