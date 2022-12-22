#include "setrangefreqcosnosignal.h"

SetRangeFreqCosNoSignal::SetRangeFreqCosNoSignal(ModSignalVariables * const modSignalVariables)
    : A_signalMod{modSignalVariables}
{

}

double SetRangeFreqCosNoSignal::setRangeFrequency() const
{
    return m_modSignalVariables->m_decimation / 2.0;
}
