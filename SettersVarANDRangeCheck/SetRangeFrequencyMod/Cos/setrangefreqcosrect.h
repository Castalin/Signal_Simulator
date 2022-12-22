#ifndef SETRANGEFREQCOSRECT_H
#define SETRANGEFREQCOSRECT_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqCosRect : public I_setRangeFrequency, private A_signal, private A_signalMod
{
public:
    SetRangeFreqCosRect(SignalVariables *const signalVariables ,ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQCOSRECT_H
