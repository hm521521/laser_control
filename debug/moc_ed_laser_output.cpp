/****************************************************************************
** Meta object code from reading C++ file 'ed_laser_output.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ed_laser_output.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ed_laser_output.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ed_v2_device_t {
    QByteArrayData data[15];
    char stringdata0[194];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ed_v2_device_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ed_v2_device_t qt_meta_stringdata_ed_v2_device = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ed_v2_device"
QT_MOC_LITERAL(1, 13, 12), // "send_command"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 15), // "on_socket_event"
QT_MOC_LITERAL(4, 43, 19), // "onSocketStateChange"
QT_MOC_LITERAL(5, 63, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(6, 92, 5), // "state"
QT_MOC_LITERAL(7, 98, 9), // "send_data"
QT_MOC_LITERAL(8, 108, 14), // "unsigned char*"
QT_MOC_LITERAL(9, 123, 13), // "settings_data"
QT_MOC_LITERAL(10, 137, 23), // "QVector<unsigned char>&"
QT_MOC_LITERAL(11, 161, 4), // "data"
QT_MOC_LITERAL(12, 166, 15), // "send_data_state"
QT_MOC_LITERAL(13, 182, 4), // "flag"
QT_MOC_LITERAL(14, 187, 6) // "posnum"

    },
    "ed_v2_device\0send_command\0\0on_socket_event\0"
    "onSocketStateChange\0QAbstractSocket::SocketState\0"
    "state\0send_data\0unsigned char*\0"
    "settings_data\0QVector<unsigned char>&\0"
    "data\0send_data_state\0flag\0posnum"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ed_v2_device[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   34,    2, 0x08 /* Private */,
       3,    0,   35,    2, 0x0a /* Public */,
       4,    1,   36,    2, 0x0a /* Public */,
       7,    4,   39,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void, 0x80000000 | 8, 0x80000000 | 10, 0x80000000 | 12, QMetaType::Int,    9,   11,   13,   14,

       0        // eod
};

void ed_v2_device::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ed_v2_device *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->send_command(); break;
        case 1: _t->on_socket_event(); break;
        case 2: _t->onSocketStateChange((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 3: _t->send_data((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< QVector<unsigned char>(*)>(_a[2])),(*reinterpret_cast< send_data_state(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ed_v2_device::staticMetaObject = { {
    &laser_device::staticMetaObject,
    qt_meta_stringdata_ed_v2_device.data,
    qt_meta_data_ed_v2_device,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ed_v2_device::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ed_v2_device::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ed_v2_device.stringdata0))
        return static_cast<void*>(this);
    return laser_device::qt_metacast(_clname);
}

int ed_v2_device::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = laser_device::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
struct qt_meta_stringdata_ed_v2_device_finder_t {
    QByteArrayData data[3];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ed_v2_device_finder_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ed_v2_device_finder_t qt_meta_stringdata_ed_v2_device_finder = {
    {
QT_MOC_LITERAL(0, 0, 19), // "ed_v2_device_finder"
QT_MOC_LITERAL(1, 20, 15), // "on_socket_event"
QT_MOC_LITERAL(2, 36, 0) // ""

    },
    "ed_v2_device_finder\0on_socket_event\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ed_v2_device_finder[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void ed_v2_device_finder::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ed_v2_device_finder *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_socket_event(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject ed_v2_device_finder::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ed_v2_device_finder.data,
    qt_meta_data_ed_v2_device_finder,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ed_v2_device_finder::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ed_v2_device_finder::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ed_v2_device_finder.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ed_v2_device_finder::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
