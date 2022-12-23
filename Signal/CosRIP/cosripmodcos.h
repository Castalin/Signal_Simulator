#ifndef COSRIPMODCOS_H
#define COSRIPMODCOS_H

#include "AbstractANDInterfaces/a_signal.h"
#include "Signal/NoSignal/modcos.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "AbstractANDInterfaces/a_randomgenerator.h"

class CosRIPModCos : protected A_signal, public I_getSignal, public I_getSignalIm, A_RandomGenerator
{
public:
    CosRIPModCos(SignalVariables *const signalVariables, ModCos *const modCos); //
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;
private:
    ModCos *const m_modCos;
};

#endif // COSRIPMODCOS_H
