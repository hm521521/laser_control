#-------------------------------------------------
#
# Project created by QtCreator 2017-05-18T16:47:51
#
#-------------------------------------------------

QT       += core gui

QT       += network

QT       += multimedia\
            multimediawidgets

QT       +=printsupport


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = TCPServer
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
    add_zones_dialog.cpp \
    cjimage.cpp \
    cjsection.cpp \
    color.cpp \
    configuration.cpp \
    dnd_scene_data_object.cpp \
    ed_laser_output.cpp \
    effect.cpp \
    gdiplus_helper.cpp \
    graphicsrectitem.cpp \
    hardware.cpp\
    laser_device.cpp \
    laser_device_manager.cpp \
    laser_output.cpp \
    laser_setting.cpp \
    main_panel.cpp \
    mainwindow.cpp \
    mainwindow1.cpp \
    mp3_player.cpp \
    output_panel.cpp \
    point.cpp \
    pointattribute.cpp \
    project_panel.cpp \
    projection_zones.cpp \
    qcustomplot.cpp \
    scene_pool.cpp \
    scene_tool_box.cpp \
    show_model.cpp \
    stage.cpp \
    toggle_button.cpp \
    yls_play_event.cpp

HEADERS  += mainwindow.h \
    add_zones_dialog.h \
    cjimage.h \
    cjsection.h \
    color.h \
    common.h \
    configuration.h \
    dnd_scene_data_object.h \
    ed_laser_output.h \
    effect.h \
    gdiplus_helper.h \
    graphicsrectitem.h \
    hardware.h \
    laser_device.h \
    laser_device_manager.h \
    laser_output.h \
    laser_setting.h \
    main_panel.h \
    mainwindow1.h \
    mp3_player.h \
    output_panel.h \
    point.h \
    pointattribute.h \
    project_panel.h \
    projection_zones.h \
    qcustomplot.h \
    scene_pool.h \
    scene_tool_box.h \
    show_model.h \
    stage.h \
    stop_watch.hpp \
    toggle_button.h \
    yls_play_event.h


FORMS    += mainwindow.ui \
    add_zones_dialog.ui \
    hardware.ui \
    laser_setting.ui \
    mainwindow1.ui \
    projection_zones.ui


RESOURCES += \
    res.qrc

CONFIG +=resources_big
msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}
