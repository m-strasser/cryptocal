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

SOURCES += \
    event.cpp \
    calendar.cpp \
    account.cpp \
    localstoragemanager.cpp \
    cryptomanager.cpp

HEADERS += \
    event.h \
    calendar.h \
    istoragemanager.h \
    account.h \
    iserializable.h \
    localstoragemanager.h \
    cryptomanager.h
unix {
    target.path = /usr/lib
    INSTALLS += target
}

unix|win32: LIBS += -lcryptopp
