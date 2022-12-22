#ifndef SETRANGEFREQNOSIGNALCOS_H
#define SETRANGEFREQNOSIGNALCOS_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeFreqNoSignalCos : public I_setRangeFrequency, private A_signalMod
{
public:
    SetRangeFreqNoSignalCos(ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQNOSIGNALCOS_H
