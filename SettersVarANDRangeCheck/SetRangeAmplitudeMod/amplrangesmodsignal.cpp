#include "amplrangesmodsignal.h"

AmplRangesModSignal::AmplRangesModSignal(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables)
    : m_setRangeHFM{signalVariables, modSignalVariables}, m_setRangeHPM{signalVariables, modSignalVariables}
{
    mapOfAmplRangeSetters[NO_SIGNAL]    = &m_setRangeNoSignal;
    mapOfAmplRangeSetters[SINE_HAM]     = &m_setRangeHAM;
    mapOfAmplRangeSetters[RECTANGLE]    = &m_setRangeRect;
    mapOfAmplRangeSetters[HFM]          = &m_setRangeHFM;
    mapOfAmplRangeSetters[HPM]          = &m_setRangeHPM;

    i_setRangeAmpl = mapOfAmplRangeSetters[NO_SIGNAL];

}

void AmplRangesModSignal::setPtrToAmplSlider(QSlider * const ptrToAmplSlider)
{
    m_ptrTolevelSignalSliderMod = ptrToAmplSlider;
}

void AmplRangesModSignal::changeSetterForRange(const int &index)
{
    i_setRangeAmpl = mapOfAmplRangeSetters[index];
    checkRangeAmplMod();
}

void AmplRangesModSignal::checkRangeAmplMod()
{
    m_ptrTolevelSignalSliderMod->setMaximum(i_setRangeAmpl->getAmplModMax());
    m_ptrTolevelSignalSliderMod->setMinimum(i_setRangeAmpl->getAmplModMin());
}

