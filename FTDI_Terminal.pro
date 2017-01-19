QT += widgets serialport

TARGET = MT3339_FTDI_Controller
TEMPLATE = app

LIBS +=   -lftdi1 -lusb-1.0
QMAKE_CXXFLAGS += -std=c++11


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    console.cpp \
    nmea_parser.cpp \
    dialog.cpp \
    ft_serial1.cpp \
    processwrapper.cpp

HEADERS += \
    mainwindow.h \
    console.h \
    nmea_parser.h \
    dialog.h \
    ft_serial1.h \
    processwrapper.h \
    pmtkcommands.h


FORMS += \
    mainwindow.ui \
    dialog.ui

RESOURCES +=

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target

DISTFILES += \
    text
