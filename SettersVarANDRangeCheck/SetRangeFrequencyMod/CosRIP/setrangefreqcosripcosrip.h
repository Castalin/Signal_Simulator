#ifndef SETRANGEFREQCOSRIPCOSRIP_H
#define SETRANGEFREQCOSRIPCOSRIP_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqCosRIPCosRIP : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqCosRIPCosRIP(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQCOSRIPCOSRIP_H
