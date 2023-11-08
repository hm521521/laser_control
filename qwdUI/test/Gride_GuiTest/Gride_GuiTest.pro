QT       += core gui

QT += widgets quickwidgets

CONFIG += c++11


# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG(release, debug|release): \
LIBS += -L$$OUT_PWD/../../src/release/ -lqwdUI
else:CONFIG(debug, debug|release): \
LIBS += -L$$OUT_PWD/../../src/debug/ -lqwdUI

INCLUDEPATH += $$PWD/../../src
DEPENDPATH += $$PWD/../../src

SOURCES += main.cpp

CONFIG += lrelease
CONFIG += embed_translations
# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../../../resources/icons/resource.qrc









