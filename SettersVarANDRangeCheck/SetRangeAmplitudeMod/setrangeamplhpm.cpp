#include "setrangeamplhpm.h"

SetRangeAmplHPM::SetRangeAmplHPM(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables)
    :A_signal{signalVariables}, A_signalMod{modSignalVariables}
{

}

int SetRangeAmplHPM::getAmplModMax() const
{
    return 100 * ((m_signalVariables->m_decimation / 2 - m_signalVariables->m_frequency) / m_modSignalVariables->m_frequencyMod - 1);
}

int SetRangeAmplHPM::getAmplModMin() const
{
    return 0;
}
