#-------------------------------------------------
#
# Project created by QtCreator 2014-03-30T21:38:33
#
#-------------------------------------------------

QT       += core gui

TARGET = qtControlMano
TEMPLATE = app

include(serial/qextserialport.pri)
win32:DEFINES += USA_EMOTIV


win32:INCLUDEPATH += win/includeLeap
unix:INCLUDEPATH += linux/includeLeap

win32:LIBS += win/lib/x86/Leapd.lib -Lwin/lib/x86
unix:LIBS += linux/lib/x64/libLeap.so -Llinux/lib/x64

SOURCES += main.cpp\
        mainwindow.cpp \
    control_Leap.cpp \
    encargadoComunicacion.cpp \
    encargadocomunicacionserial.cpp \
    conversorleapservo.cpp \
    controlmanual.cpp \
    controlemotiv.cpp

HEADERS  += mainwindow.h \
    control_Leap.h \
    encargadoComunicacion.h \
    encargadocomunicacionserial.h \
    conversorleapservo.h \
    controlmanual.h \
    controlemotiv.h

FORMS    += mainwindow.ui \
    controlmanual.ui \
    controlemotiv.ui
