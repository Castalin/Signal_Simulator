#ifndef SETRANGEFREQSINESINE_H
#define SETRANGEFREQSINESINE_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqSineSine : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqSineSine(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;

};

#endif // SETRANGEFREQSINESINE_H
