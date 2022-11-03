#include "freqrangesmainsignal.h"
#include <cmath>


FreqRangesMainSignal::FreqRangesMainSignal(SignalVariables * const signalVariables)
    : A_signal{signalVariables}, m_setRangeFreqNoSignal{signalVariables}, m_setRangeFreqSine{signalVariables}, m_setRangeFreqRect{signalVariables}
{
    i_SetRangeFreq = &m_setRangeFreqNoSignal;

    m_mapFreqRanges[NO_SIGNAL] = &m_setRangeFreqNoSignal;
    m_mapFreqRanges[SINE] = &m_setRangeFreqSine;
    m_mapFreqRanges[RECTANGLE] = &m_setRangeFreqRect;


}

void FreqRangesMainSignal::checkRangeFrequency(const int &index)
{
    if (index == FREQUENCY :: kHz)
    {
        m_ptrToFreqSpinNum->setMaximum(i_SetRangeFreq->setRangeFrequency() / 1e3);
        m_ptrToFreqSpinNum->setValue(m_signalVariables->m_frequency / 1e3);
        m_ptrToFreqSpinNum->setSingleStep(5.0);
        return;
    }
    else
    {
        m_ptrToFreqSpinNum->setValue(m_signalVariables->m_frequency / 1e6);
        m_ptrToFreqSpinNum->setMaximum(floor(i_SetRangeFreq->setRangeFrequency() / 1e3) / 1e3);
        m_ptrToFreqSpinNum->setSingleStep(0.5);
        return;
    }
}

void FreqRangesMainSignal::changeSetterForRange(const int &indexOfSignal)
{
    i_SetRangeFreq = m_mapFreqRanges[indexOfSignal];
}

void FreqRangesMainSignal::setPtrToFreqSpinNum(QDoubleSpinBox * const ptrToFreqSpinNum)
{
    m_ptrToFreqSpinNum = ptrToFreqSpinNum;
}
