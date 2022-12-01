#ifndef SETRANGEDURATIONRECTMOD_H
#define SETRANGEDURATIONRECTMOD_H

#include "AbstractANDInterfaces/i_setrangeduration.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeDurationRectMod : public I_setRangeDuration, private A_signalMod
{
public:
    SetRangeDurationRectMod(ModSignalVariables *const modSignalVariables);
    virtual double setRangeDuration() const override;
};

#endif // SETRANGEDURATIONRECTMOD_H
