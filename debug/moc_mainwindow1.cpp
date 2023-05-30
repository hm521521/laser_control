/****************************************************************************
** Meta object code from reading C++ file 'mainwindow1.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow1.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow1.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_main_frame_thread_t {
    QByteArrayData data[4];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_main_frame_thread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_main_frame_thread_t qt_meta_stringdata_main_frame_thread = {
    {
QT_MOC_LITERAL(0, 0, 17), // "main_frame_thread"
QT_MOC_LITERAL(1, 18, 6), // "update"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9) // "completed"

    },
    "main_frame_thread\0update\0\0completed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_main_frame_thread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   24,    2, 0x06 /* Public */,
       3,    0,   25,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void main_frame_thread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<main_frame_thread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update(); break;
        case 1: _t->completed(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (main_frame_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&main_frame_thread::update)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (main_frame_thread::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&main_frame_thread::completed)) {
                *result = 1;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject main_frame_thread::staticMetaObject = { {
    &QThread::staticMetaObject,
    qt_meta_stringdata_main_frame_thread.data,
    qt_meta_data_main_frame_thread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *main_frame_thread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *main_frame_thread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_main_frame_thread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int main_frame_thread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
void main_frame_thread::update()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void main_frame_thread::completed()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_MainWindow1_t {
    QByteArrayData data[26];
    char stringdata0[420];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow1_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow1_t qt_meta_stringdata_MainWindow1 = {
    {
QT_MOC_LITERAL(0, 0, 11), // "MainWindow1"
QT_MOC_LITERAL(1, 12, 13), // "stage_operate"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 21), // "on_hardware_triggered"
QT_MOC_LITERAL(4, 49, 26), // "on_laser_setting_triggered"
QT_MOC_LITERAL(5, 76, 29), // "on_projection_zones_triggered"
QT_MOC_LITERAL(6, 106, 27), // "on_open_workspace_triggered"
QT_MOC_LITERAL(7, 134, 20), // "on_thread_completion"
QT_MOC_LITERAL(8, 155, 16), // "on_thread_update"
QT_MOC_LITERAL(9, 172, 26), // "on_pushButton_grid_clicked"
QT_MOC_LITERAL(10, 199, 30), // "on_pushButton_timeline_clicked"
QT_MOC_LITERAL(11, 230, 22), // "on_play_button_clicked"
QT_MOC_LITERAL(12, 253, 24), // "on_output_button_clicked"
QT_MOC_LITERAL(13, 278, 11), // "eventFilter"
QT_MOC_LITERAL(14, 290, 3), // "obj"
QT_MOC_LITERAL(15, 294, 7), // "QEvent*"
QT_MOC_LITERAL(16, 302, 5), // "event"
QT_MOC_LITERAL(17, 308, 10), // "add_stages"
QT_MOC_LITERAL(18, 319, 6), // "stage*"
QT_MOC_LITERAL(19, 326, 1), // "s"
QT_MOC_LITERAL(20, 328, 14), // "refresh_stages"
QT_MOC_LITERAL(21, 343, 13), // "laser_device*"
QT_MOC_LITERAL(22, 357, 6), // "device"
QT_MOC_LITERAL(23, 364, 20), // "handle_stage_results"
QT_MOC_LITERAL(24, 385, 6), // "result"
QT_MOC_LITERAL(25, 392, 27) // "on_picture_tracer_triggered"

    },
    "MainWindow1\0stage_operate\0\0"
    "on_hardware_triggered\0on_laser_setting_triggered\0"
    "on_projection_zones_triggered\0"
    "on_open_workspace_triggered\0"
    "on_thread_completion\0on_thread_update\0"
    "on_pushButton_grid_clicked\0"
    "on_pushButton_timeline_clicked\0"
    "on_play_button_clicked\0on_output_button_clicked\0"
    "eventFilter\0obj\0QEvent*\0event\0add_stages\0"
    "stage*\0s\0refresh_stages\0laser_device*\0"
    "device\0handle_stage_results\0result\0"
    "on_picture_tracer_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   94,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,   97,    2, 0x08 /* Private */,
       4,    0,   98,    2, 0x08 /* Private */,
       5,    0,   99,    2, 0x08 /* Private */,
       6,    0,  100,    2, 0x08 /* Private */,
       7,    0,  101,    2, 0x08 /* Private */,
       8,    0,  102,    2, 0x08 /* Private */,
       9,    0,  103,    2, 0x08 /* Private */,
      10,    0,  104,    2, 0x08 /* Private */,
      11,    0,  105,    2, 0x08 /* Private */,
      12,    0,  106,    2, 0x08 /* Private */,
      13,    2,  107,    2, 0x08 /* Private */,
      17,    1,  112,    2, 0x08 /* Private */,
      20,    1,  115,    2, 0x08 /* Private */,
      23,    1,  118,    2, 0x08 /* Private */,
      25,    0,  121,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 15,   14,   16,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Int,   24,
    QMetaType::Void,

       0        // eod
};

void MainWindow1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stage_operate((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->on_hardware_triggered(); break;
        case 2: _t->on_laser_setting_triggered(); break;
        case 3: _t->on_projection_zones_triggered(); break;
        case 4: _t->on_open_workspace_triggered(); break;
        case 5: _t->on_thread_completion(); break;
        case 6: _t->on_thread_update(); break;
        case 7: _t->on_pushButton_grid_clicked(); break;
        case 8: _t->on_pushButton_timeline_clicked(); break;
        case 9: _t->on_play_button_clicked(); break;
        case 10: _t->on_output_button_clicked(); break;
        case 11: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 12: _t->add_stages((*reinterpret_cast< stage*(*)>(_a[1]))); break;
        case 13: _t->refresh_stages((*reinterpret_cast< laser_device*(*)>(_a[1]))); break;
        case 14: _t->handle_stage_results((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_picture_tracer_triggered(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 12:
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
            using _t = void (MainWindow1::*)(const bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow1::stage_operate)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow1::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow1.data,
    qt_meta_data_MainWindow1,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow1::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow1::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow1.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow1::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void MainWindow1::stage_operate(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
