#include "setrangefreqcoshfm.h"

SetRangeFreqCosHFM::SetRangeFreqCosHFM(SignalVariables * const signalVariables)
    : A_signal{signalVariables}
{

}

double SetRangeFreqCosHFM::setRangeFrequency() const
{
    return (m_signalVariables->m_decimation / 2) - m_signalVariables->m_frequency;
}
