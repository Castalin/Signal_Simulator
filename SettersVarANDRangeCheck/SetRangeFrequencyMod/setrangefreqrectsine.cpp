#include "setrangefreqrectsine.h"

SetRangeFreqRectSine::SetRangeFreqRectSine(SignalVariables * const signalVariables)
    :A_signal{signalVariables}
{

}

double SetRangeFreqRectSine::setRangeFrequency() const
{
    if (m_signalVariables->m_duration == 0) // ((m_decimation / 2) - 2 / m_durationMainSignal) < 0
    {
        return 0;
    }
    else
    {
        return (m_signalVariables->m_decimation / 2) - (2 / m_signalVariables->m_duration);
    }
}
