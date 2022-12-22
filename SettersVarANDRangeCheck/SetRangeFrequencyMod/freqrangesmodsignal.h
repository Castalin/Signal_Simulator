#ifndef FREQRANGESMODSIGNAL_H
#define FREQRANGESMODSIGNAL_H
#include <QDoubleSpinBox>
#include "ModFreqRanges_definitions.h"
#include "Structes/enumSignals.h"

class FreqRangesModSignal : private A_signalMod
{
public:
    FreqRangesModSignal(SignalVariables *const signalVariables, ModSignalVariables *const modSignalVariables);
    void setPtrToFreqSpinNum(QDoubleSpinBox *const ptrToFreqSpinNum);
    void changeSetterForRange(const QPair<int, int> &pairSignals);
    void checkRangeFrequencyMod(const int &index);


private:
    QDoubleSpinBox *m_ptrToFreqSpinNum;
    std :: map <QPair<int, int>, I_setRangeFrequency*> m_mapFreqRanges;
    I_setRangeFrequency *i_SetRangeFreq;

    SetRangeFreqNoSignalNoSignal m_setRangeFreqNoSignalNoSignal;
    SetRangeFreqNoSignalCos m_setRangeFreqNoSignalCos;
    SetRangeFreqNoSignalRect m_setRangeFreqNoSignalRect;
    SetRangeFreqCosNoSignal m_setRangeFreqCosNoSignal;
    SetRangeFreqCosCos m_setRangeFreqCosCos;
    SetRangeFreqCosRect m_setRangeFreqCosRect;
    SetRangeFreqRectNoSignal m_setRangeFreqRectNoSignal;
    SetRangeFreqRectCos m_setRangeFreqRectCos;
    SetRangeFreqRectRect m_setRangeFreqRectRect;
    SetRangeFreqCosHFM m_setRangeFreqCosHFM;
    SetRangeFreqCosHPM m_setRangeFreqCosHPM;
    SetRangeFreqNoSignalRip m_setRangeFreqNoSignalRIP;
    SetRangeFreqCosCosRIP m_setRangeFreqCosCosRIP;
    SetRangeFreqRectRIP m_setRangeFreqRectRIP;
    SetRangeFreqCosRIPNoSignal m_setRangeFreqCosRIPNoSignal;
    SetRangeFreqCosRIPRect m_setRangeFreqCosRIPRect;
    SetRangeFreqCosRIPCosRIP m_setRangeFreqCosRIPCosRIP;
    SetRangeFreqCosRIPCos m_setRangeFreqCosRIPCos;
    SetRangeFreqCosRIPHFM m_setRangeFreqCosRIPHFM;
    SetRangeFreqCosRIPHPM m_setRangeFreqCosRIPHPM;


    enum FREQUENCY
    {
        kHz                 = 0,
        MHz                 = 1,
    };

};

#endif // FREQRANGESMODSIGNAL_H
