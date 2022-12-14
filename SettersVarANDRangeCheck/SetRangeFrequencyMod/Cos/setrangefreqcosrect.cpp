#include "setrangefreqcosrect.h"

SetRangeFreqCosRect::SetRangeFreqCosRect(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables)
    : A_signal{signalVariables}, A_signalMod{modSignalVariables}
{

}

double SetRangeFreqCosRect::setRangeFrequency() const
{
    if (m_modSignalVariables->m_durationMod == 0) // ((m_decimation / 2) - 2 / m_durationMainSignal) < 0
    {
        return 0;
    }
    else
    {
        if (m_modSignalVariables->m_decimation / 4 < m_signalVariables->m_frequency)
        {
            double a = m_modSignalVariables->m_decimation / 2 - m_signalVariables->m_frequency - 2 / m_modSignalVariables->m_durationMod;
            if (a > 0)
            {
                return a;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            double a = m_signalVariables->m_frequency - 2 / m_modSignalVariables->m_durationMod;
            if (a > 0)
            {
                return a;
            }
            else
            {
                return 0;
            }
        }
    }
}
