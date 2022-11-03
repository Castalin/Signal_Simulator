#ifndef SETRANGEFREQNOSIGNALSINE_H
#define SETRANGEFREQNOSIGNALSINE_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeFreqNoSignalSine : public I_setRangeFrequency, private A_signalMod
{
public:
    SetRangeFreqNoSignalSine(ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() override;
};

#endif // SETRANGEFREQNOSIGNALSINE_H
