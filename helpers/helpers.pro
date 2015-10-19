TARGET = helper
TEMPLATE = lib
CONFIG += shared c++11
QT  -=
QT  += sql gui
DEFINES += TF_DLL
DESTDIR = ../lib
DEPENDPATH +=

INCLUDEPATH += /usr/include /usr/include/ImageMagick/
LIBS += -L../lib -L/usr/include/ImageMagick/ -lMagick++ -lMagickCore

include(../appbase.pri)

HEADERS += applicationhelper.h
SOURCES += applicationhelper.cpp
