#ifndef SETRANGEFREQCOSRIPHPM_H
#define SETRANGEFREQCOSRIPHPM_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqCosRIPHPM : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqCosRIPHPM(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;

};

#endif // SETRANGEFREQCOSRIPHPM_H
