QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AbstractANDInterfaces/a_signal.cpp \
    AbstractANDInterfaces/a_signalmod.cpp \
    AbstractANDInterfaces/i_getamplmodrange.cpp \
    AbstractANDInterfaces/i_getsignal.cpp \
    AbstractANDInterfaces/i_getsignalim.cpp \
    AbstractANDInterfaces/i_setrangeduration.cpp \
    AbstractANDInterfaces/i_setrangefrequency.cpp \
    BackEnd/anglecounter.cpp \
    BackEnd/controldatamain.cpp \
    BackEnd/settingsreceiver.cpp \
    BackEnd/settingssender.cpp \
    BackEnd/signaldatamain.cpp \
    BackEnd/signalgenerator.cpp \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/amplrangesmodsignal.cpp \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/setrangeamplham.cpp \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/setrangeamplhfm.cpp \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/setrangeamplhpm.cpp \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/setrangeamplnosignal.cpp \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/setrangeamplrect.cpp \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/setrangeamplrip.cpp \
    SettersVarANDRangeCheck/SetRangeDurationMain/durationrangesmainsignal.cpp \
    SettersVarANDRangeCheck/SetRangeDurationMain/setrangedurationrect.cpp \
    SettersVarANDRangeCheck/SetRangeDurationMod/durationrangesmodsignal.cpp \
    SettersVarANDRangeCheck/SetRangeDurationMod/setrangedurationrectMod.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/freqrangesmainsignal.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqnosignal.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqrect.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqsine.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/freqrangesmodsignal.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqnosignalnosignal.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqnosignalrect.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqnosignalrip.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqnosignalsine.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqrectnosignal.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqrectrect.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqrectrip.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqrectsine.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqsinehfm.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqsinehpm.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqsinenosignal.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqsinerect.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqsinerip.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqsinesine.cpp \
    SettersVarANDRangeCheck/settermainsignal.cpp \
    SettersVarANDRangeCheck/settermodsignal.cpp \
    SettersVarANDRangeCheck/setternoise.cpp \
    Signal/Cos/cos.cpp \
    Signal/Cos/cos_hfm.cpp \
    Signal/Cos/cos_hpm.cpp \
    Signal/Cos/cosmodcos.cpp \
    Signal/Cos/cosmodrect.cpp \
    Signal/Cos/cosmodrip.cpp \
    Signal/NoSignal/modcos.cpp \
    Signal/NoSignal/modrect.cpp \
    Signal/NoSignal/modrip.cpp \
    Signal/NoSignal/nosignal.cpp \
    Signal/Noise/noise.cpp \
    Signal/Rectangle/rectangle.cpp \
    Signal/Rectangle/rectmodcos.cpp \
    Signal/Rectangle/rectmodrect.cpp \
    Signal/Rectangle/rectmodrip.cpp \
    Signal/factoryofsignal.cpp \
    Structes/all_data.cpp \
    UI/Untouchable/adc_delay.cpp \
    UI/Untouchable/controlsettingsOne.cpp \
    UI/Untouchable/controlsettingsTwo.cpp \
    UI/amplitidemainsignalui.cpp \
    UI/amplitudemodsignalui.cpp \
    UI/controladdresses.cpp \
    UI/controlangle.cpp \
    UI/modulationui.cpp \
    UI/noiseui.cpp \
    UI/signalsui.cpp \
    main.cpp \
    mainwindow.cpp \
    test.cpp

HEADERS += \
    AbstractANDInterfaces/a_signal.h \
    AbstractANDInterfaces/a_signalmod.h \
    AbstractANDInterfaces/i_getamplmodrange.h \
    AbstractANDInterfaces/i_getsignal.h \
    AbstractANDInterfaces/i_getsignalim.h \
    AbstractANDInterfaces/i_setrangeduration.h \
    AbstractANDInterfaces/i_setrangefrequency.h \
    BackEnd/anglecounter.h \
    BackEnd/controldatamain.h \
    BackEnd/settingsreceiver.h \
    BackEnd/settingssender.h \
    BackEnd/signaldatamain.h \
    BackEnd/signalgenerator.h \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/ModAmplRanges_definitions.h \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/amplrangesmodsignal.h \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/setrangeamplham.h \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/setrangeamplhfm.h \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/setrangeamplhpm.h \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/setrangeamplnosignal.h \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/setrangeamplrect.h \
    SettersVarANDRangeCheck/SetRangeAmplitudeMod/setrangeamplrip.h \
    SettersVarANDRangeCheck/SetRangeDurationMain/durationrangesmainsignal.h \
    SettersVarANDRangeCheck/SetRangeDurationMain/setrangedurationrect.h \
    SettersVarANDRangeCheck/SetRangeDurationMod/durationrangesmodsignal.h \
    SettersVarANDRangeCheck/SetRangeDurationMod/setrangedurationrectMod.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/freqrangesmainsignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqnosignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqrect.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqsine.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/ModFreqRanges_definitions.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/freqrangesmodsignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqnosignalnosignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqnosignalrect.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqnosignalrip.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqnosignalsine.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqrectnosignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqrectrect.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqrectrip.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqrectsine.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqsinehfm.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqsinehpm.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqsinenosignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqsinerect.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqsinerip.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/setrangefreqsinesine.h \
    SettersVarANDRangeCheck/settermainsignal.h \
    SettersVarANDRangeCheck/settermodsignal.h \
    SettersVarANDRangeCheck/setternoise.h \
    Signal/Cos/cos.h \
    Signal/Cos/cos_hfm.h \
    Signal/Cos/cos_hpm.h \
    Signal/Cos/cosmodcos.h \
    Signal/Cos/cosmodrect.h \
    Signal/Cos/cosmodrip.h \
    Signal/NoSignal/modcos.h \
    Signal/NoSignal/modrect.h \
    Signal/NoSignal/modrip.h \
    Signal/NoSignal/nosignal.h \
    Signal/Noise/noise.h \
    Signal/Rectangle/rectangle.h \
    Signal/Rectangle/rectmodcos.h \
    Signal/Rectangle/rectmodrect.h \
    Signal/Rectangle/rectmodrip.h \
    Signal/factoryofsignal.h \
    Signal/signals_defenition.h \
    Structes/ModSignalVariables.h \
    Structes/NoiseVariables.h \
    Structes/SignalVariables.h \
    Structes/all_data.h \
    Structes/enumSignals.h \
    UI/Untouchable/adc_delay.h \
    UI/Untouchable/controlsettingsOne.h \
    UI/Untouchable/controlsettingsTwo.h \
    UI/amplitidemainsignalui.h \
    UI/amplitudemodsignalui.h \
    UI/controladdresses.h \
    UI/controlangle.h \
    UI/modulationui.h \
    UI/noiseui.h \
    UI/signalsui.h \
    mainwindow.h \
    test.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md
