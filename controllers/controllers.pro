TARGET = controller
TEMPLATE = lib
CONFIG += shared c++11 crypto
QT += network sql xml gui
QT -=
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers ../models /usr/include/botan-1.10/ /usr/include/ImageMagick/
DEPENDPATH  += ../helpers ../models
LIBS += -L../lib -lhelper -lmodel -I/usr/include/botan-1.10/ -lbotan-1.10 -L/usr/include/ImageMagick/

CONFIG(debug, debug|release) {
    QMAKE_CXXFLAGS += -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16
    LIBS += -lMagick++-6.Q16 -lMagickCore-6.Q16
} else {
    LIBS += -lMagick++ -lMagickCore
}


include(../appbase.pri)

HEADERS += applicationcontroller.h \
    includecontroller.h

SOURCES += applicationcontroller.cpp \
    includecontroller.cpp

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
HEADERS += informationmailer.h
SOURCES += informationmailer.cpp
HEADERS += privatemessagescontroller.h
SOURCES += privatemessagescontroller.cpp
