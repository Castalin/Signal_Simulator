#ifndef SETRANGEFREQCOSCOS_H
#define SETRANGEFREQCOSCOS_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqCosCos : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqCosCos(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;

};

#endif // SETRANGEFREQCOSCOS_H
