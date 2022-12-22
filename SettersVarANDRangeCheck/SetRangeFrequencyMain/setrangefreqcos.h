#ifndef SETRANGEFREQCOS_H
#define SETRANGEFREQCOS_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqCos : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqCos(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQCOS_H
