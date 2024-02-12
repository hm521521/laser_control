/****************************************************************************
** Meta object code from reading C++ file 'hardware.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../hardware.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'hardware.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SubWindow_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SubWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SubWindow_t qt_meta_stringdata_SubWindow = {
    {
QT_MOC_LITERAL(0, 0, 9) // "SubWindow"

    },
    "SubWindow"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SubWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void SubWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject SubWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_SubWindow.data,
    qt_meta_data_SubWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *SubWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SubWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SubWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int SubWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_hardware_t {
    QByteArrayData data[10];
    char stringdata0[144];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hardware_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hardware_t qt_meta_stringdata_hardware = {
    {
QT_MOC_LITERAL(0, 0, 8), // "hardware"
QT_MOC_LITERAL(1, 9, 13), // "stage_changed"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 6), // "stage*"
QT_MOC_LITERAL(4, 31, 1), // "s"
QT_MOC_LITERAL(5, 33, 18), // "refresh_controller"
QT_MOC_LITERAL(6, 52, 22), // "on_Plus_Button_clicked"
QT_MOC_LITERAL(7, 75, 25), // "on_Refresh_Button_clicked"
QT_MOC_LITERAL(8, 101, 17), // "on_table_selected"
QT_MOC_LITERAL(9, 119, 24) // "on_Delete_button_clicked"

    },
    "hardware\0stage_changed\0\0stage*\0s\0"
    "refresh_controller\0on_Plus_Button_clicked\0"
    "on_Refresh_Button_clicked\0on_table_selected\0"
    "on_Delete_button_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hardware[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   44,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x08 /* Private */,
       7,    0,   49,    2, 0x08 /* Private */,
       8,    1,   50,    2, 0x08 /* Private */,
       9,    0,   53,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QVariant,    4,
    QMetaType::Void,

       0        // eod
};

void hardware::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<hardware *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stage_changed((*reinterpret_cast< stage*(*)>(_a[1]))); break;
        case 1: _t->refresh_controller(); break;
        case 2: _t->on_Plus_Button_clicked(); break;
        case 3: _t->on_Refresh_Button_clicked(); break;
        case 4: _t->on_table_selected((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 5: _t->on_Delete_button_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< stage* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hardware::*)(stage * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hardware::stage_changed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (hardware::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hardware::refresh_controller)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hardware::staticMetaObject = { {
    &SubWindow::staticMetaObject,
    qt_meta_stringdata_hardware.data,
    qt_meta_data_hardware,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *hardware::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hardware::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hardware.stringdata0))
        return static_cast<void*>(this);
    return SubWindow::qt_metacast(_clname);
}

int hardware::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SubWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void hardware::stage_changed(stage * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void hardware::refresh_controller()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_hardware_table_t {
    QByteArrayData data[7];
    char stringdata0[95];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_hardware_table_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_hardware_table_t qt_meta_stringdata_hardware_table = {
    {
QT_MOC_LITERAL(0, 0, 14), // "hardware_table"
QT_MOC_LITERAL(1, 15, 14), // "table_selected"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 1), // "s"
QT_MOC_LITERAL(4, 33, 20), // "refresh_laser_device"
QT_MOC_LITERAL(5, 54, 26), // "std::vector<laser_device*>"
QT_MOC_LITERAL(6, 81, 13) // "m_device_list"

    },
    "hardware_table\0table_selected\0\0s\0"
    "refresh_laser_device\0std::vector<laser_device*>\0"
    "m_device_list"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_hardware_table[] = {

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
       1,    1,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   27,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QVariant,    3,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    6,

       0        // eod
};

void hardware_table::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<hardware_table *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->table_selected((*reinterpret_cast< QVariant(*)>(_a[1]))); break;
        case 1: _t->refresh_laser_device((*reinterpret_cast< std::vector<laser_device*>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (hardware_table::*)(QVariant );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&hardware_table::table_selected)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject hardware_table::staticMetaObject = { {
    &QTableView::staticMetaObject,
    qt_meta_stringdata_hardware_table.data,
    qt_meta_data_hardware_table,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *hardware_table::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *hardware_table::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_hardware_table.stringdata0))
        return static_cast<void*>(this);
    return QTableView::qt_metacast(_clname);
}

int hardware_table::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
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
void hardware_table::table_selected(QVariant _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
