TARGET = helper
TEMPLATE = lib
CONFIG += shared c++11
QT  -=
QT  += sql gui network xml
DEFINES += TF_DLL
DESTDIR = ../lib
DEPENDPATH +=

INCLUDEPATH += /usr/include /usr/include/botan-1.10/ /usr/include/ImageMagick/
LIBS += -L../lib -I/usr/include/botan-1.10/ -lbotan-1.10 -L/usr/include/ImageMagick/

#CONFIG(debug, debug|release) {
#    QMAKE_CXXFLAGS += -DMAGICKCORE_HDRI_ENABLE=0 -DMAGICKCORE_QUANTUM_DEPTH=16
#    LIBS += -lMagick++-6.Q16 -lMagickCore-6.Q16
#} else {
    LIBS += -lMagick++ -lMagickCore
#}


include(../appbase.pri)

HEADERS += applicationhelper.h
SOURCES += applicationhelper.cpp
