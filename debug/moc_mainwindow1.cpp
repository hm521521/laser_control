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
struct qt_meta_stringdata_workspace_worker_t {
    QByteArrayData data[3];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_workspace_worker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_workspace_worker_t qt_meta_stringdata_workspace_worker = {
    {
QT_MOC_LITERAL(0, 0, 16), // "workspace_worker"
QT_MOC_LITERAL(1, 17, 9), // "workspace"
QT_MOC_LITERAL(2, 27, 0) // ""

    },
    "workspace_worker\0workspace\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_workspace_worker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void workspace_worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<workspace_worker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->workspace(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (workspace_worker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&workspace_worker::workspace)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject workspace_worker::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_workspace_worker.data,
    qt_meta_data_workspace_worker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *workspace_worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *workspace_worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_workspace_worker.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(this);
    return QObject::qt_metacast(_clname);
}

int workspace_worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void workspace_worker::workspace()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_main_thread_worker_t {
    QByteArrayData data[3];
    char stringdata0[27];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_main_thread_worker_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_main_thread_worker_t qt_meta_stringdata_main_thread_worker = {
    {
QT_MOC_LITERAL(0, 0, 18), // "main_thread_worker"
QT_MOC_LITERAL(1, 19, 6), // "update"
QT_MOC_LITERAL(2, 26, 0) // ""

    },
    "main_thread_worker\0update\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_main_thread_worker[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void main_thread_worker::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<main_thread_worker *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->update(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (main_thread_worker::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&main_thread_worker::update)) {
                *result = 0;
                return;
            }
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject main_thread_worker::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_main_thread_worker.data,
    qt_meta_data_main_thread_worker,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *main_thread_worker::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *main_thread_worker::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_main_thread_worker.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QRunnable"))
        return static_cast< QRunnable*>(this);
    return QObject::qt_metacast(_clname);
}

int main_thread_worker::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void main_thread_worker::update()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_MainWindow1_t {
    QByteArrayData data[36];
    char stringdata0[690];
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
QT_MOC_LITERAL(20, 328, 18), // "set_publicize_play"
QT_MOC_LITERAL(21, 347, 14), // "refresh_stages"
QT_MOC_LITERAL(22, 362, 13), // "laser_device*"
QT_MOC_LITERAL(23, 376, 6), // "device"
QT_MOC_LITERAL(24, 383, 20), // "handle_stage_results"
QT_MOC_LITERAL(25, 404, 6), // "result"
QT_MOC_LITERAL(26, 411, 27), // "on_picture_tracer_triggered"
QT_MOC_LITERAL(27, 439, 22), // "on_publicize_triggered"
QT_MOC_LITERAL(28, 462, 14), // "open_workspace"
QT_MOC_LITERAL(29, 477, 26), // "on_test_patterns_triggered"
QT_MOC_LITERAL(30, 504, 32), // "on_DMX_ArtNet_Settings_triggered"
QT_MOC_LITERAL(31, 537, 37), // "on_Setup_Administritor_Mode_t..."
QT_MOC_LITERAL(32, 575, 28), // "on_Setup_User_Mode_triggered"
QT_MOC_LITERAL(33, 604, 25), // "on_Midi_Monitor_triggered"
QT_MOC_LITERAL(34, 630, 33), // "on_Midi_Device_Settings_trigg..."
QT_MOC_LITERAL(35, 664, 25) // "on_OSC_Settings_triggered"

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
    "stage*\0s\0set_publicize_play\0refresh_stages\0"
    "laser_device*\0device\0handle_stage_results\0"
    "result\0on_picture_tracer_triggered\0"
    "on_publicize_triggered\0open_workspace\0"
    "on_test_patterns_triggered\0"
    "on_DMX_ArtNet_Settings_triggered\0"
    "on_Setup_Administritor_Mode_triggered\0"
    "on_Setup_User_Mode_triggered\0"
    "on_Midi_Monitor_triggered\0"
    "on_Midi_Device_Settings_triggered\0"
    "on_OSC_Settings_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      26,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  144,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    0,  147,    2, 0x08 /* Private */,
       4,    0,  148,    2, 0x08 /* Private */,
       5,    0,  149,    2, 0x08 /* Private */,
       6,    0,  150,    2, 0x08 /* Private */,
       7,    0,  151,    2, 0x08 /* Private */,
       8,    0,  152,    2, 0x08 /* Private */,
       9,    0,  153,    2, 0x08 /* Private */,
      10,    0,  154,    2, 0x08 /* Private */,
      11,    0,  155,    2, 0x08 /* Private */,
      12,    0,  156,    2, 0x08 /* Private */,
      13,    2,  157,    2, 0x08 /* Private */,
      17,    1,  162,    2, 0x08 /* Private */,
      20,    0,  165,    2, 0x08 /* Private */,
      21,    1,  166,    2, 0x08 /* Private */,
      24,    1,  169,    2, 0x08 /* Private */,
      26,    0,  172,    2, 0x08 /* Private */,
      27,    0,  173,    2, 0x08 /* Private */,
      28,    0,  174,    2, 0x08 /* Private */,
      29,    0,  175,    2, 0x08 /* Private */,
      30,    0,  176,    2, 0x08 /* Private */,
      31,    0,  177,    2, 0x08 /* Private */,
      32,    0,  178,    2, 0x08 /* Private */,
      33,    0,  179,    2, 0x08 /* Private */,
      34,    0,  180,    2, 0x08 /* Private */,
      35,    0,  181,    2, 0x08 /* Private */,

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
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 22,   23,
    QMetaType::Void, QMetaType::Int,   25,
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
        case 13: _t->set_publicize_play(); break;
        case 14: _t->refresh_stages((*reinterpret_cast< laser_device*(*)>(_a[1]))); break;
        case 15: _t->handle_stage_results((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_picture_tracer_triggered(); break;
        case 17: _t->on_publicize_triggered(); break;
        case 18: _t->open_workspace(); break;
        case 19: _t->on_test_patterns_triggered(); break;
        case 20: _t->on_DMX_ArtNet_Settings_triggered(); break;
        case 21: _t->on_Setup_Administritor_Mode_triggered(); break;
        case 22: _t->on_Setup_User_Mode_triggered(); break;
        case 23: _t->on_Midi_Monitor_triggered(); break;
        case 24: _t->on_Midi_Device_Settings_triggered(); break;
        case 25: _t->on_OSC_Settings_triggered(); break;
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
        case 14:
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
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 26)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 26;
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
