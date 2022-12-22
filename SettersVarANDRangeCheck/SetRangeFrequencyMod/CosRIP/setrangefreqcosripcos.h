#ifndef SETRANGEFREQCOSRIPCOS_H
#define SETRANGEFREQCOSRIPCOS_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqCosRIPCos : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqCosRIPCos(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;

};

#endif // SETRANGEFREQCOSRIPCOS_H
