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
    QByteArrayData data[21];
    char stringdata0[282];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ed_v2_device_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ed_v2_device_t qt_meta_stringdata_ed_v2_device = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ed_v2_device"
QT_MOC_LITERAL(1, 13, 13), // "delete_device"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 8), // "tcp_addr"
QT_MOC_LITERAL(4, 37, 16), // "device_connected"
QT_MOC_LITERAL(5, 54, 12), // "send_command"
QT_MOC_LITERAL(6, 67, 15), // "on_socket_event"
QT_MOC_LITERAL(7, 83, 19), // "onSocketStateChange"
QT_MOC_LITERAL(8, 103, 28), // "QAbstractSocket::SocketState"
QT_MOC_LITERAL(9, 132, 5), // "state"
QT_MOC_LITERAL(10, 138, 9), // "send_data"
QT_MOC_LITERAL(11, 148, 14), // "unsigned char*"
QT_MOC_LITERAL(12, 163, 13), // "settings_data"
QT_MOC_LITERAL(13, 177, 27), // "std::vector<unsigned char>&"
QT_MOC_LITERAL(14, 205, 4), // "data"
QT_MOC_LITERAL(15, 210, 15), // "send_data_state"
QT_MOC_LITERAL(16, 226, 4), // "flag"
QT_MOC_LITERAL(17, 231, 6), // "posnum"
QT_MOC_LITERAL(18, 238, 8), // "tcpError"
QT_MOC_LITERAL(19, 247, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(20, 276, 5) // "error"

    },
    "ed_v2_device\0delete_device\0\0tcp_addr\0"
    "device_connected\0send_command\0"
    "on_socket_event\0onSocketStateChange\0"
    "QAbstractSocket::SocketState\0state\0"
    "send_data\0unsigned char*\0settings_data\0"
    "std::vector<unsigned char>&\0data\0"
    "send_data_state\0flag\0posnum\0tcpError\0"
    "QAbstractSocket::SocketError\0error"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ed_v2_device[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       4,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   55,    2, 0x08 /* Private */,
       6,    0,   56,    2, 0x0a /* Public */,
       7,    1,   57,    2, 0x0a /* Public */,
      10,    4,   60,    2, 0x0a /* Public */,
      18,    1,   69,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    3,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, 0x80000000 | 11, 0x80000000 | 13, 0x80000000 | 15, QMetaType::Int,   12,   14,   16,   17,
    QMetaType::Void, 0x80000000 | 19,   20,

       0        // eod
};

void ed_v2_device::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ed_v2_device *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->delete_device((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->device_connected((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->send_command(); break;
        case 3: _t->on_socket_event(); break;
        case 4: _t->onSocketStateChange((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 5: _t->send_data((*reinterpret_cast< unsigned char*(*)>(_a[1])),(*reinterpret_cast< std::vector<unsigned char>(*)>(_a[2])),(*reinterpret_cast< send_data_state(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 6: _t->tcpError((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketState >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ed_v2_device::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ed_v2_device::delete_device)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ed_v2_device::*)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ed_v2_device::device_connected)) {
                *result = 1;
                return;
            }
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
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void ed_v2_device::delete_device(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ed_v2_device::device_connected(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
