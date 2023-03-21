QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    AbstractANDInterfaces/a_randomgenerator.cpp \
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
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqcos.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqcosrip.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqnosignal.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqrect.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Cos/setrangefreqcoscos.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Cos/setrangefreqcoscosrip.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Cos/setrangefreqcoshfm.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Cos/setrangefreqcoshpm.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Cos/setrangefreqcosnosignal.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Cos/setrangefreqcosrect.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/CosRIP/setrangefreqcosripcos.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/CosRIP/setrangefreqcosripcosrip.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/CosRIP/setrangefreqcosriphfm.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/CosRIP/setrangefreqcosriphpm.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/CosRIP/setrangefreqcosripnosignal.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/CosRIP/setrangefreqcosriprect.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/NoSignal/setrangefreqnosignalcos.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/NoSignal/setrangefreqnosignalnosignal.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Rect/setrangefreqrectcos.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/freqrangesmodsignal.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/NoSignal/setrangefreqnosignalrect.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/NoSignal/setrangefreqnosignalrip.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Rect/setrangefreqrectnosignal.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Rect/setrangefreqrectrect.cpp \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Rect/setrangefreqrectrip.cpp \
    SettersVarANDRangeCheck/settermainsignal.cpp \
    SettersVarANDRangeCheck/settermodsignal.cpp \
    SettersVarANDRangeCheck/setternoise.cpp \
    Signal/Cos/cos.cpp \
    Signal/Cos/cos_hfm.cpp \
    Signal/Cos/cos_hpm.cpp \
    Signal/Cos/cosmodcos.cpp \
    Signal/Cos/cosmodrect.cpp \
    Signal/Cos/cosmodrip.cpp \
    Signal/CosRIP/cosrip.cpp \
    Signal/CosRIP/cosripmodcos.cpp \
    Signal/CosRIP/cosripmodcosrip.cpp \
    Signal/CosRIP/cosripmodhfm.cpp \
    Signal/CosRIP/cosripmodhpm.cpp \
    Signal/CosRIP/cosripmodrect.cpp \
    Signal/NoSignal/modcos.cpp \
    Signal/NoSignal/modrect.cpp \
    Signal/NoSignal/modrip.cpp \
    Signal/NoSignal/nosignal.cpp \
    Signal/Noise/noisechannel_1.cpp \
    Signal/Noise/noisechannel_2.cpp \
    Signal/Rectangle/rectangle.cpp \
    Signal/Rectangle/rectmodcos.cpp \
    Signal/Rectangle/rectmodrect.cpp \
    Signal/Rectangle/rectmodrip.cpp \
    Signal/factoryofsignal.cpp \
    Structes/all_data.cpp \
    UI/Plots/signalplot.cpp \
    UI/SignalSettings/amplitidemainsignalui.cpp \
    UI/SignalSettings/amplitudemodsignalui.cpp \
    UI/SignalSettings/modulationui.cpp \
    UI/SignalSettings/signalsui.cpp \
    UI/Untouchable/adc_delay.cpp \
    UI/Untouchable/controlsettingsOne.cpp \
    UI/Untouchable/controlsettingsTwo.cpp \
    UI/controladdresses.cpp \
    UI/controlangle.cpp \
    UI/noiseui.cpp \
    main.cpp \
    mainwindow.cpp \
    otherLibs/qcustomplot.cpp

HEADERS += \
    AbstractANDInterfaces/a_randomgenerator.h \
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
    SettersVarANDRangeCheck/SetRangeFrequencyMain/SetRangeFreq_definitions.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/freqrangesmainsignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqcos.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqcosrip.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqnosignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMain/setrangefreqrect.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Cos/setrangefreqcoscos.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Cos/setrangefreqcoscosrip.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Cos/setrangefreqcoshfm.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Cos/setrangefreqcoshpm.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Cos/setrangefreqcosnosignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Cos/setrangefreqcosrect.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/CosRIP/setrangefreqcosripcos.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/CosRIP/setrangefreqcosripcosrip.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/CosRIP/setrangefreqcosriphfm.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/CosRIP/setrangefreqcosriphpm.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/CosRIP/setrangefreqcosripnosignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/CosRIP/setrangefreqcosriprect.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/ModFreqRanges_definitions.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/NoSignal/setrangefreqnosignalcos.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/NoSignal/setrangefreqnosignalnosignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Rect/setrangefreqrectcos.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/freqrangesmodsignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/NoSignal/setrangefreqnosignalrect.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/NoSignal/setrangefreqnosignalrip.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Rect/setrangefreqrectnosignal.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Rect/setrangefreqrectrect.h \
    SettersVarANDRangeCheck/SetRangeFrequencyMod/Rect/setrangefreqrectrip.h \
    SettersVarANDRangeCheck/settermainsignal.h \
    SettersVarANDRangeCheck/settermodsignal.h \
    SettersVarANDRangeCheck/setternoise.h \
    Signal/Cos/cos.h \
    Signal/Cos/cos_hfm.h \
    Signal/Cos/cos_hpm.h \
    Signal/Cos/cosmodcos.h \
    Signal/Cos/cosmodrect.h \
    Signal/Cos/cosmodrip.h \
    Signal/CosRIP/cosrip.h \
    Signal/CosRIP/cosripmodcos.h \
    Signal/CosRIP/cosripmodcosrip.h \
    Signal/CosRIP/cosripmodhfm.h \
    Signal/CosRIP/cosripmodhpm.h \
    Signal/CosRIP/cosripmodrect.h \
    Signal/NoSignal/modcos.h \
    Signal/NoSignal/modrect.h \
    Signal/NoSignal/modrip.h \
    Signal/NoSignal/nosignal.h \
    Signal/Noise/noisechannel_1.h \
    Signal/Noise/noisechannel_2.h \
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
    UI/Plots/signalplot.h \
    UI/SignalSettings/amplitidemainsignalui.h \
    UI/SignalSettings/amplitudemodsignalui.h \
    UI/SignalSettings/modulationui.h \
    UI/SignalSettings/signalsui.h \
    UI/Untouchable/adc_delay.h \
    UI/Untouchable/controlsettingsOne.h \
    UI/Untouchable/controlsettingsTwo.h \
    UI/controladdresses.h \
    UI/controlangle.h \
    UI/noiseui.h \
    mainwindow.h \
    otherLibs/qcustomplot.h


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md
