INCLUDEPATH += $$PWD


HEADERS  += \
    $$PWD/modbus.h \
    $$PWD/modbus-private.h \
    $$PWD/modbus-rtu.h \
    $$PWD/modbus-rtu-private.h \
    $$PWD/modbus-tcp.h \
    $$PWD/modbus-tcp-private.h \
    $$PWD/modbus-version.h \
    $$PWD/config.h

SOURCES += \
    $$PWD/modbus.c \
    $$PWD/modbus-data.c \
    $$PWD/modbus-tcp.c \
    $$PWD/modbus-rtu.c


INCLUDEPATH += $$PWD
