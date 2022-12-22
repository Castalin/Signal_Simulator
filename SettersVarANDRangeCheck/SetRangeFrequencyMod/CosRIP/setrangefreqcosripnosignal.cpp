#include "setrangefreqcosripnosignal.h"

SetRangeFreqCosRIPNoSignal::SetRangeFreqCosRIPNoSignal(ModSignalVariables * const modSignalVariables)
    : A_signalMod{modSignalVariables}
{

}

double SetRangeFreqCosRIPNoSignal::setRangeFrequency() const
{
    return m_modSignalVariables->m_decimation / 2.0;
}
