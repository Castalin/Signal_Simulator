#ifndef MODCOS_H
#define MODCOS_H
#include "AbstractANDInterfaces/a_signalmod.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"

class ModCos : protected A_signalMod, public I_getSignal, public I_getSignalIm
{
public:
    ModCos(ModSignalVariables *const modSignalVariable);
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;
};

#endif // MODCOS_H
