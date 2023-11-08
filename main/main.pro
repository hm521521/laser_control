QT       += core gui

QT += widgets quick qml quickwidgets

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG(release, debug|release): LIBS += \
-L$$OUT_PWD/../qmlUI/src/release/ -lqmlUI \
-L$$OUT_PWD/../qwdUI/src/release/ -lqwdUI \
-L$$OUT_PWD/../engine/src/release/ -lengine
else:CONFIG(debug, debug|release): LIBS += \
-L$$OUT_PWD/../qmlUI/src/debug/ -lqmlUI \
-L$$OUT_PWD/../qwdUI/src/debug/ -lqwdUI \
-L$$OUT_PWD/../engine/src/debug/ -lengine

INCLUDEPATH += \
$$PWD/../qmlUI/src \
$$PWD/../qwdUI/src \
$$PWD/../engine/src
DEPENDPATH += \
$$PWD/../qmlUI/src \
$$PWD/../qwdUI/src \
$$PWD/../engine/src

SOURCES += main.cpp

CONFIG += lrelease
CONFIG += embed_translations

!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../resources/icons/resource.qrc \
    ../qmlUI/qmls/qmls.qrc









