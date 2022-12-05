#ifndef COSMODCOS_H
#define COSMODCOS_H
#include "AbstractANDInterfaces/a_signal.h"
#include "modcos.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"

class CosModCos : protected A_signal, public I_getSignal, public I_getSignalIm
{
public:
    CosModCos(SignalVariables *const signalVariables, ModCos *const modSine); //
    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;
private:
    ModCos *const m_modCos;
};

#endif // COSMODCOS_H
