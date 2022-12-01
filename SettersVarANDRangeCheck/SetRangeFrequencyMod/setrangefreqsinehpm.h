#ifndef SETRANGEFREQSINEHPM_H
#define SETRANGEFREQSINEHPM_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqSineHPM : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqSineHPM(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;

};

#endif // SETRANGEFREQSINEHPM_H
