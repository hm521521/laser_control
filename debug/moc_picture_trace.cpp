/****************************************************************************
** Meta object code from reading C++ file 'picture_trace.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../picture_trace.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'picture_trace.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Picture_trace_t {
    QByteArrayData data[17];
    char stringdata0[219];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Picture_trace_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Picture_trace_t qt_meta_stringdata_Picture_trace = {
    {
QT_MOC_LITERAL(0, 0, 13), // "Picture_trace"
QT_MOC_LITERAL(1, 14, 12), // "btn_img_slot"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 13), // "btn_blur_slot"
QT_MOC_LITERAL(4, 42, 16), // "slider_rank_slot"
QT_MOC_LITERAL(5, 59, 15), // "btn_bigger_slot"
QT_MOC_LITERAL(6, 75, 16), // "btn_smaller_slot"
QT_MOC_LITERAL(7, 92, 12), // "btn_out_slot"
QT_MOC_LITERAL(8, 105, 15), // "img_resize_slot"
QT_MOC_LITERAL(9, 121, 11), // "filter_slot"
QT_MOC_LITERAL(10, 133, 5), // "state"
QT_MOC_LITERAL(11, 139, 8), // "ildafile"
QT_MOC_LITERAL(12, 148, 4), // "file"
QT_MOC_LITERAL(13, 153, 20), // "handleButtonClicked1"
QT_MOC_LITERAL(14, 174, 16), // "QAbstractButton*"
QT_MOC_LITERAL(15, 191, 6), // "button"
QT_MOC_LITERAL(16, 198, 20) // "handleButtonClicked2"

    },
    "Picture_trace\0btn_img_slot\0\0btn_blur_slot\0"
    "slider_rank_slot\0btn_bigger_slot\0"
    "btn_smaller_slot\0btn_out_slot\0"
    "img_resize_slot\0filter_slot\0state\0"
    "ildafile\0file\0handleButtonClicked1\0"
    "QAbstractButton*\0button\0handleButtonClicked2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Picture_trace[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    1,   76,    2, 0x08 /* Private */,
      11,    1,   79,    2, 0x08 /* Private */,
      13,    1,   82,    2, 0x08 /* Private */,
      16,    1,   85,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,   10,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, 0x80000000 | 14,   15,

       0        // eod
};

void Picture_trace::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Picture_trace *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->btn_img_slot(); break;
        case 1: _t->btn_blur_slot(); break;
        case 2: _t->slider_rank_slot(); break;
        case 3: _t->btn_bigger_slot(); break;
        case 4: _t->btn_smaller_slot(); break;
        case 5: _t->btn_out_slot(); break;
        case 6: _t->img_resize_slot(); break;
        case 7: _t->filter_slot((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->ildafile((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 9: _t->handleButtonClicked1((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        case 10: _t->handleButtonClicked2((*reinterpret_cast< QAbstractButton*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 9:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        case 10:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractButton* >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Picture_trace::staticMetaObject = { {
    &SubWindow::staticMetaObject,
    qt_meta_stringdata_Picture_trace.data,
    qt_meta_data_Picture_trace,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Picture_trace::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Picture_trace::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Picture_trace.stringdata0))
        return static_cast<void*>(this);
    return SubWindow::qt_metacast(_clname);
}

int Picture_trace::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SubWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
