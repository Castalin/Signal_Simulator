#include "setrangefreqcosriphpm.h"

SetRangeFreqCosRIPHPM::SetRangeFreqCosRIPHPM(SignalVariables *const signalVariables)
    : A_signal{signalVariables}
{

}

double SetRangeFreqCosRIPHPM::setRangeFrequency() const
{
     return (m_signalVariables->m_decimation / 2) - m_signalVariables->m_frequency;
}
