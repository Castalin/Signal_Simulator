#ifndef SETRANGEFREQCOSRIPHFM_H
#define SETRANGEFREQCOSRIPHFM_H

#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_setrangefrequency.h"

class SetRangeFreqCosRIPHFM : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqCosRIPHFM(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQCOSRIPHFM_H
