#include "setrangefreqnosignalrip.h"

SetRangeFreqNoSignalRip::SetRangeFreqNoSignalRip(ModSignalVariables *const modSignalVariables)
    :A_signalMod{modSignalVariables}
{

}

double SetRangeFreqNoSignalRip::setRangeFrequency() const
{
    return m_modSignalVariables->m_decimation / 2.0;
}
