QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adc_delay.cpp \
    controladdresses.cpp \
    controlangle.cpp \
    controldatamain.cpp \
    controlsettingsOne.cpp \
    controlsettingsTwo.cpp \
    main.cpp \
    mainwindow.cpp \
    settingsreceiver.cpp \
    signalsui.cpp

HEADERS += \
    adc_delay.h \
    controladdresses.h \
    controlangle.h \
    controldatamain.h \
    controlsettingsOne.h \
    controlsettingsTwo.h \
    mainwindow.h \
    settingsreceiver.h \
    signalsui.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
