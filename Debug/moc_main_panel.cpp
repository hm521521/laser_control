/****************************************************************************
** Meta object code from reading C++ file 'main_panel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../main_panel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_scene_item_t {
    QByteArrayData data[7];
    char stringdata0[55];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_scene_item_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_scene_item_t qt_meta_stringdata_scene_item = {
    {
QT_MOC_LITERAL(0, 0, 10), // "scene_item"
QT_MOC_LITERAL(1, 11, 11), // "mouse_enter"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "flag"
QT_MOC_LITERAL(4, 29, 8), // "selected"
QT_MOC_LITERAL(5, 38, 10), // "mouse_move"
QT_MOC_LITERAL(6, 49, 5) // "pause"

    },
    "scene_item\0mouse_enter\0\0flag\0selected\0"
    "mouse_move\0pause"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_scene_item[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    0,   37,    2, 0x06 /* Public */,
       5,    0,   38,    2, 0x06 /* Public */,
       6,    0,   39,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Bool,    3,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void scene_item::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<scene_item *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouse_enter((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 1: _t->selected(); break;
        case 2: _t->mouse_move(); break;
        case 3: _t->pause(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (scene_item::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&scene_item::mouse_enter)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (scene_item::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&scene_item::selected)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (scene_item::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&scene_item::mouse_move)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (scene_item::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&scene_item::pause)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject scene_item::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_scene_item.data,
    qt_meta_data_scene_item,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *scene_item::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *scene_item::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_scene_item.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QGraphicsItem"))
        return static_cast< QGraphicsItem*>(this);
    return QObject::qt_metacast(_clname);
}

int scene_item::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void scene_item::mouse_enter(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void scene_item::selected()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void scene_item::mouse_move()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void scene_item::pause()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
struct qt_meta_stringdata_scene_panel_t {
    QByteArrayData data[11];
    char stringdata0[130];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_scene_panel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_scene_panel_t qt_meta_stringdata_scene_panel = {
    {
QT_MOC_LITERAL(0, 0, 11), // "scene_panel"
QT_MOC_LITERAL(1, 12, 11), // "panel_index"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 3), // "idx"
QT_MOC_LITERAL(4, 29, 16), // "show_panel_index"
QT_MOC_LITERAL(5, 46, 17), // "mouse_enter_event"
QT_MOC_LITERAL(6, 64, 4), // "flag"
QT_MOC_LITERAL(7, 69, 14), // "selected_event"
QT_MOC_LITERAL(8, 84, 16), // "on_thread_update"
QT_MOC_LITERAL(9, 101, 16), // "mouse_move_event"
QT_MOC_LITERAL(10, 118, 11) // "pause_event"

    },
    "scene_panel\0panel_index\0\0idx\0"
    "show_panel_index\0mouse_enter_event\0"
    "flag\0selected_event\0on_thread_update\0"
    "mouse_move_event\0pause_event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_scene_panel[] = {

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
       5,    1,   55,    2, 0x0a /* Public */,
       7,    0,   58,    2, 0x0a /* Public */,
       8,    0,   59,    2, 0x0a /* Public */,
       9,    0,   60,    2, 0x0a /* Public */,
      10,    0,   61,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void scene_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<scene_panel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->panel_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->show_panel_index((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->mouse_enter_event((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->selected_event(); break;
        case 4: _t->on_thread_update(); break;
        case 5: _t->mouse_move_event(); break;
        case 6: _t->pause_event(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (scene_panel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&scene_panel::panel_index)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (scene_panel::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&scene_panel::show_panel_index)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject scene_panel::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_scene_panel.data,
    qt_meta_data_scene_panel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *scene_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *scene_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_scene_panel.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int scene_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void scene_panel::panel_index(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void scene_panel::show_panel_index(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
