/****************************************************************************
** Meta object code from reading C++ file 'laser_setting.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../laser_setting.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'laser_setting.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MyGraphicsView_t {
    QByteArrayData data[6];
    char stringdata0[62];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MyGraphicsView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MyGraphicsView_t qt_meta_stringdata_MyGraphicsView = {
    {
QT_MOC_LITERAL(0, 0, 14), // "MyGraphicsView"
QT_MOC_LITERAL(1, 15, 14), // "mouseMovePoint"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "point"
QT_MOC_LITERAL(4, 37, 12), // "mouseClicked"
QT_MOC_LITERAL(5, 50, 11) // "flagchanged"

    },
    "MyGraphicsView\0mouseMovePoint\0\0point\0"
    "mouseClicked\0flagchanged"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MyGraphicsView[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,
       5,    0,   35,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void,

       0        // eod
};

void MyGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MyGraphicsView *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->mouseMovePoint((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 1: _t->mouseClicked((*reinterpret_cast< QPoint(*)>(_a[1]))); break;
        case 2: _t->flagchanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MyGraphicsView::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::mouseMovePoint)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MyGraphicsView::*)(QPoint );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::mouseClicked)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MyGraphicsView::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MyGraphicsView::flagchanged)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MyGraphicsView::staticMetaObject = { {
    &QGraphicsView::staticMetaObject,
    qt_meta_stringdata_MyGraphicsView.data,
    qt_meta_data_MyGraphicsView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MyGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MyGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MyGraphicsView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int MyGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void MyGraphicsView::mouseMovePoint(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MyGraphicsView::mouseClicked(QPoint _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MyGraphicsView::flagchanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_laser_device_table_t {
    QByteArrayData data[6];
    char stringdata0[96];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_laser_device_table_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_laser_device_table_t qt_meta_stringdata_laser_device_table = {
    {
QT_MOC_LITERAL(0, 0, 18), // "laser_device_table"
QT_MOC_LITERAL(1, 19, 14), // "manager_setted"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 20), // "refresh_laser_device"
QT_MOC_LITERAL(4, 56, 26), // "std::vector<laser_device*>"
QT_MOC_LITERAL(5, 83, 12) // "laser_device"

    },
    "laser_device_table\0manager_setted\0\0"
    "refresh_laser_device\0std::vector<laser_device*>\0"
    "laser_device"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_laser_device_table[] = {

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
       1,    0,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    1,   25,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,

       0        // eod
};

void laser_device_table::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<laser_device_table *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->manager_setted(); break;
        case 1: _t->refresh_laser_device((*reinterpret_cast< std::vector<laser_device*>(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (laser_device_table::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&laser_device_table::manager_setted)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject laser_device_table::staticMetaObject = { {
    &QTableView::staticMetaObject,
    qt_meta_stringdata_laser_device_table.data,
    qt_meta_data_laser_device_table,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *laser_device_table::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *laser_device_table::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_laser_device_table.stringdata0))
        return static_cast<void*>(this);
    return QTableView::qt_metacast(_clname);
}

int laser_device_table::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void laser_device_table::manager_setted()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_laser_setting_data_t {
    QByteArrayData data[1];
    char stringdata0[19];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_laser_setting_data_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_laser_setting_data_t qt_meta_stringdata_laser_setting_data = {
    {
QT_MOC_LITERAL(0, 0, 18) // "laser_setting_data"

    },
    "laser_setting_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_laser_setting_data[] = {

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

void laser_setting_data::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject laser_setting_data::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_laser_setting_data.data,
    qt_meta_data_laser_setting_data,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *laser_setting_data::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *laser_setting_data::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_laser_setting_data.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int laser_setting_data::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_laser_setting_t {
    QByteArrayData data[45];
    char stringdata0[1331];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_laser_setting_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_laser_setting_t qt_meta_stringdata_laser_setting = {
    {
QT_MOC_LITERAL(0, 0, 13), // "laser_setting"
QT_MOC_LITERAL(1, 14, 7), // "refresh"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 27), // "on_xsize_Slider_sliderMoved"
QT_MOC_LITERAL(4, 51, 8), // "position"
QT_MOC_LITERAL(5, 60, 24), // "on_xspinBox_valueChanged"
QT_MOC_LITERAL(6, 85, 4), // "arg1"
QT_MOC_LITERAL(7, 90, 13), // "onflagchanged"
QT_MOC_LITERAL(8, 104, 27), // "on_ysize_Slider_sliderMoved"
QT_MOC_LITERAL(9, 132, 24), // "on_yspinBox_valueChanged"
QT_MOC_LITERAL(10, 157, 31), // "on_xposition_Slider_sliderMoved"
QT_MOC_LITERAL(11, 189, 26), // "on_xp_spinBox_valueChanged"
QT_MOC_LITERAL(12, 216, 31), // "on_yposition_Slider_sliderMoved"
QT_MOC_LITERAL(13, 248, 26), // "on_yp_spinBox_valueChanged"
QT_MOC_LITERAL(14, 275, 21), // "on_comboBox_activated"
QT_MOC_LITERAL(15, 297, 25), // "on_TTL_pushButton_clicked"
QT_MOC_LITERAL(16, 323, 31), // "on_linearRes_pushButton_clicked"
QT_MOC_LITERAL(17, 355, 28), // "on_logRes_pushButton_clicked"
QT_MOC_LITERAL(18, 384, 42), // "on_singleMinU_horizontalSlide..."
QT_MOC_LITERAL(19, 427, 34), // "on_singleMinU_spinBox_valueCh..."
QT_MOC_LITERAL(20, 462, 42), // "on_singleMaxU_horizontalSlide..."
QT_MOC_LITERAL(21, 505, 34), // "on_singleMaxU_spinBox_valueCh..."
QT_MOC_LITERAL(22, 540, 39), // "on_redMinU_horizontalSlider_s..."
QT_MOC_LITERAL(23, 580, 31), // "on_redMinU_spinBox_valueChanged"
QT_MOC_LITERAL(24, 612, 39), // "on_redMaxU_horizontalSlider_s..."
QT_MOC_LITERAL(25, 652, 31), // "on_redMaxU_spinBox_valueChanged"
QT_MOC_LITERAL(26, 684, 41), // "on_greenMinU_horizontalSlider..."
QT_MOC_LITERAL(27, 726, 33), // "on_greenMinU_spinBox_valueCha..."
QT_MOC_LITERAL(28, 760, 41), // "on_greenMaxU_horizontalSlider..."
QT_MOC_LITERAL(29, 802, 33), // "on_greenMaxU_spinBox_valueCha..."
QT_MOC_LITERAL(30, 836, 40), // "on_blueMinU_horizontalSlider_..."
QT_MOC_LITERAL(31, 877, 32), // "on_blueMinU_spinBox_valueChanged"
QT_MOC_LITERAL(32, 910, 40), // "on_blueMaxU_horizontalSlider_..."
QT_MOC_LITERAL(33, 951, 32), // "on_blueMaxU_spinBox_valueChanged"
QT_MOC_LITERAL(34, 984, 38), // "on_sample_horizontalSlider_sl..."
QT_MOC_LITERAL(35, 1023, 30), // "on_sample_spinBox_valueChanged"
QT_MOC_LITERAL(36, 1054, 35), // "on_min_horizontalSlider_slide..."
QT_MOC_LITERAL(37, 1090, 27), // "on_min_spinBox_valueChanged"
QT_MOC_LITERAL(38, 1118, 35), // "on_max_horizontalSlider_slide..."
QT_MOC_LITERAL(39, 1154, 27), // "on_max_spinBox_valueChanged"
QT_MOC_LITERAL(40, 1182, 27), // "on_OpenConfigButton_clicked"
QT_MOC_LITERAL(41, 1210, 30), // "on_actionopensettins_triggered"
QT_MOC_LITERAL(42, 1241, 27), // "on_saveConfigButton_clicked"
QT_MOC_LITERAL(43, 1269, 31), // "on_actionsavesettings_triggered"
QT_MOC_LITERAL(44, 1301, 29) // "on_saveAsConfigButton_clicked"

    },
    "laser_setting\0refresh\0\0"
    "on_xsize_Slider_sliderMoved\0position\0"
    "on_xspinBox_valueChanged\0arg1\0"
    "onflagchanged\0on_ysize_Slider_sliderMoved\0"
    "on_yspinBox_valueChanged\0"
    "on_xposition_Slider_sliderMoved\0"
    "on_xp_spinBox_valueChanged\0"
    "on_yposition_Slider_sliderMoved\0"
    "on_yp_spinBox_valueChanged\0"
    "on_comboBox_activated\0on_TTL_pushButton_clicked\0"
    "on_linearRes_pushButton_clicked\0"
    "on_logRes_pushButton_clicked\0"
    "on_singleMinU_horizontalSlider_sliderMoved\0"
    "on_singleMinU_spinBox_valueChanged\0"
    "on_singleMaxU_horizontalSlider_sliderMoved\0"
    "on_singleMaxU_spinBox_valueChanged\0"
    "on_redMinU_horizontalSlider_sliderMoved\0"
    "on_redMinU_spinBox_valueChanged\0"
    "on_redMaxU_horizontalSlider_sliderMoved\0"
    "on_redMaxU_spinBox_valueChanged\0"
    "on_greenMinU_horizontalSlider_sliderMoved\0"
    "on_greenMinU_spinBox_valueChanged\0"
    "on_greenMaxU_horizontalSlider_sliderMoved\0"
    "on_greenMaxU_spinBox_valueChanged\0"
    "on_blueMinU_horizontalSlider_sliderMoved\0"
    "on_blueMinU_spinBox_valueChanged\0"
    "on_blueMaxU_horizontalSlider_sliderMoved\0"
    "on_blueMaxU_spinBox_valueChanged\0"
    "on_sample_horizontalSlider_sliderMoved\0"
    "on_sample_spinBox_valueChanged\0"
    "on_min_horizontalSlider_sliderMoved\0"
    "on_min_spinBox_valueChanged\0"
    "on_max_horizontalSlider_sliderMoved\0"
    "on_max_spinBox_valueChanged\0"
    "on_OpenConfigButton_clicked\0"
    "on_actionopensettins_triggered\0"
    "on_saveConfigButton_clicked\0"
    "on_actionsavesettings_triggered\0"
    "on_saveAsConfigButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_laser_setting[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      41,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,  219,    2, 0x08 /* Private */,
       3,    1,  220,    2, 0x08 /* Private */,
       5,    1,  223,    2, 0x08 /* Private */,
       7,    0,  226,    2, 0x08 /* Private */,
       8,    1,  227,    2, 0x08 /* Private */,
       9,    1,  230,    2, 0x08 /* Private */,
      10,    1,  233,    2, 0x08 /* Private */,
      11,    1,  236,    2, 0x08 /* Private */,
      12,    1,  239,    2, 0x08 /* Private */,
      13,    1,  242,    2, 0x08 /* Private */,
      14,    1,  245,    2, 0x08 /* Private */,
      15,    0,  248,    2, 0x08 /* Private */,
      16,    0,  249,    2, 0x08 /* Private */,
      17,    0,  250,    2, 0x08 /* Private */,
      18,    1,  251,    2, 0x08 /* Private */,
      19,    1,  254,    2, 0x08 /* Private */,
      20,    1,  257,    2, 0x08 /* Private */,
      21,    1,  260,    2, 0x08 /* Private */,
      22,    1,  263,    2, 0x08 /* Private */,
      23,    1,  266,    2, 0x08 /* Private */,
      24,    1,  269,    2, 0x08 /* Private */,
      25,    1,  272,    2, 0x08 /* Private */,
      26,    1,  275,    2, 0x08 /* Private */,
      27,    1,  278,    2, 0x08 /* Private */,
      28,    1,  281,    2, 0x08 /* Private */,
      29,    1,  284,    2, 0x08 /* Private */,
      30,    1,  287,    2, 0x08 /* Private */,
      31,    1,  290,    2, 0x08 /* Private */,
      32,    1,  293,    2, 0x08 /* Private */,
      33,    1,  296,    2, 0x08 /* Private */,
      34,    1,  299,    2, 0x08 /* Private */,
      35,    1,  302,    2, 0x08 /* Private */,
      36,    1,  305,    2, 0x08 /* Private */,
      37,    1,  308,    2, 0x08 /* Private */,
      38,    1,  311,    2, 0x08 /* Private */,
      39,    1,  314,    2, 0x08 /* Private */,
      40,    0,  317,    2, 0x08 /* Private */,
      41,    0,  318,    2, 0x08 /* Private */,
      42,    0,  319,    2, 0x08 /* Private */,
      43,    0,  320,    2, 0x08 /* Private */,
      44,    0,  321,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void, QMetaType::Int,    4,
    QMetaType::Void, QMetaType::Int,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void laser_setting::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<laser_setting *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->refresh(); break;
        case 1: _t->on_xsize_Slider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->on_xspinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->onflagchanged(); break;
        case 4: _t->on_ysize_Slider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->on_yspinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->on_xposition_Slider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->on_xp_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->on_yposition_Slider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->on_yp_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 10: _t->on_comboBox_activated((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->on_TTL_pushButton_clicked(); break;
        case 12: _t->on_linearRes_pushButton_clicked(); break;
        case 13: _t->on_logRes_pushButton_clicked(); break;
        case 14: _t->on_singleMinU_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_singleMinU_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 16: _t->on_singleMaxU_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 17: _t->on_singleMaxU_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->on_redMinU_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 19: _t->on_redMinU_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 20: _t->on_redMaxU_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 21: _t->on_redMaxU_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 22: _t->on_greenMinU_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 23: _t->on_greenMinU_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 24: _t->on_greenMaxU_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 25: _t->on_greenMaxU_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 26: _t->on_blueMinU_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 27: _t->on_blueMinU_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 28: _t->on_blueMaxU_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 29: _t->on_blueMaxU_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 30: _t->on_sample_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 31: _t->on_sample_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 32: _t->on_min_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 33: _t->on_min_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 34: _t->on_max_horizontalSlider_sliderMoved((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 35: _t->on_max_spinBox_valueChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 36: _t->on_OpenConfigButton_clicked(); break;
        case 37: _t->on_actionopensettins_triggered(); break;
        case 38: _t->on_saveConfigButton_clicked(); break;
        case 39: _t->on_actionsavesettings_triggered(); break;
        case 40: _t->on_saveAsConfigButton_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject laser_setting::staticMetaObject = { {
    &SubWindow::staticMetaObject,
    qt_meta_stringdata_laser_setting.data,
    qt_meta_data_laser_setting,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *laser_setting::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *laser_setting::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_laser_setting.stringdata0))
        return static_cast<void*>(this);
    return SubWindow::qt_metacast(_clname);
}

int laser_setting::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = SubWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 41)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 41;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 41)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 41;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
