QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    BackEnd/anglecounter.cpp \
    BackEnd/controldatamain.cpp \
    BackEnd/settingsreceiver.cpp \
    BackEnd/settingssender.cpp \
    BackEnd/signaldatamain.cpp \
    BackEnd/signalgenerator.cpp \
    UI/adc_delay.cpp \
    UI/controladdresses.cpp \
    UI/controlangle.cpp \
    UI/controlsettingsOne.cpp \
    UI/controlsettingsTwo.cpp \
    UI/signalsui.cpp \
    main.cpp \
    mainwindow.cpp \

HEADERS += \
    BackEnd/anglecounter.h \
    BackEnd/controldatamain.h \
    BackEnd/settingsreceiver.h \
    BackEnd/settingssender.h \
    BackEnd/signaldatamain.h \
    BackEnd/signalgenerator.h \
    UI/adc_delay.h \
    UI/controladdresses.h \
    UI/controlangle.h \
    UI/controlsettingsOne.h \
    UI/controlsettingsTwo.h \
    UI/signalsui.h \
    mainwindow.h \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
