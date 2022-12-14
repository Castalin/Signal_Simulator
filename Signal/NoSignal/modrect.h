#ifndef MODRECT_H
#define MODRECT_H
#include "AbstractANDInterfaces/a_signalmod.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"

class ModRect : protected A_signalMod, public I_getSignal, public I_getSignalIm
{
public:
    ModRect(ModSignalVariables *const modSignalVariable);
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;
};

#endif // MODRECT_H
