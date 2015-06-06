#-------------------------------------------------
#
# Project created by QtCreator 2015-05-13T00:14:34
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Astrophysics
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    imf.cpp \
    infooaplikacji.cpp

HEADERS  += mainwindow.h \
    imf.h \
    infooaplikacji.h

FORMS    += mainwindow.ui \
    infooaplikacji.ui

CONFIG += qwt

DISTFILES += \
    astrophysics
