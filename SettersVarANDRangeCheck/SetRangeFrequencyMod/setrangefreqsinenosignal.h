#ifndef SETRANGEFREQSINENOSIGNAL_H
#define SETRANGEFREQSINENOSIGNAL_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeFreqSineNoSignal : public I_setRangeFrequency, private A_signalMod
{
public:
    SetRangeFreqSineNoSignal(ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQSINENOSIGNAL_H
