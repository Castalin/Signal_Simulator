#include "setrangefreqsine.h"

SetRangeFreqSine::SetRangeFreqSine(SignalVariables * const signalVariables)
    :A_signal{signalVariables}
{

}

double SetRangeFreqSine::setRangeFrequency() const
{
    return m_signalVariables->m_decimation / 2.0;
}
