#-------------------------------------------------
#
# Project created by QtCreator 2010-11-24T09:57:26
#
# https://www.jianshu.com/p/d93c17485c0a libmodbus 手册翻译
#-------------------------------------------------

QT       += core gui
QT       += xml svg script gui
QT       += quickwidgets qml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Libra_Modbus
TEMPLATE = app


include(3rdparty/QsLog/QsLog.pri)
include(3rdparty/libmodbus/libmodbus.pri)
include(3rdparty/modmaster/modmaster.pri)

include(3rdparty/analogwidgets/code/analogwidgets.pri)


INCLUDEPATH += 3rdparty/libmodbus \
    3rdparty/QsLog \
    3rdparty/modmaster/src \
    3rdparty/analogwidgets/analogwidgets \
    3rdparty/analogwidgets/code


SOURCES += src/main.cpp \
           src/modbuswindow.cpp \
           src/function_extend.cpp \
    src/codetest.cpp

HEADERS  += src/modbuswindow.h \
            src/function_extend.h \
    src/codetest.h \
    src/app_config.h

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

RESOURCES += \
    resource.qrc

DISTFILES += \
    resource/qml/main.qml
    resource/qml/DashboardGaugeStyle.qml

OTHER_FILES += \
    resource/qml/main.qml
    resource/qml/DashboardGaugeStyle.qml



















