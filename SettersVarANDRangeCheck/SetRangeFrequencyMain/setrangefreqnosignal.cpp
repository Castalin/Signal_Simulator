#include "setrangefreqnosignal.h"

SetRangeFreqNoSignal::SetRangeFreqNoSignal(SignalVariables * const signalVariables)
    :A_signal(signalVariables)
{

}

double SetRangeFreqNoSignal::setRangeFrequency() const
{
    return m_signalVariables->m_decimation / 2.0;
}
