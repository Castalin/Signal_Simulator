#include "freqrangesmodsignal.h"
#include <cmath>

FreqRangesModSignal::FreqRangesModSignal(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables)
    : A_signalMod{modSignalVariables}, m_setRangeFreqNoSignalNoSignal{modSignalVariables}, m_setRangeFreqNoSignalCos{modSignalVariables},
      m_setRangeFreqNoSignalRect{modSignalVariables}, m_setRangeFreqCosNoSignal{modSignalVariables}, m_setRangeFreqCosCos{signalVariables},
      m_setRangeFreqCosRect{signalVariables, modSignalVariables}, m_setRangeFreqRectNoSignal{modSignalVariables}, m_setRangeFreqRectCos{signalVariables},
      m_setRangeFreqRectRect{modSignalVariables}, m_setRangeFreqCosHFM{signalVariables}, m_setRangeFreqCosHPM{signalVariables},
      m_setRangeFreqNoSignalRIP{modSignalVariables}, m_setRangeFreqCosCosRIP{signalVariables}, m_setRangeFreqRectRIP{signalVariables},
      m_setRangeFreqCosRIPNoSignal{modSignalVariables}, m_setRangeFreqCosRIPRect{signalVariables, modSignalVariables},
      m_setRangeFreqCosRIPCosRIP{signalVariables}, m_setRangeFreqCosRIPCos{signalVariables}, m_setRangeFreqCosRIPHFM{signalVariables},
      m_setRangeFreqCosRIPHPM{signalVariables}
{
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: NO_SIGNAL, SIGNALS_MOD :: NO_SIGNAL)]             = &m_setRangeFreqNoSignalNoSignal;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: NO_SIGNAL, SIGNALS_MOD :: COS_HAM)]               = &m_setRangeFreqNoSignalCos;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: NO_SIGNAL, SIGNALS_MOD :: RECTANGLE)]             = &m_setRangeFreqNoSignalRect;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: NO_SIGNAL, SIGNALS_MOD :: COS_HAM_RNDPHASE)]      = &m_setRangeFreqNoSignalRIP;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: NO_SIGNAL)]             = &m_setRangeFreqCosNoSignal;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: COS_HAM)]               = &m_setRangeFreqCosCos;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: RECTANGLE)]             = &m_setRangeFreqCosRect;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: COS_HAM_RNDPHASE)]      = &m_setRangeFreqCosCosRIP;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: HFM)]                   = &m_setRangeFreqCosHFM;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS,       SIGNALS_MOD :: HPM)]                   = &m_setRangeFreqCosHPM;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: RECTANGLE, SIGNALS_MOD :: NO_SIGNAL)]             = &m_setRangeFreqRectNoSignal;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: RECTANGLE, SIGNALS_MOD :: COS_HAM)]               = &m_setRangeFreqRectCos;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: RECTANGLE, SIGNALS_MOD :: RECTANGLE)]             = &m_setRangeFreqRectRect;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: RECTANGLE, SIGNALS_MOD :: COS_HAM_RNDPHASE)]      = &m_setRangeFreqRectRIP;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS_RIP,   SIGNALS_MOD :: NO_SIGNAL)]             = &m_setRangeFreqCosRIPNoSignal;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS_RIP,   SIGNALS_MOD :: COS_HAM)]               = &m_setRangeFreqCosRIPCos;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS_RIP,   SIGNALS_MOD :: RECTANGLE)]             = &m_setRangeFreqCosRIPRect;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS_RIP,   SIGNALS_MOD :: COS_HAM_RNDPHASE)]      = &m_setRangeFreqCosRIPCosRIP;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS_RIP,   SIGNALS_MOD :: HFM)]                   = &m_setRangeFreqCosRIPHFM;
    m_mapFreqRanges[QPair(SIGNALS_MAIN :: COS_RIP,   SIGNALS_MOD :: HPM)]                   = &m_setRangeFreqCosRIPHPM;

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

