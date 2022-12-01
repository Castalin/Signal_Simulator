#ifndef SETRANGEFREQSINERECT_H
#define SETRANGEFREQSINERECT_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqSineRect : public I_setRangeFrequency, private A_signal, private A_signalMod
{
public:
    SetRangeFreqSineRect(SignalVariables *const signalVariables ,ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQSINERECT_H
