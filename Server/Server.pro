QT += core widgets network
QT -= gui

TARGET = Server
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    core/CServer.cpp \
    core/CClient.cpp \
    core/CDebug.cpp \
    model/CRoom.cpp \
    model/CRoomCollection.cpp

HEADERS += \
    core/CServer.h \
    core/CClient.h \
    core/CDebug.h \
    core/CSingleton.h \
    core/CBus.h \
    core/Messages.h \
    model/CRoom.h \
    model/CRoomCollection.h

INCLUDEPATH += $$PWD
