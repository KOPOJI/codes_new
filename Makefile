#############################################################################
# Makefile for building: codes
# Generated by qmake (3.0) (Qt 5.0.2) on: ?? ????. 4 22:13:27 2016
# Project:  codes.pro
# Template: subdirs
# Command: /usr/lib/i386-linux-gnu/qt5/bin/qmake CONFIG+=release -o Makefile codes.pro
#############################################################################

MAKEFILE      = Makefile

first: make_first
QMAKE         = /usr/lib/i386-linux-gnu/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = $(COPY_DIR)
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
SUBTARGETS    =  \
		sub-helpers \
		sub-models \
		sub-views \
		sub-controllers


sub-helpers-qmake_all:  FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile
	cd helpers/ && $(MAKE) -f Makefile qmake_all
sub-helpers: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile
sub-helpers-make_first-ordered: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile 
sub-helpers-make_first: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile 
sub-helpers-all-ordered: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile all
sub-helpers-all: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile all
sub-helpers-clean-ordered: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile clean
sub-helpers-clean: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile clean
sub-helpers-distclean-ordered: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile distclean
sub-helpers-distclean: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile distclean
sub-helpers-install_subtargets-ordered: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile install
sub-helpers-install_subtargets: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile install
sub-helpers-uninstall_subtargets-ordered: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-helpers-uninstall_subtargets: FORCE
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-models-qmake_all: sub-helpers-qmake_all FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile
	cd models/ && $(MAKE) -f Makefile qmake_all
sub-models: FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile
sub-models-make_first-ordered: sub-helpers-make_first-ordered  FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile 
sub-models-make_first: FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile 
sub-models-all-ordered: sub-helpers-all-ordered  FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile all
sub-models-all: FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile all
sub-models-clean-ordered: sub-helpers-clean-ordered  FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile clean
sub-models-clean: FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile clean
sub-models-distclean-ordered: sub-helpers-distclean-ordered  FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile distclean
sub-models-distclean: FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile distclean
sub-models-install_subtargets-ordered: sub-helpers-install_subtargets-ordered  FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile install
sub-models-install_subtargets: FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile install
sub-models-uninstall_subtargets-ordered: sub-helpers-uninstall_subtargets-ordered  FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-models-uninstall_subtargets: FORCE
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-views-qmake_all: sub-models-qmake_all FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile
	cd views/ && $(MAKE) -f Makefile qmake_all
sub-views: FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile
sub-views-make_first-ordered: sub-models-make_first-ordered  FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile 
sub-views-make_first: FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile 
sub-views-all-ordered: sub-models-all-ordered  FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile all
sub-views-all: FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile all
sub-views-clean-ordered: sub-models-clean-ordered  FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile clean
sub-views-clean: FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile clean
sub-views-distclean-ordered: sub-models-distclean-ordered  FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile distclean
sub-views-distclean: FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile distclean
sub-views-install_subtargets-ordered: sub-models-install_subtargets-ordered  FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile install
sub-views-install_subtargets: FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile install
sub-views-uninstall_subtargets-ordered: sub-models-uninstall_subtargets-ordered  FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-views-uninstall_subtargets: FORCE
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-controllers-qmake_all: sub-views-qmake_all FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile
	cd controllers/ && $(MAKE) -f Makefile qmake_all
sub-controllers: FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile
sub-controllers-make_first-ordered: sub-views-make_first-ordered  FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile 
sub-controllers-make_first: FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile 
sub-controllers-all-ordered: sub-views-all-ordered  FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile all
sub-controllers-all: FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile all
sub-controllers-clean-ordered: sub-views-clean-ordered  FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile clean
sub-controllers-clean: FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile clean
sub-controllers-distclean-ordered: sub-views-distclean-ordered  FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile distclean
sub-controllers-distclean: FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile distclean
sub-controllers-install_subtargets-ordered: sub-views-install_subtargets-ordered  FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile install
sub-controllers-install_subtargets: FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile install
sub-controllers-uninstall_subtargets-ordered: sub-views-uninstall_subtargets-ordered  FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile uninstall
sub-controllers-uninstall_subtargets: FORCE
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile uninstall

Makefile: codes.pro /usr/share/qt5/mkspecs/linux-g++/qmake.conf /usr/share/qt5/mkspecs/features/spec_pre.prf \
		/usr/share/qt5/mkspecs/common/shell-unix.conf \
		/usr/share/qt5/mkspecs/common/unix.conf \
		/usr/share/qt5/mkspecs/common/linux.conf \
		/usr/share/qt5/mkspecs/common/gcc-base.conf \
		/usr/share/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/share/qt5/mkspecs/common/g++-base.conf \
		/usr/share/qt5/mkspecs/common/g++-unix.conf \
		/usr/share/qt5/mkspecs/qconfig.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_bootstrap.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_location.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_platformsupport.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_qmldevtools.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_quickparticles.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_sensors.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_webkit.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_webkitwidgets.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/share/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/share/qt5/mkspecs/features/qt_functions.prf \
		/usr/share/qt5/mkspecs/features/qt_config.prf \
		/usr/share/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/share/qt5/mkspecs/features/spec_post.prf \
		/usr/share/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/share/qt5/mkspecs/features/default_pre.prf \
		/usr/share/qt5/mkspecs/features/unix/default_pre.prf \
		/usr/share/qt5/mkspecs/features/resolve_config.prf \
		/usr/share/qt5/mkspecs/features/default_post.prf \
		/usr/share/qt5/mkspecs/features/c++11.prf \
		/usr/share/qt5/mkspecs/features/unix/gdb_dwarf_index.prf \
		/usr/share/qt5/mkspecs/features/warn_on.prf \
		/usr/share/qt5/mkspecs/features/wayland-scanner.prf \
		/usr/share/qt5/mkspecs/features/testcase_targets.prf \
		/usr/share/qt5/mkspecs/features/exceptions.prf \
		/usr/share/qt5/mkspecs/features/yacc.prf \
		/usr/share/qt5/mkspecs/features/lex.prf \
		codes.pro
	$(QMAKE) CONFIG+=release -o Makefile codes.pro
/usr/share/qt5/mkspecs/features/spec_pre.prf:
/usr/share/qt5/mkspecs/common/shell-unix.conf:
/usr/share/qt5/mkspecs/common/unix.conf:
/usr/share/qt5/mkspecs/common/linux.conf:
/usr/share/qt5/mkspecs/common/gcc-base.conf:
/usr/share/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/share/qt5/mkspecs/common/g++-base.conf:
/usr/share/qt5/mkspecs/common/g++-unix.conf:
/usr/share/qt5/mkspecs/qconfig.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_bootstrap.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_location.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_platformsupport.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_qmldevtools.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_quickparticles.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_sensors.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_webkit.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_webkitwidgets.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/share/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/share/qt5/mkspecs/features/qt_functions.prf:
/usr/share/qt5/mkspecs/features/qt_config.prf:
/usr/share/qt5/mkspecs/linux-g++/qmake.conf:
/usr/share/qt5/mkspecs/features/spec_post.prf:
/usr/share/qt5/mkspecs/features/exclusive_builds.prf:
/usr/share/qt5/mkspecs/features/default_pre.prf:
/usr/share/qt5/mkspecs/features/unix/default_pre.prf:
/usr/share/qt5/mkspecs/features/resolve_config.prf:
/usr/share/qt5/mkspecs/features/default_post.prf:
/usr/share/qt5/mkspecs/features/c++11.prf:
/usr/share/qt5/mkspecs/features/unix/gdb_dwarf_index.prf:
/usr/share/qt5/mkspecs/features/warn_on.prf:
/usr/share/qt5/mkspecs/features/wayland-scanner.prf:
/usr/share/qt5/mkspecs/features/testcase_targets.prf:
/usr/share/qt5/mkspecs/features/exceptions.prf:
/usr/share/qt5/mkspecs/features/yacc.prf:
/usr/share/qt5/mkspecs/features/lex.prf:
codes.pro:
qmake: FORCE
	@$(QMAKE) CONFIG+=release -o Makefile codes.pro

qmake_all: sub-helpers-qmake_all sub-models-qmake_all sub-views-qmake_all sub-controllers-qmake_all FORCE

make_first: sub-helpers-make_first-ordered sub-models-make_first-ordered sub-views-make_first-ordered sub-controllers-make_first-ordered FORCE
all: sub-helpers-all-ordered sub-models-all-ordered sub-views-all-ordered sub-controllers-all-ordered FORCE
clean: sub-helpers-clean-ordered sub-models-clean-ordered sub-views-clean-ordered sub-controllers-clean-ordered FORCE
	-$(DEL_FILE) translations/*.qm
distclean: sub-helpers-distclean-ordered sub-models-distclean-ordered sub-views-distclean-ordered sub-controllers-distclean-ordered FORCE
	-$(DEL_FILE) Makefile
install_subtargets: sub-helpers-install_subtargets-ordered sub-models-install_subtargets-ordered sub-views-install_subtargets-ordered sub-controllers-install_subtargets-ordered FORCE
uninstall_subtargets: sub-helpers-uninstall_subtargets-ordered sub-models-uninstall_subtargets-ordered sub-views-uninstall_subtargets-ordered sub-controllers-uninstall_subtargets-ordered FORCE

sub-helpers-check_ordered:
	@test -d helpers/ || mkdir -p helpers/
	cd helpers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/helpers/helpers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile check
sub-models-check_ordered: sub-helpers-check_ordered 
	@test -d models/ || mkdir -p models/
	cd models/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/models/models.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile check
sub-views-check_ordered: sub-models-check_ordered 
	@test -d views/ || mkdir -p views/
	cd views/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/views/views.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile check
sub-controllers-check_ordered: sub-views-check_ordered 
	@test -d controllers/ || mkdir -p controllers/
	cd controllers/ && ( test -e Makefile || $(QMAKE) /home/web/codes_new/controllers/controllers.pro CONFIG+=release -o Makefile ) && $(MAKE) -f Makefile check
check: sub-helpers-check_ordered sub-models-check_ordered sub-views-check_ordered sub-controllers-check_ordered
install: install_subtargets  FORCE

uninstall:  uninstall_subtargets FORCE

FORCE:

