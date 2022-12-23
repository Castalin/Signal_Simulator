#ifndef COSRIPMODCOSRIP_H
#define COSRIPMODCOSRIP_H

#include "Signal/NoSignal/modrip.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/a_randomgenerator.h"

class CosRIPModCosRIP : private A_signal, public I_getSignal, public I_getSignalIm, public A_RandomGenerator
{
public:
    CosRIPModCosRIP(SignalVariables *const signalVariables, ModRIP *const modRIP); //
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;
private:
    ModRIP *m_ptrToModRIP;
};

#endif // COSRIPMODCOSRIP_H
