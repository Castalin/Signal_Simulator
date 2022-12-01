#ifndef SINE_HPM_H
#define SINE_HPM_H

#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "modsine.h"

class Sine_HPM : protected A_signal, public I_getSignal, public I_getSignalIm
{
public:
    Sine_HPM(SignalVariables * const signalVariables, ModSine * const modSine);

    virtual double getSignal(const int &i) const override;
    virtual double getSignalIm(const int &i) const override;

private:
    ModSine *const m_modSine;
};

#endif // SINE_HPM_H
