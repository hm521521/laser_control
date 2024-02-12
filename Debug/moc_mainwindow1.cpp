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
struct qt_meta_stringdata_artnetdmx_slider_t {
    QByteArrayData data[6];
    char stringdata0[63];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_artnetdmx_slider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_artnetdmx_slider_t qt_meta_stringdata_artnetdmx_slider = {
    {
QT_MOC_LITERAL(0, 0, 16), // "artnetdmx_slider"
QT_MOC_LITERAL(1, 17, 13), // "value_changed"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 5), // "index"
QT_MOC_LITERAL(4, 38, 5), // "value"
QT_MOC_LITERAL(5, 44, 18) // "deal_value_changed"

    },
    "artnetdmx_slider\0value_changed\0\0index\0"
    "value\0deal_value_changed"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_artnetdmx_slider[] = {

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
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   29,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    4,

       0        // eod
};

void artnetdmx_slider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<artnetdmx_slider *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->value_changed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->deal_value_changed((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (artnetdmx_slider::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&artnetdmx_slider::value_changed)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject artnetdmx_slider::staticMetaObject = { {
    &QSlider::staticMetaObject,
    qt_meta_stringdata_artnetdmx_slider.data,
    qt_meta_data_artnetdmx_slider,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *artnetdmx_slider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *artnetdmx_slider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_artnetdmx_slider.stringdata0))
        return static_cast<void*>(this);
    return QSlider::qt_metacast(_clname);
}

int artnetdmx_slider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSlider::qt_metacall(_c, _id, _a);
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
void artnetdmx_slider::value_changed(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_MainWindow1_t {
    QByteArrayData data[51];
    char stringdata0[883];
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
QT_MOC_LITERAL(3, 27, 12), // "dialog_close"
QT_MOC_LITERAL(4, 40, 21), // "on_hardware_triggered"
QT_MOC_LITERAL(5, 62, 26), // "on_laser_setting_triggered"
QT_MOC_LITERAL(6, 89, 29), // "on_projection_zones_triggered"
QT_MOC_LITERAL(7, 119, 27), // "on_open_workspace_triggered"
QT_MOC_LITERAL(8, 147, 26), // "on_pushButton_grid_clicked"
QT_MOC_LITERAL(9, 174, 30), // "on_pushButton_timeline_clicked"
QT_MOC_LITERAL(10, 205, 22), // "on_play_button_clicked"
QT_MOC_LITERAL(11, 228, 11), // "eventFilter"
QT_MOC_LITERAL(12, 240, 3), // "obj"
QT_MOC_LITERAL(13, 244, 7), // "QEvent*"
QT_MOC_LITERAL(14, 252, 5), // "event"
QT_MOC_LITERAL(15, 258, 10), // "add_stages"
QT_MOC_LITERAL(16, 269, 6), // "stage*"
QT_MOC_LITERAL(17, 276, 1), // "s"
QT_MOC_LITERAL(18, 278, 18), // "set_publicize_play"
QT_MOC_LITERAL(19, 297, 15), // "output_universe"
QT_MOC_LITERAL(20, 313, 14), // "refresh_stages"
QT_MOC_LITERAL(21, 328, 26), // "std::vector<laser_device*>"
QT_MOC_LITERAL(22, 355, 4), // "list"
QT_MOC_LITERAL(23, 360, 20), // "handle_stage_results"
QT_MOC_LITERAL(24, 381, 6), // "result"
QT_MOC_LITERAL(25, 388, 27), // "on_picture_tracer_triggered"
QT_MOC_LITERAL(26, 416, 22), // "on_publicize_triggered"
QT_MOC_LITERAL(27, 439, 14), // "open_workspace"
QT_MOC_LITERAL(28, 454, 26), // "on_test_patterns_triggered"
QT_MOC_LITERAL(29, 481, 32), // "on_DMX_ArtNet_Settings_triggered"
QT_MOC_LITERAL(30, 514, 37), // "on_Setup_Administritor_Mode_t..."
QT_MOC_LITERAL(31, 552, 28), // "on_Setup_User_Mode_triggered"
QT_MOC_LITERAL(32, 581, 25), // "on_Midi_Monitor_triggered"
QT_MOC_LITERAL(33, 607, 33), // "on_Midi_Device_Settings_trigg..."
QT_MOC_LITERAL(34, 641, 25), // "on_OSC_Settings_triggered"
QT_MOC_LITERAL(35, 667, 19), // "update_output_scene"
QT_MOC_LITERAL(36, 687, 3), // "idx"
QT_MOC_LITERAL(37, 691, 17), // "main_timer_update"
QT_MOC_LITERAL(38, 709, 17), // "line_timer_update"
QT_MOC_LITERAL(39, 727, 17), // "update_show_scene"
QT_MOC_LITERAL(40, 745, 14), // "readSinglePage"
QT_MOC_LITERAL(41, 760, 4), // "page"
QT_MOC_LITERAL(42, 765, 19), // "readQuickSinglePage"
QT_MOC_LITERAL(43, 785, 24), // "on_output_button_clicked"
QT_MOC_LITERAL(44, 810, 17), // "set_artnet_server"
QT_MOC_LITERAL(45, 828, 12), // "setupDMXData"
QT_MOC_LITERAL(46, 841, 2), // "id"
QT_MOC_LITERAL(47, 844, 5), // "value"
QT_MOC_LITERAL(48, 850, 14), // "recieveSection"
QT_MOC_LITERAL(49, 865, 9), // "CJSection"
QT_MOC_LITERAL(50, 875, 7) // "section"

    },
    "MainWindow1\0stage_operate\0\0dialog_close\0"
    "on_hardware_triggered\0on_laser_setting_triggered\0"
    "on_projection_zones_triggered\0"
    "on_open_workspace_triggered\0"
    "on_pushButton_grid_clicked\0"
    "on_pushButton_timeline_clicked\0"
    "on_play_button_clicked\0eventFilter\0"
    "obj\0QEvent*\0event\0add_stages\0stage*\0"
    "s\0set_publicize_play\0output_universe\0"
    "refresh_stages\0std::vector<laser_device*>\0"
    "list\0handle_stage_results\0result\0"
    "on_picture_tracer_triggered\0"
    "on_publicize_triggered\0open_workspace\0"
    "on_test_patterns_triggered\0"
    "on_DMX_ArtNet_Settings_triggered\0"
    "on_Setup_Administritor_Mode_triggered\0"
    "on_Setup_User_Mode_triggered\0"
    "on_Midi_Monitor_triggered\0"
    "on_Midi_Device_Settings_triggered\0"
    "on_OSC_Settings_triggered\0update_output_scene\0"
    "idx\0main_timer_update\0line_timer_update\0"
    "update_show_scene\0readSinglePage\0page\0"
    "readQuickSinglePage\0on_output_button_clicked\0"
    "set_artnet_server\0setupDMXData\0id\0"
    "value\0recieveSection\0CJSection\0section"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow1[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      35,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  189,    2, 0x06 /* Public */,
       3,    0,  192,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    0,  193,    2, 0x08 /* Private */,
       5,    0,  194,    2, 0x08 /* Private */,
       6,    0,  195,    2, 0x08 /* Private */,
       7,    0,  196,    2, 0x08 /* Private */,
       8,    0,  197,    2, 0x08 /* Private */,
       9,    0,  198,    2, 0x08 /* Private */,
      10,    0,  199,    2, 0x08 /* Private */,
      11,    2,  200,    2, 0x08 /* Private */,
      15,    1,  205,    2, 0x08 /* Private */,
      18,    0,  208,    2, 0x08 /* Private */,
      19,    0,  209,    2, 0x08 /* Private */,
      20,    1,  210,    2, 0x08 /* Private */,
      23,    1,  213,    2, 0x08 /* Private */,
      25,    0,  216,    2, 0x08 /* Private */,
      26,    0,  217,    2, 0x08 /* Private */,
      27,    0,  218,    2, 0x08 /* Private */,
      28,    0,  219,    2, 0x08 /* Private */,
      29,    0,  220,    2, 0x08 /* Private */,
      30,    0,  221,    2, 0x08 /* Private */,
      31,    0,  222,    2, 0x08 /* Private */,
      32,    0,  223,    2, 0x08 /* Private */,
      33,    0,  224,    2, 0x08 /* Private */,
      34,    0,  225,    2, 0x08 /* Private */,
      35,    1,  226,    2, 0x08 /* Private */,
      37,    0,  229,    2, 0x08 /* Private */,
      38,    0,  230,    2, 0x08 /* Private */,
      39,    1,  231,    2, 0x08 /* Private */,
      40,    1,  234,    2, 0x08 /* Private */,
      42,    1,  237,    2, 0x08 /* Private */,
      43,    0,  240,    2, 0x08 /* Private */,
      44,    0,  241,    2, 0x0a /* Public */,
      45,    2,  242,    2, 0x0a /* Public */,
      48,    1,  247,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QObjectStar, 0x80000000 | 13,   12,   14,
    QMetaType::Void, 0x80000000 | 16,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 21,   22,
    QMetaType::Void, QMetaType::Int,   24,
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
    QMetaType::Void, QMetaType::Int,   36,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   36,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void, QMetaType::Int,   41,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   46,   47,
    QMetaType::Void, 0x80000000 | 49,   50,

       0        // eod
};

void MainWindow1::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow1 *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->stage_operate((*reinterpret_cast< const bool(*)>(_a[1]))); break;
        case 1: _t->dialog_close(); break;
        case 2: _t->on_hardware_triggered(); break;
        case 3: _t->on_laser_setting_triggered(); break;
        case 4: _t->on_projection_zones_triggered(); break;
        case 5: _t->on_open_workspace_triggered(); break;
        case 6: _t->on_pushButton_grid_clicked(); break;
        case 7: _t->on_pushButton_timeline_clicked(); break;
        case 8: _t->on_play_button_clicked(); break;
        case 9: { bool _r = _t->eventFilter((*reinterpret_cast< QObject*(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 10: _t->add_stages((*reinterpret_cast< stage*(*)>(_a[1]))); break;
        case 11: _t->set_publicize_play(); break;
        case 12: _t->output_universe(); break;
        case 13: _t->refresh_stages((*reinterpret_cast< std::vector<laser_device*>(*)>(_a[1]))); break;
        case 14: _t->handle_stage_results((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_picture_tracer_triggered(); break;
        case 16: _t->on_publicize_triggered(); break;
        case 17: _t->open_workspace(); break;
        case 18: _t->on_test_patterns_triggered(); break;
        case 19: _t->on_DMX_ArtNet_Settings_triggered(); break;
        case 20: _t->on_Setup_Administritor_Mode_triggered(); break;
        case 21: _t->on_Setup_User_Mode_triggered(); break;
        case 22: _t->on_Midi_Monitor_triggered(); break;
        case 23: _t->on_Midi_Device_Settings_triggered(); break;
        case 24: _t->on_OSC_Settings_triggered(); break;
        case 25: _t->update_output_scene((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->main_timer_update(); break;
        case 27: _t->line_timer_update(); break;
        case 28: _t->update_show_scene((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->readSinglePage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->readQuickSinglePage((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->on_output_button_clicked(); break;
        case 32: _t->set_artnet_server(); break;
        case 33: _t->setupDMXData((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 34: _t->recieveSection((*reinterpret_cast< CJSection(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 10:
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
        {
            using _t = void (MainWindow1::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MainWindow1::dialog_close)) {
                *result = 1;
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
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 35)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 35;
    }
    return _id;
}

// SIGNAL 0
void MainWindow1::stage_operate(const bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MainWindow1::dialog_close()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
