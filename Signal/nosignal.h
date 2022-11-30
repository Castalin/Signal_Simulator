#ifndef NOSIGNAL_H
#define NOSIGNAL_H
#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"

class NoSignal : protected A_signal, public I_getSignal, public I_getSignalIm
{
public:
    NoSignal(SignalVariables * const signalVariables);
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;
};

#endif // NOSIGNAL_H
