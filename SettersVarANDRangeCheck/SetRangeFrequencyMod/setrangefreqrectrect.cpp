#include "setrangefreqrectrect.h"

SetRangeFreqRectRect::SetRangeFreqRectRect(ModSignalVariables * const modSignalVariables)
    :A_signalMod{modSignalVariables}
{

}

double SetRangeFreqRectRect::setRangeFrequency()
{
    return  m_modSignalVariables->m_decimation / (m_modSignalVariables->m_durationMod * m_modSignalVariables->m_decimation + 2);
}
