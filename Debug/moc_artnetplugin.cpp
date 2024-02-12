/****************************************************************************
** Meta object code from reading C++ file 'artnetplugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../artnetplugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'artnetplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ArtNetPlugin_t {
    QByteArrayData data[11];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ArtNetPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ArtNetPlugin_t qt_meta_stringdata_ArtNetPlugin = {
    {
QT_MOC_LITERAL(0, 0, 12), // "ArtNetPlugin"
QT_MOC_LITERAL(1, 13, 12), // "valueChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "input"
QT_MOC_LITERAL(4, 33, 7), // "channel"
QT_MOC_LITERAL(5, 41, 5), // "value"
QT_MOC_LITERAL(6, 47, 20), // "configurationChanged"
QT_MOC_LITERAL(7, 68, 11), // "sendDMXData"
QT_MOC_LITERAL(8, 80, 4), // "data"
QT_MOC_LITERAL(9, 85, 21), // "slotInputValueChanged"
QT_MOC_LITERAL(10, 107, 12) // "setupDMXData"

    },
    "ArtNetPlugin\0valueChanged\0\0input\0"
    "channel\0value\0configurationChanged\0"
    "sendDMXData\0data\0slotInputValueChanged\0"
    "setupDMXData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ArtNetPlugin[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   39,    2, 0x06 /* Public */,
       6,    0,   46,    2, 0x06 /* Public */,
       7,    1,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       9,    3,   50,    2, 0x08 /* Private */,
      10,    1,   57,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::UInt, QMetaType::UChar,    3,    4,    5,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QByteArray,    8,

 // slots: parameters
    QMetaType::Void, QMetaType::UInt, QMetaType::Int, QMetaType::UChar,    3,    4,    5,
    QMetaType::Void, QMetaType::QByteArray,    8,

       0        // eod
};

void ArtNetPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ArtNetPlugin *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->valueChanged((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< quint32(*)>(_a[2])),(*reinterpret_cast< uchar(*)>(_a[3]))); break;
        case 1: _t->configurationChanged(); break;
        case 2: _t->sendDMXData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        case 3: _t->slotInputValueChanged((*reinterpret_cast< quint32(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< uchar(*)>(_a[3]))); break;
        case 4: _t->setupDMXData((*reinterpret_cast< QByteArray(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ArtNetPlugin::*)(quint32 , quint32 , uchar );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArtNetPlugin::valueChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ArtNetPlugin::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArtNetPlugin::configurationChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ArtNetPlugin::*)(QByteArray );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ArtNetPlugin::sendDMXData)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject ArtNetPlugin::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_ArtNetPlugin.data,
    qt_meta_data_ArtNetPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ArtNetPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ArtNetPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ArtNetPlugin.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ArtNetPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void ArtNetPlugin::valueChanged(quint32 _t1, quint32 _t2, uchar _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ArtNetPlugin::configurationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ArtNetPlugin::sendDMXData(QByteArray _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
