TARGET = model
TEMPLATE = lib
CONFIG += shared c++11 crypto
QT += sql gui
QT -=
DEFINES += TF_DLL
DESTDIR = ../lib
INCLUDEPATH += ../helpers sqlobjects mongoobjects /usr/include/botan-1.10/ /usr/include/ImageMagick/
DEPENDPATH  += ../helpers sqlobjects mongoobjects
LIBS += -L../lib -lhelper -I/usr/include/botan-1.10/ -lbotan-1.10 -L/usr/include/ImageMagick/ -lMagick++ -lMagickCore

include(../appbase.pri)

HEADERS += sqlobjects/codesobject.h
HEADERS += codes.h
SOURCES += codes.cpp
HEADERS += sqlobjects/usersobject.h
HEADERS += users.h
SOURCES += users.cpp
HEADERS += sqlobjects/attachmentsobject.h
HEADERS += attachments.h
SOURCES += attachments.cpp
HEADERS += sqlobjects/profilesobject.h
HEADERS += profiles.h
SOURCES += profiles.cpp
HEADERS += sqlobjects/privatemessagesobject.h
HEADERS += privatemessages.h
SOURCES += privatemessages.cpp
