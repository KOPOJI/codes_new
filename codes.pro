TEMPLATE = subdirs
CONFIG += ordered c++11 crypto
SUBDIRS = helpers models views controllers

TRANSLATIONS += ./translations/ru.ts \
    ./translations/en.ts

INCLUDEPATH +=  /usr/include/botan-1.10/
LIBS += -I/usr/include/botan-1.10/ -lbotan-1.10

QMAKE_CLEAN += translations/*.qm
