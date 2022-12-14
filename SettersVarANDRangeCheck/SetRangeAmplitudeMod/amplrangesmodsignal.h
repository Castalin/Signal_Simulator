#ifndef AMPLRANGESMODSIGNAL_H
#define AMPLRANGESMODSIGNAL_H
#include "ModAmplRanges_definitions.h"
#include "Structes/enumSignals.h"
#include <map>
#include <QSlider>

class AmplRangesModSignal
{
public:
    AmplRangesModSignal(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables);

private:
    SetRangeAmplNoSignal m_setRangeNoSignal;
    SetRangeAmplHAM m_setRangeHAM;
    SetRangeAmplRect m_setRangeRect;
    SetRangeAmplHFM m_setRangeHFM;
    SetRangeAmplHPM m_setRangeHPM;
    SetRangeAmplRIP m_setRangeRIP;

    I_getAmplModRange *i_setRangeAmpl;
    std :: map <int, I_getAmplModRange*>mapOfAmplRangeSetters;
    QSlider *m_ptrTolevelSignalSliderMod;

public:
    void setPtrToAmplSlider(QSlider * const ptrToAmplSlider);
    void changeSetterForRange(const int &index);
    void checkRangeAmplMod();
};

#endif // AMPLRANGESMODSIGNAL_H
