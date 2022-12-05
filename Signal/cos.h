#ifndef COS_H
#define COS_H
#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"


class Cos : protected A_signal, public I_getSignal, public I_getSignalIm
{
public:
    Cos(SignalVariables *const signalVariables);
    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;
};

#endif // COS_H
