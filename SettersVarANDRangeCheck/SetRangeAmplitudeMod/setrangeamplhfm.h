#ifndef SETRANGEAMPLHFM_H
#define SETRANGEAMPLHFM_H

#include "AbstractANDInterfaces/i_getamplmodrange.h"
#include "AbstractANDInterfaces/a_signal.h"
#include "AbstractANDInterfaces/a_signalmod.h"

class SetRangeAmplHFM : public I_getAmplModRange, protected A_signal, protected A_signalMod
{
public:
    SetRangeAmplHFM(SignalVariables * const signalVariables, ModSignalVariables * const modSignalVariables);

    virtual int getAmplModMax() const override;
    virtual int getAmplModMin() const override;
};

#endif // SETRANGEAMPLHFM_H
