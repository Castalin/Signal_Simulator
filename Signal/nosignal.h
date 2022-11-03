#ifndef NOSIGNAL_H
#define NOSIGNAL_H
#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_getsignal.h"

class NoSignal : protected A_signal, public I_getSignal
{
public:
    NoSignal(SignalVariables * const signalVariables);
    virtual double getSignal(const int &i) override;
};

#endif // NOSIGNAL_H
