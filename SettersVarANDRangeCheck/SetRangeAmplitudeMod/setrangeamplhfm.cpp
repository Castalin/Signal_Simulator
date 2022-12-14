#include "setrangeamplhfm.h"

SetRangeAmplHFM::SetRangeAmplHFM(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables)
    :A_signal{signalVariables}, A_signalMod{modSignalVariables}
{

}

int SetRangeAmplHFM::getAmplModMax() const
{
    if (m_signalVariables->m_decimation / 4 < m_signalVariables->m_frequency)
    {
        return (m_signalVariables->m_decimation / 2 - m_signalVariables->m_frequency - m_modSignalVariables->m_frequencyMod) / 1000;
    }
    else
    {
        return (m_signalVariables->m_frequency - m_modSignalVariables->m_frequencyMod) / 1000;
    }
}

int SetRangeAmplHFM::getAmplModMin() const
{
    return 0;
}
