#-------------------------------------------------
#
# Project created by QtCreator 2015-10-07T12:40:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iprat-gui
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    actor.cpp \
    connection.cpp \
    information.cpp \
    task.cpp \
    function.cpp \
    identificationcreator.cpp

HEADERS  += mainwindow.h \
    actor.h \
    connection.h \
    information.h \
    task.h \
    function.h \
    identificationcreator.h

FORMS    += mainwindow.ui