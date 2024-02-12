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
    add_id_dialog.cpp \
    add_zones_dialog.cpp \
    cjimage.cpp \
    cjpoint.cpp \
    cjsection.cpp \
    clockedit.cpp \
    color.cpp \
    configuration.cpp \
    delete_projection_zone_dialog.cpp \
    delete_zone_id_dialog.cpp \
    dmx_setup.cpp \
    dnd_scene_data_object.cpp \
    ed_laser_output.cpp \
    effect.cpp \
    gdiplus_helper.cpp \
    graphicsrectitem.cpp \
    hardware.cpp\
    laser_device_manager.cpp \
    laser_output.cpp \
    laser_setting.cpp \
    main_panel.cpp \
    mainwindow1.cpp \
    midi_device_settings.cpp \
    midi_moniter.cpp \
    mp3_player.cpp \
    mygraphicsview.cpp \
    osc_settings.cpp \
    output_panel.cpp \
    output_universe_dialog.cpp \
    picture_trace.cpp \
    pointattribute.cpp \
    project_panel.cpp \
    projection_zones.cpp \
    publicize.cpp \
    qcustomplot.cpp \
    scene_pool.cpp \
    scene_tool_box.cpp \
    setup_administrator_mode.cpp \
    setup_user_mode.cpp \
    show_model.cpp \
    stage.cpp \
    test_patterns.cpp \
    toggle_button.cpp \
    yls_play_event.cpp\
    dmax_out_artnet_dialog.cpp \
    dmax_output_dialog.cpp\
    artnetplugin.cpp\
    artnetpacketizer.cpp\
    artnetcontroller.cpp\
    configureartnet.cpp

HEADERS  += \
    add_id_dialog.h \
    add_zones_dialog.h \
    cjimage.h \
    cjpoint.h \
    cjsection.h \
    clockedit.h \
    color.h \
    common.h \
    configuration.h \
    delete_projection_zone_dialog.h \
    delete_zone_id_dialog.h \
    dmx_setup.h \
    dnd_scene_data_object.h \
    ed_laser_output.h \
    effect.h \
    gdiplus_helper.h \
    graphicsrectitem.h \
    hardware.h \
    ildafile.h \
    laser_device_manager.h \
    laser_output.h \
    laser_setting.h \
    main_panel.h \
    mainwindow1.h \
    midi_device_settings.h \
    midi_moniter.h \
    mp3_player.h \
    mygraphicsview.h \
    osc_settings.h \
    output_panel.h \
    output_universe_dialog.h \
    picture_trace.h \
    pointattribute.h \
    project_panel.h \
    projection_zones.h \
    publicize.h \
    qcustomplot.h \
    scene_pool.h \
    scene_tool_box.h \
    setup_administrator_mode.h \
    setup_user_mode.h \
    show_model.h \
    stage.h \
    stop_watch.hpp \
    test_patterns.h \
    toggle_button.h \
    yls_play_event.h\
    dmax_out_artnet_dialog.h \
    dmax_output_dialog.h\
    artnetplugin.h\
    artnetpacketizer.h\
    artnetcontroller.h\
    configureartnet.h

FORMS    += \
    add_id_dialog.ui \
    add_zones_dialog.ui \
    clockedit.ui \
    delete_projection_zone_dialog.ui \
    delete_zone_id_dialog.ui \
    dmx_setup.ui \
    hardware.ui \
    laser_setting.ui \
    mainwindow1.ui \
    midi_device_settings.ui \
    midi_moniter.ui \
    osc_settings.ui \
    output_universe_dialog.ui \
    picture_trace.ui \
    projection_zones.ui \
    publicize.ui \
    setup_administrator_mode.ui \
    setup_user_mode.ui \
    test_patterns.ui\
    dmax_out_artnet_dialog.ui \
    dmax_output_dialog.ui


RESOURCES += \
    res.qrc

CONFIG +=resources_big
msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

#win32:CONFIG(release, debug|release): LIBS += -LD:/Program_Files/opencv3.4.1/opencv/build/x64/vc15/lib/ -lopencv_world341
#else:win32:CONFIG(debug, debug|release): LIBS += -LD:/Program_Files/opencv3.4.1/opencv/build/x64/vc15/lib/ -lopencv_world341d

#INCLUDEPATH += D:/Program_Files/opencv3.4.1/opencv/build/include
#DEPENDPATH += D:/Program_Files/opencv3.4.1/opencv/build/include


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../opencv/build/x64/vc15/lib/ -lopencv_world341
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../opencv/build/x64/vc15/lib/ -lopencv_world341d

INCLUDEPATH += $$PWD/../../opencv/build/include
DEPENDPATH += $$PWD/../../opencv/build/include
