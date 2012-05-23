#VERSION 0.0.8
QT += phonon
SOURCES += \
    main.cpp \
    MainProcess.cpp \
    window/MainWindow.cpp \
    window/SidePanelWidget.cpp \
    window/ControlWidget.cpp \
    window/LibraryBar.cpp \
    manager/MusicManager.cpp

HEADERS += \
    MainProcess.h \
    window/MainWindow.h \
    window/SidePanelWidget.h \
    window/ControlWidget.h \
    window/LibraryBar.h \
    manager/MusicManager.h

RESOURCES += \
    myressource.qrc
