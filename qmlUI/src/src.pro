TEMPLATE = lib
CONFIG += staticlib
TARGET = qmlUI

QT += core gui qml quick widgets


!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    ../qmls/qmls.qrc \
    ../../resources/icons/resource.qrc
