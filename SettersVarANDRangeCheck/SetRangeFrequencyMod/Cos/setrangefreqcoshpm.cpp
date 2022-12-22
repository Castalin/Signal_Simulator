#include "setrangefreqcoshpm.h"

SetRangeFreqCosHPM::SetRangeFreqCosHPM(SignalVariables *const signalVariables)
    : A_signal{signalVariables}
{

}

double SetRangeFreqCosHPM::setRangeFrequency() const
{
    return (m_signalVariables->m_decimation / 2) - m_signalVariables->m_frequency;
}
