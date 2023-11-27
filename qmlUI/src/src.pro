TEMPLATE = lib
CONFIG += staticlib
TARGET = qmlUI

QT += core gui qml quick widgets

CONFIG(release, debug|release): LIBS += \
-L$$OUT_PWD/../../engine/src/release/ -lengine
else:CONFIG(debug, debug|release): LIBS += \
-L$$OUT_PWD/../../engine/src/debug/ -lengine

INCLUDEPATH += \
$$PWD/../../engine/src
DEPENDPATH += \
$$PWD/../../engine/src


!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../qmls/qmls.qrc \
    ../../resources/icons/resource.qrc

HEADERS += \
    uicontroller_cueworkspace.h \
    uicontroller_gridcue.h

SOURCES += \
    uicontroller_cueworkspace.cpp \
    uicontroller_gridcue.cpp
