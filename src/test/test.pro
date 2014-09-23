#-------------------------------------------------
#
# Project created by QtCreator 2014-08-30T00:23:37
#
#-------------------------------------------------

QT       += testlib gui

#QT       -= gui

TARGET = tst_testaccount
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += tst_testaccount.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../cc-lib/release/ -lcc-lib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../cc-lib/debug/ -lcc-lib
else:unix: LIBS += -L$$OUT_PWD/../cc-lib/ -lcc-lib

INCLUDEPATH += $$PWD/../cc-lib
DEPENDPATH += $$PWD/../cc-lib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cc-lib/release/libcc-lib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cc-lib/debug/libcc-lib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cc-lib/release/cc-lib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$OUT_PWD/../cc-lib/debug/cc-lib.lib
else:unix: PRE_TARGETDEPS += $$OUT_PWD/../cc-lib/libcc-lib.a
