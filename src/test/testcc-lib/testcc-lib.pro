#-------------------------------------------------
#
# Project created by QtCreator 2014-03-28T16:20:10
#
#-------------------------------------------------

QT       += testlib

#QT       -= gui

TARGET = tst_testcalendar
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += \
    tst_testaccount.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../bin/cc-lib/desktop-debug/release/ -lcc-lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../bin/cc-lib/desktop-debug/debug/ -lcc-lib
else:unix: LIBS += -L$$PWD/../../../bin/cc-lib/desktop-debug/ -lcc-lib

INCLUDEPATH += $$PWD/../../cc-lib
DEPENDPATH += $$PWD/../../cc-lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../bin/cc-lib/desktop-debug/release/libcc-lib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../bin/cc-lib/desktop-debug/debug/libcc-lib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../../bin/cc-lib/desktop-debug/release/cc-lib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../../bin/cc-lib/desktop-debug/debug/cc-lib.lib
else:unix: PRE_TARGETDEPS += $$PWD/../../../bin/cc-lib/desktop-debug/libcc-lib.a
