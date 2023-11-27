#ifndef MACROS_H
#define MACROS_H

#include <QObject>

/*! 用于快速生成Q_PROPERTY */
#define BASIC_Q_PROPERTY(TYPE, NAME) \
Q_PROPERTY(TYPE NAME READ NAME WRITE set ## NAME NOTIFY NAME ## Changed ) \
    public: \
    TYPE NAME() { return m_ ## NAME ; } \
    void set ## NAME(TYPE value) { \
        if (m_ ## NAME == value)  return; \
        m_ ## NAME = value; \
        emit NAME ## Changed(); \
} \
    Q_SIGNAL void NAME ## Changed();\
    private: \
    TYPE m_ ## NAME;

/*! 用于快速生成Q_PROPERTY */
#define BASIC_INIT_Q_PROPERTY(TYPE, NAME, VALUE) \
Q_PROPERTY(TYPE NAME READ NAME WRITE set ## NAME NOTIFY NAME ## Changed ) \
    public: \
    TYPE NAME() { return m_ ## NAME ; } \
    void set ## NAME(TYPE value) { \
        if (m_ ## NAME == value)  return; \
        m_ ## NAME = value; \
        emit NAME ## Changed(); \
} \
    Q_SIGNAL void NAME ## Changed();\
    private: \
    TYPE m_ ## NAME = VALUE;

#define CTRL_BASIC_Q_PROPERTY(TYPE, NAME, ATTACH, SETPROPS) \
Q_PROPERTY(TYPE NAME READ NAME WRITE set ## NAME NOTIFY NAME ## Changed ) \
    public: \
    TYPE NAME() { \
        auto ret = ATTACH->property( # NAME).value<TYPE>() ; \
        QObject::connect(ATTACH, SIGNAL( NAME ## Changed()), this, SIGNAL( NAME ## Changed()), Qt::ConnectionType(Qt::AutoConnection|Qt::UniqueConnection)); \
        return ret; \
} \
    void set ## NAME(TYPE value) { \
        if (NAME() == value) return; \
        if( SETPROPS ){ \
            SETPROPS->setProperty(ATTACH, # NAME, value); \
        } else { \
            ATTACH->setProperty( # NAME,value); \
        } \
        emit NAME ## Changed(); \
} \
    Q_SIGNAL void NAME ## Changed();

#endif // MACROS_H
