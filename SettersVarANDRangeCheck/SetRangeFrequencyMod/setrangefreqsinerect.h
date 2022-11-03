#ifndef SETRANGEFREQSINERECT_H
#define SETRANGEFREQSINERECT_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeFreqSineRect : public I_setRangeFrequency, private A_signalMod
{
public:
    SetRangeFreqSineRect(ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() override;
};

#endif // SETRANGEFREQSINERECT_H
