#include "setrangeamplhpm.h"

SetRangeAmplHPM::SetRangeAmplHPM(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables)
    :A_signal{signalVariables}, A_signalMod{modSignalVariables}
{

}

int SetRangeAmplHPM::getAmplModMax() const
{
    if (m_signalVariables->m_decimation / 4 < m_signalVariables->m_frequency)
    {
        return 100 * ((m_signalVariables->m_decimation / 2 - m_signalVariables->m_frequency) / m_modSignalVariables->m_frequencyMod - 1);
    }
    else
    {
        return 100 * (m_signalVariables->m_frequency / m_modSignalVariables->m_frequencyMod - 1);
    }
}

int SetRangeAmplHPM::getAmplModMin() const
{
    return 0;
}
