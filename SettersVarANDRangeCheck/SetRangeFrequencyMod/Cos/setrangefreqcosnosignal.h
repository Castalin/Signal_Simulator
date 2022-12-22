#ifndef SETRANGEFREQCOSNOSIGNAL_H
#define SETRANGEFREQCOSNOSIGNAL_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeFreqCosNoSignal : public I_setRangeFrequency, private A_signalMod
{
public:
    SetRangeFreqCosNoSignal(ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQCOSNOSIGNAL_H
