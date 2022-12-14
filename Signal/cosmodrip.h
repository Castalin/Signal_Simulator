#ifndef COSMODRIP_H
#define COSMODRIP_H

#include "modrip.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "AbstractANDInterfaces/a_signal.h"

class CosModRIP : private A_signal, public I_getSignal, public I_getSignalIm
{
public:
    CosModRIP(SignalVariables *const signalVariables, ModRIP *const modRIP); //
    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;

private:
    ModRIP *m_ptrToModRIP;
};

#endif // COSMODRIP_H
