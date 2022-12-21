#ifndef COS_HFM_H
#define COS_HFM_H
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "AbstractANDInterfaces/a_signal.h"
#include "Signal/NoSignal/modcos.h"

class Cos_HFM : protected A_signal, public I_getSignal, public I_getSignalIm
{
public:
    Cos_HFM(SignalVariables * const signalVariables, ModCos * const modCos);

    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;

private:
    ModCos *const m_modCos;
};

#endif // COS_HFM_H
