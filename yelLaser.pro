TEMPLATE = subdirs

QT       += core gui widgets
CONFIG   += ordered

SUBDIRS += \
    engine \
    qmlUI \
    qwdUI \
    main \
    resources



!isEmpty(target.path): INSTALLS += target



