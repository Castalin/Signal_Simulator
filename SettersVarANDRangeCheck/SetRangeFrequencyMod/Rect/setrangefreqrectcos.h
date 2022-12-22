#ifndef SETRANGEFREQRECTCOS_H
#define SETRANGEFREQRECTCOS_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqRectCos : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqRectCos(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQRECTCOS_H
