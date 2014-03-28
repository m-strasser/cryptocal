/****************************************************************************
** Meta object code from reading C++ file 'calendar.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../src/cc-lib/calendar.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'calendar.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Calendar_t {
    QByteArrayData data[8];
    char stringdata[70];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Calendar_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Calendar_t qt_meta_stringdata_Calendar = {
    {
QT_MOC_LITERAL(0, 0, 8),
QT_MOC_LITERAL(1, 9, 2),
QT_MOC_LITERAL(2, 12, 4),
QT_MOC_LITERAL(3, 17, 11),
QT_MOC_LITERAL(4, 29, 5),
QT_MOC_LITERAL(5, 35, 12),
QT_MOC_LITERAL(6, 48, 6),
QT_MOC_LITERAL(7, 55, 13)
    },
    "Calendar\0id\0name\0description\0color\0"
    "synchronised\0events\0QList<Event*>\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Calendar[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       6,   14, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // properties: name, type, flags
       1, QMetaType::QUuid, 0x00095001,
       2, QMetaType::QString, 0x00095003,
       3, QMetaType::QString, 0x00095003,
       4, QMetaType::QColor, 0x00095003,
       5, QMetaType::Bool, 0x00095003,
       6, 0x80000000 | 7, 0x00095009,

       0        // eod
};

void Calendar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 5:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<Event*> >(); break;
        }
    }

    Q_UNUSED(_o);
}

const QMetaObject Calendar::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Calendar.data,
      qt_meta_data_Calendar,  qt_static_metacall, 0, 0}
};


const QMetaObject *Calendar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Calendar::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Calendar.stringdata))
        return static_cast<void*>(const_cast< Calendar*>(this));
    return QObject::qt_metacast(_clname);
}

int Calendar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    
#ifndef QT_NO_PROPERTIES
     if (_c == QMetaObject::ReadProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QUuid*>(_v) = id(); break;
        case 1: *reinterpret_cast< QString*>(_v) = m_name; break;
        case 2: *reinterpret_cast< QString*>(_v) = m_description; break;
        case 3: *reinterpret_cast< QColor*>(_v) = m_color; break;
        case 4: *reinterpret_cast< bool*>(_v) = m_synchronised; break;
        case 5: *reinterpret_cast< QList<Event*>*>(_v) = events(); break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::WriteProperty) {
        void *_v = _a[0];
        switch (_id) {
        case 1:
            if (m_name != *reinterpret_cast< QString*>(_v)) {
                m_name = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 2:
            if (m_description != *reinterpret_cast< QString*>(_v)) {
                m_description = *reinterpret_cast< QString*>(_v);
            }
            break;
        case 3:
            if (m_color != *reinterpret_cast< QColor*>(_v)) {
                m_color = *reinterpret_cast< QColor*>(_v);
            }
            break;
        case 4:
            if (m_synchronised != *reinterpret_cast< bool*>(_v)) {
                m_synchronised = *reinterpret_cast< bool*>(_v);
            }
            break;
        }
        _id -= 6;
    } else if (_c == QMetaObject::ResetProperty) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 6;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 6;
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_END_MOC_NAMESPACE
