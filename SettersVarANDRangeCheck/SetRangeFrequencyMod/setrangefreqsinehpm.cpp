#include "setrangefreqsinehpm.h"

SetRangeFreqSineHPM::SetRangeFreqSineHPM(SignalVariables *const signalVariables)
    : A_signal{signalVariables}
{

}

double SetRangeFreqSineHPM::setRangeFrequency() const
{
    return (m_signalVariables->m_decimation / 2) - m_signalVariables->m_frequency;
}
