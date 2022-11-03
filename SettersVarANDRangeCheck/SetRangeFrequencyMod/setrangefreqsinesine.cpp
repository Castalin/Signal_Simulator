#include "setrangefreqsinesine.h"

SetRangeFreqSineSine::SetRangeFreqSineSine(SignalVariables * const signalVariables)
    :A_signal{signalVariables}
{

}

double SetRangeFreqSineSine::setRangeFrequency()
{
    return (m_signalVariables->m_decimation / 2) - m_signalVariables->m_frequency;
}
