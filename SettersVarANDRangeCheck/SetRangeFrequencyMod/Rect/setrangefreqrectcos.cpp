#include "setrangefreqrectcos.h"

SetRangeFreqRectCos::SetRangeFreqRectCos(SignalVariables * const signalVariables)
    :A_signal{signalVariables}
{

}

double SetRangeFreqRectCos::setRangeFrequency() const
{
    if (m_signalVariables->m_duration == 0 || ((m_signalVariables->m_decimation / 2) - 2 / m_signalVariables->m_duration) < 0)
    {
        return 0;
    }
    else
    {
        return (m_signalVariables->m_decimation / 2) - (2 / m_signalVariables->m_duration);
    }
}
