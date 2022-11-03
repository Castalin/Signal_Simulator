#ifndef SETRANGEFREQNOSIGNALNOSIGNAL_H
#define SETRANGEFREQNOSIGNALNOSIGNAL_H
#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeFreqNoSignalNoSignal : public I_setRangeFrequency, private A_signalMod
{
public:
    SetRangeFreqNoSignalNoSignal(ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() override;
};

#endif // SETRANGEFREQNOSIGNALNOSIGNAL_H
