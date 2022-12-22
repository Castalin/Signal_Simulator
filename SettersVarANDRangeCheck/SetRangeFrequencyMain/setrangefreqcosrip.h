#ifndef SETRANGEFREQCOSRIP_H
#define SETRANGEFREQCOSRIP_H

#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_setrangefrequency.h"

class SetRangeFreqCosRIP : private A_signal, public I_setRangeFrequency
{
public:
    SetRangeFreqCosRIP(SignalVariables * const signalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQCOSRIP_H
