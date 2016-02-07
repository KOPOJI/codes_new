TARGET = helper
TEMPLATE = lib
CONFIG += shared c++11
QT  -=
QT  += sql gui network xml
DEFINES += TF_DLL
DESTDIR = ../lib
DEPENDPATH +=

INCLUDEPATH += /usr/include /usr/include/botan-1.10/ /usr/include/ImageMagick/
LIBS += -L../lib -I/usr/include/botan-1.10/ -lbotan-1.10 -L/usr/include/ImageMagick/ -lMagick++ -lMagickCore

include(../appbase.pri)

HEADERS += applicationhelper.h
SOURCES += applicationhelper.cpp
