#-------------------------------------------------
#
# Project created by QtCreator 2017-01-08T16:27:07
#
#-------------------------------------------------

QT       += core gui
QT       += sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Myproject1
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    passworderror.cpp \
    connect.cpp \
    dialog.cpp

HEADERS  += mainwindow.h \
    passworderror.h \
    globals.h \
    connect.h \
    dialog.h

FORMS    += mainwindow.ui \
    dialog.ui \
    passworderror.ui

RESOURCES += \
    resources.qrc
