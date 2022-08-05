QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adc_delay.cpp \
    controlsettings_1.cpp \
    controlsettings_2.cpp \
    main.cpp \
    mainwindow.cpp \
    signalsui.cpp

HEADERS += \
    adc_delay.h \
    controlsettings_1.h \
    controlsettings_2.h \
    mainwindow.h \
    signalsui.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
