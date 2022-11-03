#ifndef SETRANGEFREQNOSIGNALRECT_H
#define SETRANGEFREQNOSIGNALRECT_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeFreqNoSignalRect : public I_setRangeFrequency, private A_signalMod
{
public:
    SetRangeFreqNoSignalRect(ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() override;
};

#endif // SETRANGEFREQNOSIGNALRECT_H
