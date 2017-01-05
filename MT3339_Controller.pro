QT += widgets serialport

TARGET = terminal
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    settingsdialog.cpp \
    console.cpp \
    nmea_parser.cpp \
    download_dialog.cpp

HEADERS += \
    mainwindow.h \
    settingsdialog.h \
    console.h \
    nmea_parser.h \
    download_dialog.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui

RESOURCES += \
    terminal.qrc

target.path = $$[QT_INSTALL_EXAMPLES]/serialport/terminal
INSTALLS += target


LIBS += -lmarblewidget-qt5
