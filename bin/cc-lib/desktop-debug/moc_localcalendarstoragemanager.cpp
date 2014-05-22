/****************************************************************************
** Meta object code from reading C++ file 'localcalendarstoragemanager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/cc-lib/localcalendarstoragemanager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'localcalendarstoragemanager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_LocalCalendarStorageManager_t {
    QByteArrayData data[5];
    char stringdata[59];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_LocalCalendarStorageManager_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_LocalCalendarStorageManager_t qt_meta_stringdata_LocalCalendarStorageManager = {
    {
QT_MOC_LITERAL(0, 0, 27),
QT_MOC_LITERAL(1, 28, 4),
QT_MOC_LITERAL(2, 33, 5),
QT_MOC_LITERAL(3, 39, 8),
QT_MOC_LITERAL(4, 48, 9)
    },
    "LocalCalendarStorageManager\0file\0QFile\0"
    "calendar\0Calendar*\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_LocalCalendarStorageManager[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       2,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, 0x80000000 | 2, 0x0009500b,
       3, 0x80000000 | 4, 0x0009500b,

       0        // eod
};

void LocalCalendarStorageManager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Calendar* >(); break;
        }
    }

    Q_UNUSED(_o);
}

const QMetaObject LocalCalendarStorageManager::staticMetaObject = {
    { &IStorageManager::staticMetaObject, qt_meta_stringdata_LocalCalendarStorageManager.data,
      qt_meta_data_LocalCalendarStorageManager,  qt_static_metacall, 0, 0}
};


const QMetaObject *LocalCalendarStorageManager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *LocalCalendarStorageManager::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LocalCalendarStorageManager.stringdata))
        return static_cast<void*>(const_cast< LocalCalendarStorageManager*>(this));
    return IStorageManager::qt_metacast(_clname);
}

int LocalCalendarStorageManager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = IStorageManager::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QFile*>(_v) = m_file; break;
        case 1: *reinterpret_cast< Calendar**>(_v) = m_calendar; break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0:
            if (m_file != *reinterpret_cast< QFile*>(_v)) {
                m_file = *reinterpret_cast< QFile*>(_v);
            }
            break;
        case 1:
            if (m_calendar != *reinterpret_cast< Calendar**>(_v)) {
                m_calendar = *reinterpret_cast< Calendar**>(_v);
            }
            break;
        }
        _id -= 2;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
