#ifndef SETRANGEFREQNOSIGNALRIP_H
#define SETRANGEFREQNOSIGNALRIP_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeFreqNoSignalRip : public I_setRangeFrequency, private A_signalMod
{
public:
    SetRangeFreqNoSignalRip(ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQNOSIGNALRIP_H
