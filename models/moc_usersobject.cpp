/****************************************************************************
** Meta object code from reading C++ file 'usersobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/usersobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usersobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_UsersObject_t {
    QByteArrayData data[22];
    char stringdata[330];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_UsersObject_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_UsersObject_t qt_meta_stringdata_UsersObject = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 2),
QT_MOC_LITERAL(2, 15, 8),
QT_MOC_LITERAL(3, 24, 5),
QT_MOC_LITERAL(4, 30, 18),
QT_MOC_LITERAL(5, 49, 20),
QT_MOC_LITERAL(6, 70, 22),
QT_MOC_LITERAL(7, 93, 19),
QT_MOC_LITERAL(8, 113, 13),
QT_MOC_LITERAL(9, 127, 18),
QT_MOC_LITERAL(10, 146, 15),
QT_MOC_LITERAL(11, 162, 18),
QT_MOC_LITERAL(12, 181, 15),
QT_MOC_LITERAL(13, 197, 18),
QT_MOC_LITERAL(14, 216, 12),
QT_MOC_LITERAL(15, 229, 20),
QT_MOC_LITERAL(16, 250, 17),
QT_MOC_LITERAL(17, 268, 15),
QT_MOC_LITERAL(18, 284, 12),
QT_MOC_LITERAL(19, 297, 9),
QT_MOC_LITERAL(20, 307, 10),
QT_MOC_LITERAL(21, 318, 10)
    },
    "UsersObject\0id\0username\0email\0"
    "encrypted_password\0reset_password_token\0"
    "reset_password_sent_at\0remember_created_at\0"
    "sign_in_count\0current_sign_in_at\0"
    "last_sign_in_at\0current_sign_in_ip\0"
    "last_sign_in_ip\0confirmation_token\0"
    "confirmed_at\0confirmation_sent_at\0"
    "unconfirmed_email\0failed_attempts\0"
    "unlock_token\0locked_at\0created_at\0"
    "updated_at\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_UsersObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      21,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::QString, 0x00095003,
       5, QMetaType::QString, 0x00095003,
       6, QMetaType::QDateTime, 0x00095003,
       7, QMetaType::QDateTime, 0x00095003,
       8, QMetaType::Int, 0x00095003,
       9, QMetaType::QDateTime, 0x00095003,
      10, QMetaType::QDateTime, 0x00095003,
      11, QMetaType::QString, 0x00095003,
      12, QMetaType::QString, 0x00095003,
      13, QMetaType::QString, 0x00095003,
      14, QMetaType::QDateTime, 0x00095003,
      15, QMetaType::QDateTime, 0x00095003,
      16, QMetaType::QString, 0x00095003,
      17, QMetaType::Int, 0x00095003,
      18, QMetaType::QString, 0x00095003,
      19, QMetaType::QDateTime, 0x00095003,
      20, QMetaType::QDateTime, 0x00095003,
      21, QMetaType::QDateTime, 0x00095003,

       0        // eod
};

void UsersObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject UsersObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_UsersObject.data,
      qt_meta_data_UsersObject,  qt_static_metacall, 0, 0}
};


const QMetaObject *UsersObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UsersObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UsersObject.stringdata))
        return static_cast<void*>(const_cast< UsersObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< UsersObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int UsersObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getusername(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getemail(); break;
        case 3: *reinterpret_cast< QString*>(_v) = getencrypted_password(); break;
        case 4: *reinterpret_cast< QString*>(_v) = getreset_password_token(); break;
        case 5: *reinterpret_cast< QDateTime*>(_v) = getreset_password_sent_at(); break;
        case 6: *reinterpret_cast< QDateTime*>(_v) = getremember_created_at(); break;
        case 7: *reinterpret_cast< int*>(_v) = getsign_in_count(); break;
        case 8: *reinterpret_cast< QDateTime*>(_v) = getcurrent_sign_in_at(); break;
        case 9: *reinterpret_cast< QDateTime*>(_v) = getlast_sign_in_at(); break;
        case 10: *reinterpret_cast< QString*>(_v) = getcurrent_sign_in_ip(); break;
        case 11: *reinterpret_cast< QString*>(_v) = getlast_sign_in_ip(); break;
        case 12: *reinterpret_cast< QString*>(_v) = getconfirmation_token(); break;
        case 13: *reinterpret_cast< QDateTime*>(_v) = getconfirmed_at(); break;
        case 14: *reinterpret_cast< QDateTime*>(_v) = getconfirmation_sent_at(); break;
        case 15: *reinterpret_cast< QString*>(_v) = getunconfirmed_email(); break;
        case 16: *reinterpret_cast< int*>(_v) = getfailed_attempts(); break;
        case 17: *reinterpret_cast< QString*>(_v) = getunlock_token(); break;
        case 18: *reinterpret_cast< QDateTime*>(_v) = getlocked_at(); break;
        case 19: *reinterpret_cast< QDateTime*>(_v) = getcreated_at(); break;
        case 20: *reinterpret_cast< QDateTime*>(_v) = getupdated_at(); break;
        }
        _id -= 21;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setid(*reinterpret_cast< int*>(_v)); break;
        case 1: setusername(*reinterpret_cast< QString*>(_v)); break;
        case 2: setemail(*reinterpret_cast< QString*>(_v)); break;
        case 3: setencrypted_password(*reinterpret_cast< QString*>(_v)); break;
        case 4: setreset_password_token(*reinterpret_cast< QString*>(_v)); break;
        case 5: setreset_password_sent_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 6: setremember_created_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 7: setsign_in_count(*reinterpret_cast< int*>(_v)); break;
        case 8: setcurrent_sign_in_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 9: setlast_sign_in_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 10: setcurrent_sign_in_ip(*reinterpret_cast< QString*>(_v)); break;
        case 11: setlast_sign_in_ip(*reinterpret_cast< QString*>(_v)); break;
        case 12: setconfirmation_token(*reinterpret_cast< QString*>(_v)); break;
        case 13: setconfirmed_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 14: setconfirmation_sent_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 15: setunconfirmed_email(*reinterpret_cast< QString*>(_v)); break;
        case 16: setfailed_attempts(*reinterpret_cast< int*>(_v)); break;
        case 17: setunlock_token(*reinterpret_cast< QString*>(_v)); break;
        case 18: setlocked_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 19: setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 20: setupdated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        }
        _id -= 21;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 21;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 21;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
