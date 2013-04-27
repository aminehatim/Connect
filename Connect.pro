#-------------------------------------------------
#
# Project created by QtCreator 2013-04-27T02:51:42
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Connect
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    setupconnectiondialog.cpp \
    aboutdialog.cpp

HEADERS  += mainwindow.h \
    setupconnectiondialog.h \
    aboutdialog.h

FORMS    += mainwindow.ui \
    setupconnectiondialog.ui \
    aboutdialog.ui
