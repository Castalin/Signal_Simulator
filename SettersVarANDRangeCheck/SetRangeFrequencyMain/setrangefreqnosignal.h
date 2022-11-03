#ifndef SETRANGEFREQNOSIGNAL_H
#define SETRANGEFREQNOSIGNAL_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqNoSignal : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqNoSignal(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() override;
};

#endif // SETRANGEFREQNOSIGNAL_H
