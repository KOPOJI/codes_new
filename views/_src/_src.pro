TARGET = view
TEMPLATE = lib
CONFIG += shared c++11 crypto
QT += network xml sql gui
QT -=
DEFINES += TF_DLL
INCLUDEPATH += ../../helpers ../../models /usr/include/botan-1.10/ /usr/include/ImageMagick/
DEPENDPATH  += ../../helpers ../../models
DESTDIR = ../../lib
LIBS += -L../../lib -lhelper -lmodel -I/usr/include/botan-1.10/ -lbotan-1.10 -L/usr/include/ImageMagick/ -lMagick++ -lMagickCore
QMAKE_CLEAN = *.cpp source.list

tmake.target = source.list
tmake.commands = tmake -f ../../config/application.ini -v .. -d . -P
lessThan(QT_MAJOR_VERSION, 5) {
  tmake.depends = qmake
} else {
  tmake.depends = qmake_all
}
QMAKE_EXTRA_TARGETS = tmake
POST_TARGETDEPS = source.list

include(../../appbase.pri)
!exists(source.list) {
  system( $$tmake.commands )
}
include(source.list)

DISTFILES += \
    ../../config/database.ini \
    ../../config/mongodb.ini \
    ../../config/routes.cfg \
    ../../config/validation.ini \
    ../../config/application.ini \
    ../../config/development.ini \
    ../../config/logger.ini \
    ../layouts/application.erb \
    ../partial/layouts/links.erb \
    ../partial/links.erb \
    ../partial/error.erb \
    ../account/form.erb \
    ../partial/form.erb \
    ../partial/_form.erb \
    ../partial/_form_header.erb

HEADERS += \
    ../codes/edit.erb \
    ../codes/entry.erb \
    ../codes/index.erb \
    ../codes/show.erb \
    ../layouts/application.erb \
    ../account/users.erb \
    ../codes/find_by_user.erb \
    ../attachments/index.erb \
    ../attachments/edit.erb \
    ../attachments/entry.erb \
    ../attachments/show.erb \
    ../account/profile.erb \
    ../privatemessages/index.erb \
    ../privatemessages/entry.erb

OTHER_FILES += \
    ../partial/_form_footer.erb \
    ../partial/_form_header.erb \
    ../partial/error.erb \
    ../partial/links.erb \
    ../partial/user_links.erb \
    ../../public/js/bbcodes.js \
    ../../public/js/application.js \
    ../../public/js/jquery-2.1.4.min.js \
    ../../public/js/prettyPhoto.js \
    ../account/form.erb \
    ../account/register.erb \
    ../mailer/mail.erb \
    ../../public/css/styles.css \
    ../../public/css/application.css
