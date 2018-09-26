INCLUDEPATH += $$PWD

HEADERS  += \
    $$PWD/zq_slider.h

SOURCES += \
    $$PWD/zq_slider.cpp
FORMS += \
    $$PWD/zq_slider.ui



SOURCES += \
    $$PWD/3rdparty/libmodbus/modbus.c \    
    $$PWD/3rdparty/libmodbus/modbus-data.c \
    $$PWD/3rdparty/libmodbus/modbus-tcp.c \
    $$PWD/3rdparty/libmodbus/modbus-rtu.c \   
    $$PWD/3rdparty/QsLog/QsLogDest.cpp \
    $$PWD/3rdparty/QsLog/QsLog.cpp \
    $$PWD/3rdparty/QsLog/QsLogDestConsole.cpp \
    $$PWD/3rdparty/QsLog/QsLogDestFile.cpp 
    

HEADERS  += \
    $$PWD/3rdparty/libmodbus/modbus.h \
    $$PWD/3rdparty/QsLog/QsLog.h \
    $$PWD/3rdparty/QsLog/QsLogDest.h \
    $$PWD/3rdparty/QsLog/QsLogDestConsole.h \
    $$PWD/3rdparty/QsLog/QsLogLevel.h \
    $$PWD/3rdparty/QsLog/QsLogDisableForThisFile.h \
    $$PWD/3rdparty/QsLog/QsLogDestFile.h 
   

INCLUDEPATH += $$PWD
   


















