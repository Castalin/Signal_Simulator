#include "setrangefreqrectnosignal.h"

SetRangeFreqRectNoSignal::SetRangeFreqRectNoSignal(ModSignalVariables * const modSignalVariables)
    :A_signalMod{modSignalVariables}
{

}

double SetRangeFreqRectNoSignal::setRangeFrequency() const
{
    return m_modSignalVariables->m_decimation / 2;
}
