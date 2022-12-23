#ifndef COSRIPMODHFM_H
#define COSRIPMODHFM_H
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "AbstractANDInterfaces/a_signal.h"
#include "Signal/NoSignal/modcos.h"
#include "AbstractANDInterfaces/a_randomgenerator.h"

class CosRIPModHFM : protected A_signal, public I_getSignal, public I_getSignalIm, public A_RandomGenerator
{
public:
    CosRIPModHFM(SignalVariables * const signalVariables, ModCos * const modCos);

    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;

private:
    ModCos *const m_modCos;
};

#endif // COSRIPMODHFM_H
