TEMPLATE = subdirs
CONFIG += ordered c++11 crypto
SUBDIRS = helpers models views controllers

TRANSLATIONS += ./translations/ru.ts \
    ./translations/en.ts

QMAKE_CLEAN += translations/*.qm
