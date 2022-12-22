#ifndef SETRANGEFREQCOSRIPNOSIGNAL_H
#define SETRANGEFREQCOSRIPNOSIGNAL_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeFreqCosRIPNoSignal : public I_setRangeFrequency, private A_signalMod
{
public:
    SetRangeFreqCosRIPNoSignal(ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQCOSRIPNOSIGNAL_H
