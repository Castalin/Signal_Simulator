#include "setrangefreqnosignalnosignal.h"

SetRangeFreqNoSignalNoSignal::SetRangeFreqNoSignalNoSignal(ModSignalVariables * const modSignalVariables)
    : A_signalMod{modSignalVariables}
{

}

double SetRangeFreqNoSignalNoSignal::setRangeFrequency() const
{
    return m_modSignalVariables->m_decimation / 2.0;
}
