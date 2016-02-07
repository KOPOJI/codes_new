/****************************************************************************
** Meta object code from reading C++ file 'profilesobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/profilesobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'profilesobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_ProfilesObject_t {
    QByteArrayData data[11];
    char stringdata[94];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_ProfilesObject_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_ProfilesObject_t qt_meta_stringdata_ProfilesObject = {
    {
QT_MOC_LITERAL(0, 0, 14),
QT_MOC_LITERAL(1, 15, 2),
QT_MOC_LITERAL(2, 18, 4),
QT_MOC_LITERAL(3, 23, 9),
QT_MOC_LITERAL(4, 33, 3),
QT_MOC_LITERAL(5, 37, 8),
QT_MOC_LITERAL(6, 46, 9),
QT_MOC_LITERAL(7, 56, 7),
QT_MOC_LITERAL(8, 64, 10),
QT_MOC_LITERAL(9, 75, 10),
QT_MOC_LITERAL(10, 86, 6)
    },
    "ProfilesObject\0id\0name\0interests\0exp\0"
    "about_me\0signature\0user_id\0created_at\0"
    "updated_at\0avatar\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ProfilesObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
      10,   14, // properties
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
       6, QMetaType::QString, 0x00095003,
       7, QMetaType::Int, 0x00095003,
       8, QMetaType::QDateTime, 0x00095003,
       9, QMetaType::QDateTime, 0x00095003,
      10, QMetaType::QString, 0x00095003,

       0        // eod
};

void ProfilesObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject ProfilesObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_ProfilesObject.data,
      qt_meta_data_ProfilesObject,  qt_static_metacall, 0, 0}
};


const QMetaObject *ProfilesObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ProfilesObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProfilesObject.stringdata))
        return static_cast<void*>(const_cast< ProfilesObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< ProfilesObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int ProfilesObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = getname(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getinterests(); break;
        case 3: *reinterpret_cast< QString*>(_v) = getexp(); break;
        case 4: *reinterpret_cast< QString*>(_v) = getabout_me(); break;
        case 5: *reinterpret_cast< QString*>(_v) = getsignature(); break;
        case 6: *reinterpret_cast< int*>(_v) = getuser_id(); break;
        case 7: *reinterpret_cast< QDateTime*>(_v) = getcreated_at(); break;
        case 8: *reinterpret_cast< QDateTime*>(_v) = getupdated_at(); break;
        case 9: *reinterpret_cast< QString*>(_v) = getavatar(); break;
        }
        _id -= 10;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setid(*reinterpret_cast< int*>(_v)); break;
        case 1: setname(*reinterpret_cast< QString*>(_v)); break;
        case 2: setinterests(*reinterpret_cast< QString*>(_v)); break;
        case 3: setexp(*reinterpret_cast< QString*>(_v)); break;
        case 4: setabout_me(*reinterpret_cast< QString*>(_v)); break;
        case 5: setsignature(*reinterpret_cast< QString*>(_v)); break;
        case 6: setuser_id(*reinterpret_cast< int*>(_v)); break;
        case 7: setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 8: setupdated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 9: setavatar(*reinterpret_cast< QString*>(_v)); break;
        }
        _id -= 10;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
