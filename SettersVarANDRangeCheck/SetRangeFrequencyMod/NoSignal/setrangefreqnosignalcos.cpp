#include "setrangefreqnosignalcos.h"

SetRangeFreqNoSignalCos::SetRangeFreqNoSignalCos(ModSignalVariables * const modSignalVariables)
    : A_signalMod{modSignalVariables}
{

}

double SetRangeFreqNoSignalCos::setRangeFrequency() const
{
    return m_modSignalVariables->m_decimation / 2.0;
}
