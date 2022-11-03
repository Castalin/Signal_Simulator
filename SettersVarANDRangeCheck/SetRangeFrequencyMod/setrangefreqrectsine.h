#ifndef SETRANGEFREQRECTSINE_H
#define SETRANGEFREQRECTSINE_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqRectSine : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqRectSine(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() override;
};

#endif // SETRANGEFREQRECTSINE_H
