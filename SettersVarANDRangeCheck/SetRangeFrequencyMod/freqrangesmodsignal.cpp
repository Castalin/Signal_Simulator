#include "freqrangesmodsignal.h"
#include <cmath>

FreqRangesModSignal::FreqRangesModSignal(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables)
    :A_signalMod{modSignalVariables}, m_setRangeFreqNoSignalNoSignal{modSignalVariables}, m_setRangeFreqNoSignalSine{modSignalVariables},
      m_setRangeFreqNoSignalRect{modSignalVariables}, m_setRangeFreqSineNoSignal{modSignalVariables}, m_setRangeFreqSineSine{signalVariables},
      m_setRangeFreqSineRect{signalVariables, modSignalVariables}, m_setRangeFreqRectNoSignal{modSignalVariables}, m_setRangeFreqRectSine{signalVariables},
      m_setRangeFreqRectRect{modSignalVariables}
{
    m_mapFreqRanges[QPair(NO_SIGNAL, NO_SIGNAL)] = &m_setRangeFreqNoSignalNoSignal;
    m_mapFreqRanges[QPair(NO_SIGNAL, SINE)] =   &m_setRangeFreqNoSignalSine;
    m_mapFreqRanges[QPair(NO_SIGNAL, RECTANGLE)] = &m_setRangeFreqNoSignalRect;
    m_mapFreqRanges[QPair(SINE, NO_SIGNAL)] = &m_setRangeFreqSineNoSignal;
    m_mapFreqRanges[QPair(SINE, SINE)] = &m_setRangeFreqSineSine;
    m_mapFreqRanges[QPair(SINE, RECTANGLE)] = &m_setRangeFreqSineRect;
    m_mapFreqRanges[QPair(RECTANGLE, NO_SIGNAL)] = &m_setRangeFreqRectNoSignal;
    m_mapFreqRanges[QPair(RECTANGLE, SINE)] = &m_setRangeFreqRectSine;
    m_mapFreqRanges[QPair(RECTANGLE, RECTANGLE)] = &m_setRangeFreqRectRect;

    i_SetRangeFreq = &m_setRangeFreqNoSignalNoSignal;

}

void FreqRangesModSignal::setPtrToFreqSpinNum(QDoubleSpinBox * const ptrToFreqSpinNum)
{
    m_ptrToFreqSpinNum = ptrToFreqSpinNum;
}

void FreqRangesModSignal::changeSetterForRange(const QPair<int, int> &pairSignals)
{
    i_SetRangeFreq = m_mapFreqRanges[pairSignals];
}

void FreqRangesModSignal::checkRangeFrequencyMod(const int &index)
{
    if (index == FREQUENCY :: kHz)
    {
        m_ptrToFreqSpinNum->setMaximum(i_SetRangeFreq->setRangeFrequency() / 1e3);
        m_ptrToFreqSpinNum->setValue(m_modSignalVariables->m_frequencyMod / 1e3);
        m_ptrToFreqSpinNum->setSingleStep(5.0);
        return;
    }
    else
    {
        m_ptrToFreqSpinNum->setValue(m_modSignalVariables->m_frequencyMod / 1e6);
        m_ptrToFreqSpinNum->setMaximum(floor(i_SetRangeFreq->setRangeFrequency() / 1e3) / 1e3);
        m_ptrToFreqSpinNum->setSingleStep(0.5);
        return;
    }
}

