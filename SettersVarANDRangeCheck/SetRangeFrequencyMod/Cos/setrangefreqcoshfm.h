#ifndef SETRANGEFREQCOSHFM_H
#define SETRANGEFREQCOSHFM_H

#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_setrangefrequency.h"

class SetRangeFreqCosHFM : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqCosHFM(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQCOSHFM_H
