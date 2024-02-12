/****************************************************************************
** Meta object code from reading C++ file 'projection_zones.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../projection_zones.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'projection_zones.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_zone_names_table_t {
    QByteArrayData data[4];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_zone_names_table_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_zone_names_table_t qt_meta_stringdata_zone_names_table = {
    {
QT_MOC_LITERAL(0, 0, 16), // "zone_names_table"
QT_MOC_LITERAL(1, 17, 7), // "display"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 10) // "m_namelist"

    },
    "zone_names_table\0display\0\0m_namelist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_zone_names_table[] = {

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
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    3,

       0        // eod
};

void zone_names_table::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<zone_names_table *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->display((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject zone_names_table::staticMetaObject = { {
    &QListView::staticMetaObject,
    qt_meta_stringdata_zone_names_table.data,
    qt_meta_data_zone_names_table,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *zone_names_table::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *zone_names_table::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_zone_names_table.stringdata0))
        return static_cast<void*>(this);
    return QListView::qt_metacast(_clname);
}

int zone_names_table::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_zone_id_listView_t {
    QByteArrayData data[4];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_zone_id_listView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_zone_id_listView_t qt_meta_stringdata_zone_id_listView = {
    {
QT_MOC_LITERAL(0, 0, 16), // "zone_id_listView"
QT_MOC_LITERAL(1, 17, 7), // "display"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 8) // "m_idlist"

    },
    "zone_id_listView\0display\0\0m_idlist"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_zone_id_listView[] = {

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
       1,    1,   19,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList,    3,

       0        // eod
};

void zone_id_listView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<zone_id_listView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->display((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject zone_id_listView::staticMetaObject = { {
    &QListView::staticMetaObject,
    qt_meta_stringdata_zone_id_listView.data,
    qt_meta_data_zone_id_listView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *zone_id_listView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *zone_id_listView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_zone_id_listView.stringdata0))
        return static_cast<void*>(this);
    return QListView::qt_metacast(_clname);
}

int zone_id_listView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QListView::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_projection_zones_t {
    QByteArrayData data[21];
    char stringdata0[338];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_projection_zones_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_projection_zones_t qt_meta_stringdata_projection_zones = {
    {
QT_MOC_LITERAL(0, 0, 16), // "projection_zones"
QT_MOC_LITERAL(1, 17, 18), // "display_zone_names"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 10), // "m_namelist"
QT_MOC_LITERAL(4, 48, 16), // "display_id_names"
QT_MOC_LITERAL(5, 65, 7), // "id_list"
QT_MOC_LITERAL(6, 73, 11), // "newZoneName"
QT_MOC_LITERAL(7, 85, 3), // "str"
QT_MOC_LITERAL(8, 89, 9), // "newIdName"
QT_MOC_LITERAL(9, 99, 30), // "on_addZones_pushButton_clicked"
QT_MOC_LITERAL(10, 130, 33), // "on_delete_zone_pushButton_cli..."
QT_MOC_LITERAL(11, 164, 13), // "buttonClicked"
QT_MOC_LITERAL(12, 178, 5), // "index"
QT_MOC_LITERAL(13, 184, 17), // "zone_name_changed"
QT_MOC_LITERAL(14, 202, 11), // "QModelIndex"
QT_MOC_LITERAL(15, 214, 27), // "on_size_radioButton_clicked"
QT_MOC_LITERAL(16, 242, 22), // "radio_groupbox_clicked"
QT_MOC_LITERAL(17, 265, 21), // "math_groupbox_clicked"
QT_MOC_LITERAL(18, 287, 12), // "loadZoneName"
QT_MOC_LITERAL(19, 300, 22), // "delete_projection_zone"
QT_MOC_LITERAL(20, 323, 14) // "delete_zone_id"

    },
    "projection_zones\0display_zone_names\0"
    "\0m_namelist\0display_id_names\0id_list\0"
    "newZoneName\0str\0newIdName\0"
    "on_addZones_pushButton_clicked\0"
    "on_delete_zone_pushButton_clicked\0"
    "buttonClicked\0index\0zone_name_changed\0"
    "QModelIndex\0on_size_radioButton_clicked\0"
    "radio_groupbox_clicked\0math_groupbox_clicked\0"
    "loadZoneName\0delete_projection_zone\0"
    "delete_zone_id"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_projection_zones[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   84,    2, 0x06 /* Public */,
       4,    1,   87,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   90,    2, 0x08 /* Private */,
       8,    1,   93,    2, 0x08 /* Private */,
       9,    0,   96,    2, 0x08 /* Private */,
      10,    0,   97,    2, 0x08 /* Private */,
      11,    1,   98,    2, 0x08 /* Private */,
      13,    1,  101,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    1,  105,    2, 0x08 /* Private */,
      17,    1,  108,    2, 0x08 /* Private */,
      18,    0,  111,    2, 0x0a /* Public */,
      19,    0,  112,    2, 0x0a /* Public */,
      20,    0,  113,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QStringList,    3,
    QMetaType::Void, QMetaType::QStringList,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, 0x80000000 | 14,    2,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void, QMetaType::Int,   12,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void projection_zones::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<projection_zones *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->display_zone_names((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 1: _t->display_id_names((*reinterpret_cast< QStringList(*)>(_a[1]))); break;
        case 2: _t->newZoneName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->newIdName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_addZones_pushButton_clicked(); break;
        case 5: _t->on_delete_zone_pushButton_clicked(); break;
        case 6: _t->buttonClicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->zone_name_changed((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_size_radioButton_clicked(); break;
        case 9: _t->radio_groupbox_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->math_groupbox_clicked((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->loadZoneName(); break;
        case 12: _t->delete_projection_zone(); break;
        case 13: _t->delete_zone_id(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (projection_zones::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&projection_zones::display_zone_names)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (projection_zones::*)(QStringList );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&projection_zones::display_id_names)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject projection_zones::staticMetaObject = { {
    &SubWindow::staticMetaObject,
    qt_meta_stringdata_projection_zones.data,
    qt_meta_data_projection_zones,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *projection_zones::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *projection_zones::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_projection_zones.stringdata0))
        return static_cast<void*>(this);
    return SubWindow::qt_metacast(_clname);
}

int projection_zones::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SubWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void projection_zones::display_zone_names(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void projection_zones::display_id_names(QStringList _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
