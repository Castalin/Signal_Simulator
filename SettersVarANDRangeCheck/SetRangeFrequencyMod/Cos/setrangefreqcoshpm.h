#ifndef SETRANGEFREQCOSHPM_H
#define SETRANGEFREQCOSHPM_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqCosHPM : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqCosHPM(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;

};

#endif // SETRANGEFREQCOSHPM_H
