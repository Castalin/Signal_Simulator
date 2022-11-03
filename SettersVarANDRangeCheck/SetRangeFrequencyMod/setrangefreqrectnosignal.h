#ifndef SETRANGEFREQRECTNOSIGNAL_H
#define SETRANGEFREQRECTNOSIGNAL_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeFreqRectNoSignal : public I_setRangeFrequency, private A_signalMod
{
public:
    SetRangeFreqRectNoSignal(ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() override;
};

#endif // SETRANGEFREQRECTNOSIGNAL_H
