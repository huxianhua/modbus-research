#-------------------------------------------------
#
# Project created by QtCreator 2010-11-24T09:57:26
#
# https://www.jianshu.com/p/d93c17485c0a libmodbus 手册翻译
#-------------------------------------------------

INCLUDEPATH += $$PWD


SOURCES +=  \
    $$PWD/src/mainwindow.cpp \
    $$PWD/src/about.cpp \
    $$PWD/src/settingsmodbusrtu.cpp \
    $$PWD/src/settingsmodbustcp.cpp \
    $$PWD/src/modbusadapter.cpp \
    $$PWD/src/eutils.cpp \
    $$PWD/src/registersmodel.cpp \
    $$PWD/src/rawdatamodel.cpp \
    $$PWD/src/settings.cpp \
    $$PWD/src/busmonitor.cpp \
    $$PWD/src/rawdatadelegate.cpp \
    $$PWD/src/registersdatadelegate.cpp \
    $$PWD/src/modbuscommsettings.cpp \
    $$PWD/src/infobar.cpp

HEADERS  += $$PWD/src/mainwindow.h \
    $$PWD/src/about.h \
    $$PWD/src/settingsmodbusrtu.h \
    $$PWD/src/settingsmodbustcp.h \
    $$PWD/src/modbusadapter.h \
    $$PWD/src/eutils.h \
    $$PWD/src/registersmodel.h \
    $$PWD/src/rawdatamodel.h \
    $$PWD/src/settings.h \
    $$PWD/src/busmonitor.h \
    $$PWD/src/rawdatadelegate.h \
    $$PWD/src/registersdatadelegate.h \
    $$PWD/src/modbuscommsettings.h \
    $$PWD/src/infobar.h





INCLUDEPATH += ../libmodbus \
    ../QsLog

TRANSLATIONS += translations/$$TARGET"_zh_CN.ts"
TRANSLATIONS += translations/$$TARGET"_zh_TW.ts"

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

FORMS    += $$PWD/src/mainwindow.ui \
    $$PWD/src/about.ui \
    $$PWD/src/settingsmodbusrtu.ui \
    $$PWD/src/settingsmodbustcp.ui \
    $$PWD/src/settings.ui \
    $$PWD/src/busmonitor.ui

RESOURCES += \
    $$PWD/icons/icons.qrc \
    $$PWD/translations/translations.qrc


















