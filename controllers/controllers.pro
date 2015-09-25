TARGET = controller
TEMPLATE = lib
CONFIG += shared c++11 crypto
QT += network sql xml gui
QT -=
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers ../models /usr/include/botan-1.10/
DEPENDPATH  += ../helpers ../models
LIBS += -L../lib -lhelper -lmodel -I/usr/include/botan-1.10/ -lbotan-1.10
include(../appbase.pri)

HEADERS += applicationcontroller.h

SOURCES += applicationcontroller.cpp

HEADERS += codescontroller.h
SOURCES += codescontroller.cpp
HEADERS += accountcontroller.h
SOURCES += accountcontroller.cpp

OTHER_FILES += \
    ../config/application.ini \
    ../config/database.ini \
    ../config/development.ini \
    ../config/logger.ini \
    ../config/mongodb.ini \
    ../config/redis.ini \
    ../config/validation.ini \
    ../config/routes.cfg \
    ../translations/ru.ts \
    ../translations/en.ts
HEADERS += attachmentscontroller.h
SOURCES += attachmentscontroller.cpp
