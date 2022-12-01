#ifndef SINE_HFM_H
#define SINE_HFM_H
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "AbstractANDInterfaces/a_signal.h"
#include "modsine.h"

class Sine_HFM : protected A_signal, public I_getSignal, public I_getSignalIm
{
public:
    Sine_HFM(SignalVariables * const signalVariables, ModSine * const modSine);

    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;

private:
    ModSine *const m_modSine;
};

#endif // SINE_HFM_H
