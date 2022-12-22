#ifndef FREQRANGESMAINSIGNAL_H
#define FREQRANGESMAINSIGNAL_H
#include "AbstractANDInterfaces/a_signal.h"
#include "SetRangeFreq_definitions.h"
#include <QDoubleSpinBox>
#include <vector>

class FreqRangesMainSignal : private A_signal
{
public:
    FreqRangesMainSignal(SignalVariables * const signalVariables);

private:
    SetRangeFreqNoSignal m_setRangeFreqNoSignal;
    SetRangeFreqCos m_setRangeFreqCos;
    SetRangeFreqRect m_setRangeFreqRect;
    SetRangeFreqCosRIP m_setRangeFreqCosRIP;
    I_setRangeFrequency *i_SetRangeFreq;
    QDoubleSpinBox *m_ptrToFreqSpinNum;
    std :: vector<I_setRangeFrequency*> m_vectorFreqRanges;

    enum FREQUENCY
    {
        kHz                 = 0,
        MHz                 = 1,
    };

public:
    void checkRangeFrequency(const int &index);
    void changeSetterForRange(const int &indexOfSignal);
    void setPtrToFreqSpinNum(QDoubleSpinBox *const ptrToFreqSpinNum);
};

#endif // FREQRANGESMAINSIGNAL_H
