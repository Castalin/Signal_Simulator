#ifndef SETRANGEAMPLHPM_H
#define SETRANGEAMPLHPM_H

#include "AbstractANDInterfaces/i_getamplmodrange.h"
#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeAmplHPM : public I_getAmplModRange, protected A_signal, protected A_signalMod
{
public:
    SetRangeAmplHPM(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables);

    virtual int getAmplModMax() const override;
    virtual int getAmplModMin() const override;
};

#endif // SETRANGEAMPLHPM_H
