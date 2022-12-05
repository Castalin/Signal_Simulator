#ifndef COS_HPM_H
#define COS_HPM_H

#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "modcos.h"

class Cos_HPM : protected A_signal, public I_getSignal, public I_getSignalIm
{
public:
    Cos_HPM(SignalVariables * const signalVariables, ModCos * const modCos);

    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;

private:
    ModCos *const m_modCos;
};

#endif // COS_HPM_H
