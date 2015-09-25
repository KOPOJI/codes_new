TARGET = helper
TEMPLATE = lib
CONFIG += shared c++11
QT  -=
QT  += sql gui
DEFINES += TF_DLL
DESTDIR = ../lib
DEPENDPATH +=

include(../appbase.pri)

HEADERS += applicationhelper.h
SOURCES += applicationhelper.cpp
