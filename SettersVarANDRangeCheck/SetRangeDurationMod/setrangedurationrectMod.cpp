#include "setrangedurationrectMod.h"

SetRangeDurationRectMod::SetRangeDurationRectMod(ModSignalVariables * const modSignalVariables)
    :A_signalMod{modSignalVariables}
{

}

double SetRangeDurationRectMod::setRangeDuration() const
{
    return 2047.0 / m_modSignalVariables->m_decimation;
}
