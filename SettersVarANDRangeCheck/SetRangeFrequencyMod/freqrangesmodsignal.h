#ifndef FREQRANGESMODSIGNAL_H
#define FREQRANGESMODSIGNAL_H
#include <QDoubleSpinBox>
#include "ModFreqRanges_definitions.h"

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
    SetRangeFreqNoSignalSine m_setRangeFreqNoSignalSine;
    SetRangeFreqNoSignalRect m_setRangeFreqNoSignalRect;
    SetRangeFreqSineNoSignal m_setRangeFreqSineNoSignal;
    SetRangeFreqSineSine m_setRangeFreqSineSine;
    SetRangeFreqSineRect m_setRangeFreqSineRect;
    SetRangeFreqRectNoSignal m_setRangeFreqRectNoSignal;
    SetRangeFreqRectSine m_setRangeFreqRectSine;
    SetRangeFreqRectRect m_setRangeFreqRectRect;

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

};

#endif // FREQRANGESMODSIGNAL_H
