#ifndef SINE_H
#define SINE_H
#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"


class Sine : protected A_signal, public I_getSignal, public I_getSignalIm
{
public:
    Sine(SignalVariables *const signalVariables);
    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;
};

#endif // SINE_H
