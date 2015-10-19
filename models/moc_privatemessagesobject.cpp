/****************************************************************************
** Meta object code from reading C++ file 'privatemessagesobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/privatemessagesobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'privatemessagesobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_PrivateMessagesObject_t {
    QByteArrayData data[13];
    char stringdata[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_PrivateMessagesObject_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_PrivateMessagesObject_t qt_meta_stringdata_PrivateMessagesObject = {
    {
QT_MOC_LITERAL(0, 0, 21),
QT_MOC_LITERAL(1, 22, 2),
QT_MOC_LITERAL(2, 25, 12),
QT_MOC_LITERAL(3, 38, 10),
QT_MOC_LITERAL(4, 49, 5),
QT_MOC_LITERAL(5, 55, 4),
QT_MOC_LITERAL(6, 60, 4),
QT_MOC_LITERAL(7, 65, 20),
QT_MOC_LITERAL(8, 86, 18),
QT_MOC_LITERAL(9, 105, 4),
QT_MOC_LITERAL(10, 110, 10),
QT_MOC_LITERAL(11, 121, 10),
QT_MOC_LITERAL(12, 132, 13)
    },
    "PrivateMessagesObject\0id\0user_from_id\0"
    "user_to_id\0title\0text\0file\0"
    "deleted_by_from_user\0deleted_by_to_user\0"
    "read\0created_at\0updated_at\0to_message_id\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_PrivateMessagesObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      12,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::Int, 0x00095003,
       3, QMetaType::Int, 0x00095003,
       4, QMetaType::QString, 0x00095003,
       5, QMetaType::QString, 0x00095003,
       6, QMetaType::QString, 0x00095003,
       7, QMetaType::Int, 0x00095003,
       8, QMetaType::Int, 0x00095003,
       9, QMetaType::Int, 0x00095003,
      10, QMetaType::QDateTime, 0x00095003,
      11, QMetaType::QDateTime, 0x00095003,
      12, QMetaType::Int, 0x00095003,

       0        // eod
};

void PrivateMessagesObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject PrivateMessagesObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_PrivateMessagesObject.data,
      qt_meta_data_PrivateMessagesObject,  qt_static_metacall, 0, 0}
};


const QMetaObject *PrivateMessagesObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *PrivateMessagesObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_PrivateMessagesObject.stringdata))
        return static_cast<void*>(const_cast< PrivateMessagesObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< PrivateMessagesObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int PrivateMessagesObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getid(); break;
        case 1: *reinterpret_cast< int*>(_v) = getuser_from_id(); break;
        case 2: *reinterpret_cast< int*>(_v) = getuser_to_id(); break;
        case 3: *reinterpret_cast< QString*>(_v) = gettitle(); break;
        case 4: *reinterpret_cast< QString*>(_v) = gettext(); break;
        case 5: *reinterpret_cast< QString*>(_v) = getfile(); break;
        case 6: *reinterpret_cast< int*>(_v) = getdeleted_by_from_user(); break;
        case 7: *reinterpret_cast< int*>(_v) = getdeleted_by_to_user(); break;
        case 8: *reinterpret_cast< int*>(_v) = getread(); break;
        case 9: *reinterpret_cast< QDateTime*>(_v) = getcreated_at(); break;
        case 10: *reinterpret_cast< QDateTime*>(_v) = getupdated_at(); break;
        case 11: *reinterpret_cast< int*>(_v) = getto_message_id(); break;
        }
        _id -= 12;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setid(*reinterpret_cast< int*>(_v)); break;
        case 1: setuser_from_id(*reinterpret_cast< int*>(_v)); break;
        case 2: setuser_to_id(*reinterpret_cast< int*>(_v)); break;
        case 3: settitle(*reinterpret_cast< QString*>(_v)); break;
        case 4: settext(*reinterpret_cast< QString*>(_v)); break;
        case 5: setfile(*reinterpret_cast< QString*>(_v)); break;
        case 6: setdeleted_by_from_user(*reinterpret_cast< int*>(_v)); break;
        case 7: setdeleted_by_to_user(*reinterpret_cast< int*>(_v)); break;
        case 8: setread(*reinterpret_cast< int*>(_v)); break;
        case 9: setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 10: setupdated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 11: setto_message_id(*reinterpret_cast< int*>(_v)); break;
        }
        _id -= 12;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 12;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 12;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
