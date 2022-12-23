#ifndef COSRIPMODHPM_H
#define COSRIPMODHPM_H

#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "Signal/NoSignal/modcos.h"
#include "AbstractANDInterfaces/a_randomgenerator.h"

class CosRIPModHPM : protected A_signal, public I_getSignal, public I_getSignalIm, public A_RandomGenerator
{
public:
    CosRIPModHPM(SignalVariables * const signalVariables, ModCos * const modCos);

    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;

private:
    ModCos *const m_modCos;
};

#endif // COSRIPMODHPM_H
