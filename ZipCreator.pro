#-------------------------------------------------
#
# Project created by QtCreator 2015-05-23T21:11:59
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ZipCreator
TEMPLATE = app

SOURCES += main.cpp Widget.cpp

HEADERS  += Widget.h

FORMS    += Widget.ui

INCLUDEPATH += $$PWD/3rdParty/QuaZip/include
INCLUDEPATH += $$PWD/3rdParty/zlib/include

LIBS += -L$$PWD/3rdParty/QuaZip/lib
LIBS += -L$$PWD/3rdParty/zlib/lib

LIBS += -lquazip -lzlib

QMAKE_CXXFLAGS += -std=gnu++14
