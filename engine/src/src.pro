TEMPLATE = lib
CONFIG += staticlib
TARGET = engine

QT       += core gui widgets network quick qml


CONFIG += c++11





!isEmpty(target.path): INSTALLS += target

include(./core/core.pri)
include(./models/models.pri)
include(./control/control.pri)













