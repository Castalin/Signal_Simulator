#ifndef SETRANGEFREQNOSIGNALNOSIGNAL_H
#define SETRANGEFREQNOSIGNALNOSIGNAL_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeFreqNoSignalNoSignal : private A_signalMod, public I_setRangeFrequency
{
public:
    SetRangeFreqNoSignalNoSignal(ModSignalVariables * const modSignalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQNOSIGNALNOSIGNAL_H
