#include "setrangedurationrectMod.h"

SetRangeDurationRectMod::SetRangeDurationRectMod(ModSignalVariables * const modSignalVariables)
    :A_signalMod{modSignalVariables}
{

}

double SetRangeDurationRectMod::setRangeDuration()
{
    return 255.0 / m_modSignalVariables->m_decimation;
}
