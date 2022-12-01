#ifndef SETRANGEFREQSINEHFM_H
#define SETRANGEFREQSINEHFM_H

#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_setrangefrequency.h"

class SetRangeFreqSineHFM : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqSineHFM(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQSINEHFM_H
