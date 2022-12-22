#ifndef COSMODCOS_H
#define COSMODCOS_H
#include "AbstractANDInterfaces/a_signal.h"
#include "Signal/NoSignal/modcos.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"

class CosModCos : protected A_signal, public I_getSignal, public I_getSignalIm
{
public:
    CosModCos(SignalVariables *const signalVariables, ModCos *const modCos); //
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;
private:
    ModCos *const m_modCos;
};

#endif // COSMODCOS_H
