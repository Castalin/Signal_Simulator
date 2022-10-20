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
    Signal/a_signal.cpp \
    Signal/a_signalmod.cpp \
    Signal/modrect.cpp \
    Signal/modsine.cpp \
    Signal/nosignal.cpp \
    Signal/rectangle.cpp \
    Signal/rectmodrect.cpp \
    Signal/rectmodsine.cpp \
    Signal/sine.cpp \
    Signal/sinemodrect.cpp \
    Signal/sinemodsine.cpp \
    UI/adc_delay.cpp \
    UI/controladdresses.cpp \
    UI/controlangle.cpp \
    UI/controlsettingsOne.cpp \
    UI/controlsettingsTwo.cpp \
    UI/modulationui.cpp \
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
    Signal/a_signal.h \
    Signal/a_signalmod.h \
    Signal/modrect.h \
    Signal/modsine.h \
    Signal/nosignal.h \
    Signal/rectangle.h \
    Signal/rectmodrect.h \
    Signal/rectmodsine.h \
    Signal/signals_defenition.h \
    Signal/sine.h \
    Signal/sinemodrect.h \
    Signal/sinemodsine.h \
    UI/adc_delay.h \
    UI/controladdresses.h \
    UI/controlangle.h \
    UI/controlsettingsOne.h \
    UI/controlsettingsTwo.h \
    UI/modulationui.h \
    UI/signalsui.h \
    mainwindow.h \


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=
