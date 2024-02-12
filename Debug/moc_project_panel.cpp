/****************************************************************************
** Meta object code from reading C++ file 'project_panel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../project_panel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'project_panel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_media_info_t {
    QByteArrayData data[12];
    char stringdata0[149];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_media_info_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_media_info_t qt_meta_stringdata_media_info = {
    {
QT_MOC_LITERAL(0, 0, 10), // "media_info"
QT_MOC_LITERAL(1, 11, 14), // "onStateChanged"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 19), // "QMediaPlayer::State"
QT_MOC_LITERAL(4, 47, 17), // "onPositionChanged"
QT_MOC_LITERAL(5, 65, 17), // "onDurationChanged"
QT_MOC_LITERAL(6, 83, 17), // "onPlaylistChanged"
QT_MOC_LITERAL(7, 101, 12), // "getPeakValue"
QT_MOC_LITERAL(8, 114, 12), // "QAudioFormat"
QT_MOC_LITERAL(9, 127, 6), // "format"
QT_MOC_LITERAL(10, 134, 9), // "setBuffer"
QT_MOC_LITERAL(11, 144, 4) // "plot"

    },
    "media_info\0onStateChanged\0\0"
    "QMediaPlayer::State\0onPositionChanged\0"
    "onDurationChanged\0onPlaylistChanged\0"
    "getPeakValue\0QAudioFormat\0format\0"
    "setBuffer\0plot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_media_info[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x0a /* Public */,
       4,    1,   52,    2, 0x0a /* Public */,
       5,    1,   55,    2, 0x0a /* Public */,
       6,    1,   58,    2, 0x0a /* Public */,
       7,    1,   61,    2, 0x08 /* Private */,
      10,    0,   64,    2, 0x08 /* Private */,
      11,    0,   65,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::LongLong,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::QReal, 0x80000000 | 8,    9,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void media_info::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<media_info *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onStateChanged((*reinterpret_cast< QMediaPlayer::State(*)>(_a[1]))); break;
        case 1: _t->onPositionChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 2: _t->onDurationChanged((*reinterpret_cast< qint64(*)>(_a[1]))); break;
        case 3: _t->onPlaylistChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: { qreal _r = _t->getPeakValue((*reinterpret_cast< const QAudioFormat(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< qreal*>(_a[0]) = std::move(_r); }  break;
        case 5: _t->setBuffer(); break;
        case 6: _t->plot(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QMediaPlayer::State >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAudioFormat >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject media_info::staticMetaObject = { {
    &QObject::staticMetaObject,
    qt_meta_stringdata_media_info.data,
    qt_meta_data_media_info,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *media_info::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *media_info::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_media_info.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int media_info::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
struct qt_meta_stringdata_common_track_t {
    QByteArrayData data[4];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_common_track_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_common_track_t qt_meta_stringdata_common_track = {
    {
QT_MOC_LITERAL(0, 0, 12), // "common_track"
QT_MOC_LITERAL(1, 13, 14), // "setCurrentTime"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 2) // "ct"

    },
    "common_track\0setCurrentTime\0\0ct"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_common_track[] = {

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
    QMetaType::Void, QMetaType::Float,    3,

       0        // eod
};

void common_track::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<common_track *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setCurrentTime((*reinterpret_cast< float(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (common_track::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&common_track::setCurrentTime)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject common_track::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_common_track.data,
    qt_meta_data_common_track,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *common_track::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *common_track::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_common_track.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int common_track::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void common_track::setCurrentTime(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_scene_track_t {
    QByteArrayData data[7];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_scene_track_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_scene_track_t qt_meta_stringdata_scene_track = {
    {
QT_MOC_LITERAL(0, 0, 11), // "scene_track"
QT_MOC_LITERAL(1, 12, 9), // "set_Width"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "width"
QT_MOC_LITERAL(4, 29, 10), // "deleteInfo"
QT_MOC_LITERAL(5, 40, 5), // "index"
QT_MOC_LITERAL(6, 46, 11) // "delete_info"

    },
    "scene_track\0set_Width\0\0width\0deleteInfo\0"
    "index\0delete_info"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_scene_track[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void scene_track::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<scene_track *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_Width((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->deleteInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->delete_info((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (scene_track::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&scene_track::set_Width)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (scene_track::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&scene_track::deleteInfo)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject scene_track::staticMetaObject = { {
    &common_track::staticMetaObject,
    qt_meta_stringdata_scene_track.data,
    qt_meta_data_scene_track,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *scene_track::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *scene_track::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_scene_track.stringdata0))
        return static_cast<void*>(this);
    return common_track::qt_metacast(_clname);
}

int scene_track::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = common_track::qt_metacall(_c, _id, _a);
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
void scene_track::set_Width(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void scene_track::deleteInfo(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_media_track_t {
    QByteArrayData data[7];
    char stringdata0[58];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_media_track_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_media_track_t qt_meta_stringdata_media_track = {
    {
QT_MOC_LITERAL(0, 0, 11), // "media_track"
QT_MOC_LITERAL(1, 12, 9), // "set_Width"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 5), // "width"
QT_MOC_LITERAL(4, 29, 10), // "deleteInfo"
QT_MOC_LITERAL(5, 40, 5), // "index"
QT_MOC_LITERAL(6, 46, 11) // "delete_info"

    },
    "media_track\0set_Width\0\0width\0deleteInfo\0"
    "index\0delete_info"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_media_track[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,
       4,    1,   32,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   35,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void media_track::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<media_track *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_Width((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->deleteInfo((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->delete_info((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (media_track::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&media_track::set_Width)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (media_track::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&media_track::deleteInfo)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject media_track::staticMetaObject = { {
    &common_track::staticMetaObject,
    qt_meta_stringdata_media_track.data,
    qt_meta_data_media_track,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *media_track::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *media_track::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_media_track.stringdata0))
        return static_cast<void*>(this);
    return common_track::qt_metacast(_clname);
}

int media_track::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = common_track::qt_metacall(_c, _id, _a);
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
void media_track::set_Width(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void media_track::deleteInfo(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
struct qt_meta_stringdata_track_list_widget_t {
    QByteArrayData data[16];
    char stringdata0[153];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_track_list_widget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_track_list_widget_t qt_meta_stringdata_track_list_widget = {
    {
QT_MOC_LITERAL(0, 0, 17), // "track_list_widget"
QT_MOC_LITERAL(1, 18, 9), // "set_Width"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 5), // "width"
QT_MOC_LITERAL(4, 35, 10), // "set_Height"
QT_MOC_LITERAL(5, 46, 6), // "height"
QT_MOC_LITERAL(6, 53, 14), // "setCurrentTime"
QT_MOC_LITERAL(7, 68, 2), // "ct"
QT_MOC_LITERAL(8, 71, 8), // "addTrack"
QT_MOC_LITERAL(9, 80, 4), // "type"
QT_MOC_LITERAL(10, 85, 10), // "resetWidth"
QT_MOC_LITERAL(11, 96, 10), // "setCurrent"
QT_MOC_LITERAL(12, 107, 11), // "infoDeleted"
QT_MOC_LITERAL(13, 119, 5), // "index"
QT_MOC_LITERAL(14, 125, 13), // "addMediaTrack"
QT_MOC_LITERAL(15, 139, 13) // "addSceneTrack"

    },
    "track_list_widget\0set_Width\0\0width\0"
    "set_Height\0height\0setCurrentTime\0ct\0"
    "addTrack\0type\0resetWidth\0setCurrent\0"
    "infoDeleted\0index\0addMediaTrack\0"
    "addSceneTrack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_track_list_widget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       4,    1,   62,    2, 0x06 /* Public */,
       6,    1,   65,    2, 0x06 /* Public */,
       8,    1,   68,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   71,    2, 0x0a /* Public */,
      11,    1,   74,    2, 0x0a /* Public */,
      12,    1,   77,    2, 0x0a /* Public */,
      14,    1,   80,    2, 0x0a /* Public */,
      15,    1,   83,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Bool,    9,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Float,    2,
    QMetaType::Void, QMetaType::Int,   13,
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void track_list_widget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<track_list_widget *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_Width((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->set_Height((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setCurrentTime((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->addTrack((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->resetWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->setCurrent((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 6: _t->infoDeleted((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->addMediaTrack((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->addSceneTrack((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (track_list_widget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&track_list_widget::set_Width)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (track_list_widget::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&track_list_widget::set_Height)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (track_list_widget::*)(float );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&track_list_widget::setCurrentTime)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (track_list_widget::*)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&track_list_widget::addTrack)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject track_list_widget::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_track_list_widget.data,
    qt_meta_data_track_list_widget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *track_list_widget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *track_list_widget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_track_list_widget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int track_list_widget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void track_list_widget::set_Width(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void track_list_widget::set_Height(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void track_list_widget::setCurrentTime(float _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void track_list_widget::addTrack(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_tick_panel_t {
    QByteArrayData data[4];
    char stringdata0[30];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_tick_panel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_tick_panel_t qt_meta_stringdata_tick_panel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "tick_panel"
QT_MOC_LITERAL(1, 11, 11), // "resizeWidth"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 5) // "width"

    },
    "tick_panel\0resizeWidth\0\0width"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_tick_panel[] = {

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
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void tick_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<tick_panel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->resizeWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject tick_panel::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_tick_panel.data,
    qt_meta_data_tick_panel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *tick_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *tick_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_tick_panel.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int tick_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_track_project_panel_t {
    QByteArrayData data[9];
    char stringdata0[84];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_track_project_panel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_track_project_panel_t qt_meta_stringdata_track_project_panel = {
    {
QT_MOC_LITERAL(0, 0, 19), // "track_project_panel"
QT_MOC_LITERAL(1, 20, 9), // "set_Width"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 5), // "width"
QT_MOC_LITERAL(4, 37, 10), // "set_Height"
QT_MOC_LITERAL(5, 48, 6), // "height"
QT_MOC_LITERAL(6, 55, 10), // "setCurrent"
QT_MOC_LITERAL(7, 66, 2), // "ct"
QT_MOC_LITERAL(8, 69, 14) // "acceptAddTrack"

    },
    "track_project_panel\0set_Width\0\0width\0"
    "set_Height\0height\0setCurrent\0ct\0"
    "acceptAddTrack"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_track_project_panel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       4,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    5,
    QMetaType::Void, QMetaType::Float,    7,
    QMetaType::Void, QMetaType::Bool,    2,

       0        // eod
};

void track_project_panel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<track_project_panel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->set_Width((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->set_Height((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->setCurrent((*reinterpret_cast< float(*)>(_a[1]))); break;
        case 3: _t->acceptAddTrack((*reinterpret_cast< bool(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject track_project_panel::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_track_project_panel.data,
    qt_meta_data_track_project_panel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *track_project_panel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *track_project_panel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_track_project_panel.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int track_project_panel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
struct qt_meta_stringdata_list_tick_t {
    QByteArrayData data[1];
    char stringdata0[10];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_list_tick_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_list_tick_t qt_meta_stringdata_list_tick = {
    {
QT_MOC_LITERAL(0, 0, 9) // "list_tick"

    },
    "list_tick"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_list_tick[] = {

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

void list_tick::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    Q_UNUSED(_o);
    Q_UNUSED(_id);
    Q_UNUSED(_c);
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject list_tick::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_list_tick.data,
    qt_meta_data_list_tick,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *list_tick::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *list_tick::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_list_tick.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int list_tick::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
