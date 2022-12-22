#include "setrangefreqcosriphfm.h"

SetRangeFreqCosRIPHFM::SetRangeFreqCosRIPHFM(SignalVariables * const signalVariables)
    : A_signal{signalVariables}
{

}

double SetRangeFreqCosRIPHFM::setRangeFrequency() const
{
        return (m_signalVariables->m_decimation / 2) - m_signalVariables->m_frequency;
}
