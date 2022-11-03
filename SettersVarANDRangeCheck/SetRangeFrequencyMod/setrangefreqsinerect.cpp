#include "setrangefreqsinerect.h"

SetRangeFreqSineRect::SetRangeFreqSineRect(ModSignalVariables * const modSignalVariables)
    : A_signalMod{modSignalVariables}
{

}

double SetRangeFreqSineRect::setRangeFrequency()
{
    return m_modSignalVariables->m_decimation / (m_modSignalVariables->m_durationMod * m_modSignalVariables->m_decimation + 2);
}
