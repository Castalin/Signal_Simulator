#include "setrangefreqsinenosignal.h"

SetRangeFreqSineNoSignal::SetRangeFreqSineNoSignal(ModSignalVariables * const modSignalVariables)
    : A_signalMod{modSignalVariables}
{

}

double SetRangeFreqSineNoSignal::setRangeFrequency()
{
    return m_modSignalVariables->m_decimation / 2.0;
}
