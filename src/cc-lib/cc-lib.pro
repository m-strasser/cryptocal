#-------------------------------------------------
#
# Project created by QtCreator 2014-03-18T15:51:56
#
#-------------------------------------------------

QT       += declarative testlib gui

#QT       -= gui

TARGET = cc-lib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += cclib.cpp \
    event.cpp \
    calendar.cpp

HEADERS += cclib.h \
    event.h \
    calendar.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
