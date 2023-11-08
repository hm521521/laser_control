TEMPLATE = lib
CONFIG += staticlib
TARGET = qwdUI

QT       += core gui quickwidgets

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11




# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


CONFIG += lrelease
CONFIG += embed_translations

!isEmpty(target.path): INSTALLS += target

RESOURCES += ../../resources/icons/resource.qrc

include(./Gride/Gride.pri)











