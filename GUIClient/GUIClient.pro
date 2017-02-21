#-------------------------------------------------
#
# Project created by QtCreator 2017-02-21T15:34:22
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GUIClient
TEMPLATE = app


SOURCES += main.cpp\
        MainWindow.cpp \
    core/CClient.cpp \
    core/CDebug.cpp \
    core/CServer.cpp

HEADERS  += MainWindow.h \
    core/CBus.h \
    core/CClient.h \
    core/CDebug.h \
    core/CServer.h \
    core/CSingleton.h \
    core/Messages.h

FORMS    += MainWindow.ui

INCLUDEPATH += $$PWD
