#-------------------------------------------------
#
# Project created by QtCreator 2010-11-24T09:57:26
#
# https://www.jianshu.com/p/d93c17485c0a libmodbus 手册翻译
#-------------------------------------------------

QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Libra_Modbus
TEMPLATE = app





include(3rdparty/QsLog/QsLog.pri)
include(3rdparty/libmodbus/libmodbus.pri)
include(3rdparty/modmaster/modmaster.pri)


INCLUDEPATH += 3rdparty/libmodbus \
    3rdparty/QsLog \
    3rdparty/modmaster/src



SOURCES += src/main.cpp \
           src/modbuswindow.cpp \

HEADERS  += src/modbuswindow.h

FORMS    += \
            src/modbuswindow.ui

unix:SOURCES +=

unix:DEFINES += _TTY_POSIX_

win32:SOURCES +=

win32:DEFINES += _TTY_WIN_  WINVER=0x0501

win32:LIBS += -lsetupapi -lwsock32 -lws2_32

QMAKE_CXXFLAGS += -std=gnu++11

DEFINES += QS_LOG_LINE_NUMBERS     # automatically writes the file and line for each log message
#DEFINES += QS_LOG_DISABLE         # logging code is replaced with a no-op
#DEFINES += QS_LOG_SEPARATE_THREAD # messages are queued and written from a separate thread
#DEFINES += LIB_MODBUS_DEBUG_OUTPUT # enable debug output from libmodbus




















