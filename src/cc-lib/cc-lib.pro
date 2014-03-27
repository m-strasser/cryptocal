#-------------------------------------------------
#
# Project created by QtCreator 2014-03-18T15:51:56
#
#-------------------------------------------------

QT       += declarative testlib

QT       -= gui

TARGET = cc-lib
TEMPLATE = lib
CONFIG += staticlib

SOURCES += cclib.cpp \
    event.cpp

HEADERS += cclib.h \
    event.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}
