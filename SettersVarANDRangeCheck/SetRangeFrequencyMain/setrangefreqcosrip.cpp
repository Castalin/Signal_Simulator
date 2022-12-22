#include "setrangefreqcosrip.h"

SetRangeFreqCosRIP::SetRangeFreqCosRIP(SignalVariables * const signalVariables)
    : A_signal{signalVariables}
{

}

double SetRangeFreqCosRIP::setRangeFrequency() const
{
    return m_signalVariables->m_decimation / 2.0;
}
