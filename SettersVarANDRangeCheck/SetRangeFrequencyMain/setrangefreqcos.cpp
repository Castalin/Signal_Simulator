#include "setrangefreqcos.h"

SetRangeFreqCos::SetRangeFreqCos(SignalVariables * const signalVariables)
    :A_signal{signalVariables}
{

}

double SetRangeFreqCos::setRangeFrequency() const
{
    return m_signalVariables->m_decimation / 2.0;
}
