QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += sdk_no_version_check

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ./Sources/Classification.cpp \
    ./Sources/Description.cpp \
    ./Sources/DueDate.cpp \
    ./Sources/Duration.cpp \
    ./Sources/Priority.cpp \
    ./Sources/Title.cpp \
    ./Sources/TaskList.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    ./Headers/Information.hpp \
    ./Headers/Classification.h \
    ./Headers/Description.h \
    ./Headers/DueDate.h \
    ./Headers/Duration.h \
    ./Headers/Priority.h \
    ./Headers/Title.h \
    ./Headers/TaskList.h \
    ./Headers/Task.h \
    ./Headers/User.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
