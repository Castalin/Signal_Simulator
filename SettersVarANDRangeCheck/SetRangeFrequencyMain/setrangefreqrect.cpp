#include "setrangefreqrect.h"

SetRangeFreqRect::SetRangeFreqRect(SignalVariables * const signalVariables)
    :A_signal{signalVariables}
{

}

double SetRangeFreqRect::setRangeFrequency() const
{
    return m_signalVariables->m_decimation /(m_signalVariables->m_duration * m_signalVariables->m_decimation + 2);
}
