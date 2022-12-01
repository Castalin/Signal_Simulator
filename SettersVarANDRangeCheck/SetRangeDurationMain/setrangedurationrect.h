#ifndef SETRANGEDURATIONRECT_H
#define SETRANGEDURATIONRECT_H
#include "AbstractANDInterfaces/i_setrangeduration.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeDurationRect : public I_setRangeDuration, private A_signal
{
public:
    SetRangeDurationRect(SignalVariables *const signalVariables);
    virtual double setRangeDuration() const override;
};

#endif // SETRANGEDURATIONRECT_H
