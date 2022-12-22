#include "setrangefreqnosignalrect.h"

SetRangeFreqNoSignalRect::SetRangeFreqNoSignalRect(ModSignalVariables * const modSignalVariables)
    : A_signalMod{modSignalVariables}
{

}

double SetRangeFreqNoSignalRect::setRangeFrequency() const
{
    return m_modSignalVariables->m_decimation /(m_modSignalVariables->m_durationMod * m_modSignalVariables->m_decimation + 2);
}
