#ifndef MODSINE_H
#define MODSINE_H
#include "AbstractANDInterfaces/a_signalmod.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"

class ModSine : protected A_signalMod, public I_getSignal, public I_getSignalIm
{
public:
    ModSine(ModSignalVariables *const modSignalVariable);
    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;
};

#endif // MODSINE_H
