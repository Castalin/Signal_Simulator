#include "setrangedurationrect.h"

SetRangeDurationRect::SetRangeDurationRect(SignalVariables * const signalVariables)
    : A_signal{signalVariables}
{

}

double SetRangeDurationRect::setRangeDuration()
{
    return 2047.0 / m_signalVariables->m_decimation;
}
