#ifndef SETRANGEFREQSINERIP_H
#define SETRANGEFREQSINERIP_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"


class SetRangeFreqSineRIP : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqSineRIP(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;

};
#endif // SETRANGEFREQSINERIP_H
