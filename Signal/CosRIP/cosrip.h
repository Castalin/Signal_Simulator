#ifndef COSRIP_H
#define COSRIP_H

#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "AbstractANDInterfaces/a_randomgenerator.h"

class CosRIP : private A_signal, public I_getSignal, public I_getSignalIm, public A_RandomGenerator
{
public:
    CosRIP(SignalVariables * const signalVariables);
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;
};

#endif // COSRIP_H
