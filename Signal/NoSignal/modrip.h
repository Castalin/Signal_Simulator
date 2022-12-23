#ifndef MODRIP_H
#define MODRIP_H

#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "AbstractANDInterfaces/a_signalmod.h"
#include "AbstractANDInterfaces/a_randomgenerator.h"

class ModRIP : protected A_signalMod, public I_getSignal, public I_getSignalIm, public A_RandomGenerator
{
public:
    explicit ModRIP(ModSignalVariables  * const modSignalVariables);

    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;
};

#endif // MODRIP_H
