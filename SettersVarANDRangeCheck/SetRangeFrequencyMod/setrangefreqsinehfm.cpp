#include "setrangefreqsinehfm.h"

SetRangeFreqSineHFM::SetRangeFreqSineHFM(SignalVariables * const signalVariables)
    : A_signal{signalVariables}
{

}

double SetRangeFreqSineHFM::setRangeFrequency() const
{
    return (m_signalVariables->m_decimation / 2) - m_signalVariables->m_frequency;
}
