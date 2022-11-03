#include "setrangedurationrect.h"

SetRangeDurationRect::SetRangeDurationRect(SignalVariables * const signalVariables)
    : A_signal{signalVariables}
{

}

double SetRangeDurationRect::setRangeDuration()
{
    return 255.0 / m_signalVariables->m_decimation;
}
