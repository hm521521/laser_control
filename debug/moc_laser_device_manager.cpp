/****************************************************************************
** Meta object code from reading C++ file 'laser_device_manager.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../laser_device_manager.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'laser_device_manager.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_laser_device_t {
    QByteArrayData data[11];
    char stringdata0[126];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_laser_device_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_laser_device_t qt_meta_stringdata_laser_device = {
    {
QT_MOC_LITERAL(0, 0, 12), // "laser_device"
QT_MOC_LITERAL(1, 13, 13), // "send_continue"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 9), // "send_data"
QT_MOC_LITERAL(4, 38, 16), // "unsigned char[8]"
QT_MOC_LITERAL(5, 55, 13), // "settings_data"
QT_MOC_LITERAL(6, 69, 23), // "QVector<unsigned char>&"
QT_MOC_LITERAL(7, 93, 4), // "data"
QT_MOC_LITERAL(8, 98, 15), // "send_data_state"
QT_MOC_LITERAL(9, 114, 4), // "flag"
QT_MOC_LITERAL(10, 119, 6) // "posnum"

    },
    "laser_device\0send_continue\0\0send_data\0"
    "unsigned char[8]\0settings_data\0"
    "QVector<unsigned char>&\0data\0"
    "send_data_state\0flag\0posnum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_laser_device[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    4,   25,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4, 0x80000000 | 6, 0x80000000 | 8, QMetaType::Int,    5,    7,    9,   10,

       0        // eod
};

void laser_device::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<laser_device *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_continue(); break;
        case 1: _t->send_data((*reinterpret_cast< unsigned char(*)[8]>(_a[1])),(*reinterpret_cast< QVector<unsigned char>(*)>(_a[2])),(*reinterpret_cast< send_data_state(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (laser_device::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&laser_device::send_continue)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject laser_device::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_laser_device.data,
    qt_meta_data_laser_device,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *laser_device::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *laser_device::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_laser_device.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int laser_device::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void laser_device::send_continue()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_laser_device_manager_t {
    QByteArrayData data[9];
    char stringdata0[123];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_laser_device_manager_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_laser_device_manager_t qt_meta_stringdata_laser_device_manager = {
    {
QT_MOC_LITERAL(0, 0, 20), // "laser_device_manager"
QT_MOC_LITERAL(1, 21, 15), // "manager_changed"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 22), // "QVector<laser_device*>"
QT_MOC_LITERAL(4, 61, 11), // "device_list"
QT_MOC_LITERAL(5, 73, 10), // "new_device"
QT_MOC_LITERAL(6, 84, 13), // "laser_device*"
QT_MOC_LITERAL(7, 98, 3), // "dev"
QT_MOC_LITERAL(8, 102, 20) // "refresh_laser_device"

    },
    "laser_device_manager\0manager_changed\0"
    "\0QVector<laser_device*>\0device_list\0"
    "new_device\0laser_device*\0dev\0"
    "refresh_laser_device"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_laser_device_manager[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       5,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void laser_device_manager::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<laser_device_manager *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->manager_changed((*reinterpret_cast< QVector<laser_device*>(*)>(_a[1]))); break;
        case 1: _t->new_device((*reinterpret_cast< laser_device*(*)>(_a[1]))); break;
        case 2: _t->refresh_laser_device(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<laser_device*> >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< laser_device* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (laser_device_manager::*)(QVector<laser_device*> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&laser_device_manager::manager_changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (laser_device_manager::*)(laser_device * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&laser_device_manager::new_device)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject laser_device_manager::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_laser_device_manager.data,
    qt_meta_data_laser_device_manager,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *laser_device_manager::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *laser_device_manager::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_laser_device_manager.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int laser_device_manager::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void laser_device_manager::manager_changed(QVector<laser_device*> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void laser_device_manager::new_device(laser_device * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
