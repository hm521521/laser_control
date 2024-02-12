/****************************************************************************
** Meta object code from reading C++ file 'test_patterns.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../test_patterns.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'test_patterns.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_my_list_view_t {
    QByteArrayData data[5];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_my_list_view_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_my_list_view_t qt_meta_stringdata_my_list_view = {
    {
QT_MOC_LITERAL(0, 0, 12), // "my_list_view"
QT_MOC_LITERAL(1, 13, 11), // "sendSection"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "CJSection"
QT_MOC_LITERAL(4, 36, 7) // "section"

    },
    "my_list_view\0sendSection\0\0CJSection\0"
    "section"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_my_list_view[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

       0        // eod
};

void my_list_view::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<my_list_view *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSection((*reinterpret_cast< CJSection(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (my_list_view::*)(CJSection );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&my_list_view::sendSection)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject my_list_view::staticMetaObject = { {
    &QListView::staticMetaObject,
    qt_meta_stringdata_my_list_view.data,
    qt_meta_data_my_list_view,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *my_list_view::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *my_list_view::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_my_list_view.stringdata0))
        return static_cast<void*>(this);
    return QListView::qt_metacast(_clname);
}

int my_list_view::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void my_list_view::sendSection(CJSection _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_test_patterns_t {
    QByteArrayData data[11];
    char stringdata0[141];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_test_patterns_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_test_patterns_t qt_meta_stringdata_test_patterns = {
    {
QT_MOC_LITERAL(0, 0, 13), // "test_patterns"
QT_MOC_LITERAL(1, 14, 11), // "sendSection"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 9), // "CJSection"
QT_MOC_LITERAL(4, 37, 7), // "section"
QT_MOC_LITERAL(5, 45, 16), // "on_enable_output"
QT_MOC_LITERAL(6, 62, 14), // "show_test_view"
QT_MOC_LITERAL(7, 77, 11), // "QModelIndex"
QT_MOC_LITERAL(8, 89, 7), // "current"
QT_MOC_LITERAL(9, 97, 14), // "receiveSection"
QT_MOC_LITERAL(10, 112, 28) // "on_output_pushButton_clicked"

    },
    "test_patterns\0sendSection\0\0CJSection\0"
    "section\0on_enable_output\0show_test_view\0"
    "QModelIndex\0current\0receiveSection\0"
    "on_output_pushButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_test_patterns[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   43,    2, 0x0a /* Public */,
       9,    1,   46,    2, 0x0a /* Public */,
      10,    0,   49,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,

       0        // eod
};

void test_patterns::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<test_patterns *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendSection((*reinterpret_cast< CJSection(*)>(_a[1]))); break;
        case 1: _t->on_enable_output(); break;
        case 2: _t->show_test_view((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 3: _t->receiveSection((*reinterpret_cast< CJSection(*)>(_a[1]))); break;
        case 4: _t->on_output_pushButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (test_patterns::*)(CJSection );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&test_patterns::sendSection)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (test_patterns::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&test_patterns::on_enable_output)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject test_patterns::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_test_patterns.data,
    qt_meta_data_test_patterns,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *test_patterns::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *test_patterns::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_test_patterns.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int test_patterns::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
void test_patterns::sendSection(CJSection _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void test_patterns::on_enable_output()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
