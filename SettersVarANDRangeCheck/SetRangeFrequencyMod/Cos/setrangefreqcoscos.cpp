#include "setrangefreqcoscos.h"

SetRangeFreqCosCos::SetRangeFreqCosCos(SignalVariables * const signalVariables)
    :A_signal{signalVariables}
{

}

double SetRangeFreqCosCos::setRangeFrequency() const
{
    if (m_signalVariables->m_decimation / 4 < m_signalVariables->m_frequency)
    {
        return (m_signalVariables->m_decimation / 2) - m_signalVariables->m_frequency;
    }
    else
    {
        return m_signalVariables->m_frequency;
    }
}
