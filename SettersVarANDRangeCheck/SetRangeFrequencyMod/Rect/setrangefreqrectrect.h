#ifndef SETRANGEFREQRECTRECT_H
#define SETRANGEFREQRECTRECT_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeFreqRectRect : public I_setRangeFrequency, private A_signalMod
{
public:
    SetRangeFreqRectRect(ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() const override;
};

#endif // SETRANGEFREQRECTRECT_H
