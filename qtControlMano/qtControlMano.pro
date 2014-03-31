#-------------------------------------------------
#
# Project created by QtCreator 2014-03-30T21:38:33
#
#-------------------------------------------------

QT       += core gui

TARGET = qtControlMano
TEMPLATE = app

INCLUDEPATH += includeLeap

include(./serial/qextserialport.pri)

LIBS += lib/x64/libLeap.so -Llib/x64

SOURCES += main.cpp\
        mainwindow.cpp \
    emisordededos.cpp \
    control_Leap.cpp \
    comunicacion.cpp

HEADERS  += mainwindow.h \
    emisordededos.h \
    control_Leap.h \
    comunicacion.h

FORMS    += mainwindow.ui
