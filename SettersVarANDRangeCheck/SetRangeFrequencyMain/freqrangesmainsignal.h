#ifndef FREQRANGESMAINSIGNAL_H
#define FREQRANGESMAINSIGNAL_H
#include "setrangefreqnosignal.h"
#include "setrangefreqsine.h"
#include "setrangefreqrect.h"
#include "AbstractANDInterfaces/a_signal.h"
#include <QDoubleSpinBox>
#include <map>

class FreqRangesMainSignal : private A_signal
{
public:
    FreqRangesMainSignal(SignalVariables * const signalVariables);

private:
    SetRangeFreqNoSignal m_setRangeFreqNoSignal;
    SetRangeFreqSine m_setRangeFreqSine;
    SetRangeFreqRect m_setRangeFreqRect;
    I_setRangeFrequency *i_SetRangeFreq;
    QDoubleSpinBox *m_ptrToFreqSpinNum;
    std :: map <int, I_setRangeFrequency*> m_mapFreqRanges;

    enum SIGNALS
    {
        NO_SIGNAL           = 0,
        SINE                = 1,
        RECTANGLE           = 2,
    };

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
