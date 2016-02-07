/****************************************************************************
** Meta object code from reading C++ file 'codesobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/codesobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'codesobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_CodesObject_t {
    QByteArrayData data[11];
    char stringdata[92];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_CodesObject_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_CodesObject_t qt_meta_stringdata_CodesObject = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 2),
QT_MOC_LITERAL(2, 15, 5),
QT_MOC_LITERAL(3, 21, 4),
QT_MOC_LITERAL(4, 26, 8),
QT_MOC_LITERAL(5, 35, 6),
QT_MOC_LITERAL(6, 42, 10),
QT_MOC_LITERAL(7, 53, 10),
QT_MOC_LITERAL(8, 64, 8),
QT_MOC_LITERAL(9, 73, 7),
QT_MOC_LITERAL(10, 81, 9)
    },
    "CodesObject\0id\0title\0code\0code_url\0"
    "status\0created_at\0updated_at\0editable\0"
    "user_id\0show_from\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CodesObject[] = {

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
       5, QMetaType::Int, 0x00095003,
       6, QMetaType::QDateTime, 0x00095003,
       7, QMetaType::QDateTime, 0x00095003,
       8, QMetaType::Int, 0x00095003,
       9, QMetaType::Int, 0x00095003,
      10, QMetaType::QString, 0x00095003,

       0        // eod
};

void CodesObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject CodesObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_CodesObject.data,
      qt_meta_data_CodesObject,  qt_static_metacall, 0, 0}
};


const QMetaObject *CodesObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CodesObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_CodesObject.stringdata))
        return static_cast<void*>(const_cast< CodesObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< CodesObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int CodesObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getid(); break;
        case 1: *reinterpret_cast< QString*>(_v) = gettitle(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getcode(); break;
        case 3: *reinterpret_cast< QString*>(_v) = getcode_url(); break;
        case 4: *reinterpret_cast< int*>(_v) = getstatus(); break;
        case 5: *reinterpret_cast< QDateTime*>(_v) = getcreated_at(); break;
        case 6: *reinterpret_cast< QDateTime*>(_v) = getupdated_at(); break;
        case 7: *reinterpret_cast< int*>(_v) = geteditable(); break;
        case 8: *reinterpret_cast< int*>(_v) = getuser_id(); break;
        case 9: *reinterpret_cast< QString*>(_v) = getshow_from(); break;
        }
        _id -= 10;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setid(*reinterpret_cast< int*>(_v)); break;
        case 1: settitle(*reinterpret_cast< QString*>(_v)); break;
        case 2: setcode(*reinterpret_cast< QString*>(_v)); break;
        case 3: setcode_url(*reinterpret_cast< QString*>(_v)); break;
        case 4: setstatus(*reinterpret_cast< int*>(_v)); break;
        case 5: setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 6: setupdated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 7: seteditable(*reinterpret_cast< int*>(_v)); break;
        case 8: setuser_id(*reinterpret_cast< int*>(_v)); break;
        case 9: setshow_from(*reinterpret_cast< QString*>(_v)); break;
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
