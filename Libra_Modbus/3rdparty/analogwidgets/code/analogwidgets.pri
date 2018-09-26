INCLUDEPATH += $$PWD



RESOURCES += $$PWD/analogwidgets.qrc

HEADERS += $$PWD/../analogwidgets/$$PWD/chart/chartdecorator.h \
           $$PWD/../analogwidgets/$$PWD/chart/channeldata.h \
           $$PWD/../analogwidgets/$$PWD/chart/channel.h \
           $$PWD/../analogwidgets/$$PWD/chart/datacontainers.h \
           $$PWD/../analogwidgets/$$PWD/chart/standard/labelsdecorator.h \
           $$PWD/../analogwidgets/$$PWD/chart/standard/legenddecorator.h \
           $$PWD/../analogwidgets/$$PWD/chart/standard/scalegriddecorator.h \
           $$PWD/../analogwidgets/$$PWD/chart/standard/glassdecorator.h \
           $$PWD/../analogwidgets/$$PWD/chart/standard/channeldecorator.h \
           $$PWD/../analogwidgets/$$PWD/chart/scalegrid.h \
           $$PWD/../analogwidgets/led.h \
           $$PWD/../analogwidgets/functions.h \
           $$PWD/../analogwidgets/manometer.h \
           $$PWD/../analogwidgets/chart.h \
           $$PWD/../analogwidgets/thermometer.h \
           $$PWD/defines.h \
           $$PWD/../analogwidgets/abstractmeter.h \
           $$PWD/../analogwidgets/wallclock.h \
           $$PWD/../analogwidgets/widgetwithbackground.h \
           $$PWD/../analogwidgets/bitmapbutton.h \
	   $$PWD/../analogwidgets/counter.h \
	   $$PWD/../analogwidgets/scriptwidget.h \
	   $$PWD/../analogwidgets/potentiometer.h \
           $$PWD/item.h
	   
SOURCES += $$PWD/chart/scalegrid.cpp \
           $$PWD/chart/standard/labelsdecorator.cpp \
           $$PWD/chart/standard/glassdecorator.cpp \
           $$PWD/chart/standard/channeldecorator.cpp \
           $$PWD/chart/standard/legenddecorator.cpp \
           $$PWD/chart/standard/scalegriddecorator.cpp \
           $$PWD/chart/channel.cpp \
           $$PWD/chart.cpp \
           $$PWD/functions.cpp \
           $$PWD/led.cpp \
           $$PWD/manometer.cpp \
           $$PWD/thermometer.cpp \
           $$PWD/wallclock.cpp \
           $$PWD/chart/chartdecorator.cpp \
           $$PWD/abstractmeter.cpp \
           $$PWD/widgetwithbackground.cpp \
           $$PWD/bitmapbutton.cpp \
	   $$PWD/counter.cpp \
	   $$PWD/scriptwidget.cpp \
	   $$PWD/potentiometer.cpp 
	   


INCLUDEPATH += $$PWD/.. \ 
               $$PWD/../analogwidgets 

       

#WIN32{
#  DEFINES+= WIN32
#}
