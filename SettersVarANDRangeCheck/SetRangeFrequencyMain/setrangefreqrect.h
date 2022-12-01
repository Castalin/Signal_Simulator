#ifndef SETRANGEFREQRECT_H
#define SETRANGEFREQRECT_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqRect : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqRect(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQRECT_H
