/****************************************************************************
** Meta object code from reading C++ file 'attachmentsobject.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.0.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "sqlobjects/attachmentsobject.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'attachmentsobject.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.0.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_AttachmentsObject_t {
    QByteArrayData data[6];
    char stringdata[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_AttachmentsObject_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_AttachmentsObject_t qt_meta_stringdata_AttachmentsObject = {
    {
QT_MOC_LITERAL(0, 0, 17),
QT_MOC_LITERAL(1, 18, 2),
QT_MOC_LITERAL(2, 21, 7),
QT_MOC_LITERAL(3, 29, 5),
QT_MOC_LITERAL(4, 35, 10),
QT_MOC_LITERAL(5, 46, 10)
    },
    "AttachmentsObject\0id\0code_id\0image\0"
    "created_at\0updated_at\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AttachmentsObject[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       5,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::Int, 0x00095003,
       2, QMetaType::Int, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::QDateTime, 0x00095003,
       5, QMetaType::QDateTime, 0x00095003,

       0        // eod
};

void AttachmentsObject::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

const QMetaObject AttachmentsObject::staticMetaObject = {
    { &TSqlObject::staticMetaObject, qt_meta_stringdata_AttachmentsObject.data,
      qt_meta_data_AttachmentsObject,  qt_static_metacall, 0, 0}
};


const QMetaObject *AttachmentsObject::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AttachmentsObject::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_AttachmentsObject.stringdata))
        return static_cast<void*>(const_cast< AttachmentsObject*>(this));
    if (!strcmp(_clname, "QSharedData"))
        return static_cast< QSharedData*>(const_cast< AttachmentsObject*>(this));
    return TSqlObject::qt_metacast(_clname);
}

int AttachmentsObject::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = TSqlObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< int*>(_v) = getid(); break;
        case 1: *reinterpret_cast< int*>(_v) = getcode_id(); break;
        case 2: *reinterpret_cast< QString*>(_v) = getimage(); break;
        case 3: *reinterpret_cast< QDateTime*>(_v) = getcreated_at(); break;
        case 4: *reinterpret_cast< QDateTime*>(_v) = getupdated_at(); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: setid(*reinterpret_cast< int*>(_v)); break;
        case 1: setcode_id(*reinterpret_cast< int*>(_v)); break;
        case 2: setimage(*reinterpret_cast< QString*>(_v)); break;
        case 3: setcreated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        case 4: setupdated_at(*reinterpret_cast< QDateTime*>(_v)); break;
        }
        _id -= 5;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
