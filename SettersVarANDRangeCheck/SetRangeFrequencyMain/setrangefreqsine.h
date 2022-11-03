#ifndef SETRANGEFREQSINE_H
#define SETRANGEFREQSINE_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqSine : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqSine(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() override;
};

#endif // SETRANGEFREQSINE_H
