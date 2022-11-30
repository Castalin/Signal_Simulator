#ifndef SINEMODSINE_H
#define SINEMODSINE_H
#include "AbstractANDInterfaces/a_signal.h"
#include "modsine.h"
#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"

class SineModSine : protected A_signal, public I_getSignal, public I_getSignalIm
{
public:
    SineModSine(SignalVariables *const signalVariables, ModSine *const modSine); //
    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;
private:
    ModSine *m_modSine;
};

#endif // SINEMODSINE_H
