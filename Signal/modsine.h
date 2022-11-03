#ifndef MODSINE_H
#define MODSINE_H
#include "AbstractANDInterfaces/a_signalmod.h"
#include "AbstractANDInterfaces/i_getsignal.h"

class ModSine : protected A_signalMod, public I_getSignal
{
public:
    ModSine(ModSignalVariables *const modSignalVariable);
    virtual double getSignal(const int &i) override;
};

#endif // MODSINE_H
