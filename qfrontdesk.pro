#-------------------------------------------------
#
# Project created by QtCreator 2012-10-23T15:38:33
#
#-------------------------------------------------

QT       += network
QT       -= gui

TARGET = qfrontdesk
TEMPLATE = lib

DEFINES += QFRONTDESK_LIBRARY

SOURCES += qfrontdesk.cpp \
    requestmanager.cpp \
    request.cpp \
    arguments.cpp

HEADERS += qfrontdesk.h\
        qfrontdesk_global.h \
    requestmanager.h \
    request.h \
    arguments.h

unix:macx: LIBS += -lgrantlee_core
