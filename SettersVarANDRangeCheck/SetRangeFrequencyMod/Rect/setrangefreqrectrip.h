#ifndef SETRANGEFREQRECTRIP_H
#define SETRANGEFREQRECTRIP_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqRectRIP : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqRectRIP(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQRECTRIP_H
