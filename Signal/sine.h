#ifndef SINE_H
#define SINE_H
#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_getsignal.h"


class Sine : protected A_signal, public I_getSignal
{
public:
    Sine(SignalVariables *const signalVariables);
    virtual double getSignal(const int &i) override;
};

#endif // SINE_H
