#include "freqrangesmodsignal.h"
#include <cmath>

FreqRangesModSignal::FreqRangesModSignal(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables)
    : A_signalMod{modSignalVariables}, m_setRangeFreqNoSignalNoSignal{modSignalVariables}, m_setRangeFreqNoSignalSine{modSignalVariables},
      m_setRangeFreqNoSignalRect{modSignalVariables}, m_setRangeFreqSineNoSignal{modSignalVariables}, m_setRangeFreqSineSine{signalVariables},
      m_setRangeFreqSineRect{signalVariables, modSignalVariables}, m_setRangeFreqRectNoSignal{modSignalVariables}, m_setRangeFreqRectSine{signalVariables},
      m_setRangeFreqRectRect{modSignalVariables}, m_setRangeFreqSineHFM{signalVariables}, m_setRangeFreqSineHPM{signalVariables}
{
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: NO_SIGNAL, SIGNALS_MOD :: NO_SIGNAL)] = &m_setRangeFreqNoSignalNoSignal;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: NO_SIGNAL, SIGNALS_MOD :: COS_HAM)]   = &m_setRangeFreqNoSignalSine;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: NO_SIGNAL, SIGNALS_MOD :: RECTANGLE)] = &m_setRangeFreqNoSignalRect;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: NO_SIGNAL)] = &m_setRangeFreqSineNoSignal;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: COS_HAM)]   = &m_setRangeFreqSineSine;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: RECTANGLE)] = &m_setRangeFreqSineRect;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: RECTANGLE, SIGNALS_MOD :: NO_SIGNAL)] = &m_setRangeFreqRectNoSignal;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: RECTANGLE, SIGNALS_MOD :: COS_HAM)]   = &m_setRangeFreqRectSine;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: RECTANGLE, SIGNALS_MOD :: RECTANGLE)] = &m_setRangeFreqRectRect;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: HFM)]       = &m_setRangeFreqSineHFM;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: HPM)]       = &m_setRangeFreqSineHPM;

    i_SetRangeFreq = &m_setRangeFreqNoSignalNoSignal;

}

void FreqRangesModSignal::setPtrToFreqSpinNum(QDoubleSpinBox * const ptrToFreqSpinNum)
{
    m_ptrToFreqSpinNum = ptrToFreqSpinNum;
}

void FreqRangesModSignal::changeSetterForRange(const QPair<int, int> &pairSignals)
{
    i_SetRangeFreq = m_mapFreqRanges.at(pairSignals);
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

