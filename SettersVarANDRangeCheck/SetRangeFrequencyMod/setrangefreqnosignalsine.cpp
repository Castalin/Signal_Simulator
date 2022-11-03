#include "setrangefreqnosignalsine.h"

SetRangeFreqNoSignalSine::SetRangeFreqNoSignalSine(ModSignalVariables * const modSignalVariables)
    : A_signalMod{modSignalVariables}
{

}

double SetRangeFreqNoSignalSine::setRangeFrequency()
{
    return m_modSignalVariables->m_decimation / 2.0;
}
