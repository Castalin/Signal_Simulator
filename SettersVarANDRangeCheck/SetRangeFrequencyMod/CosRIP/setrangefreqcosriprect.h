#ifndef SETRANGEFREQCOSRIPRECT_H
#define SETRANGEFREQCOSRIPRECT_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signalmod.h"
#include "AbstractANDInterfaces/a_signal.h"

class SetRangeFreqCosRIPRect : public I_setRangeFrequency, private A_signal, private A_signalMod
{
public:
    SetRangeFreqCosRIPRect(SignalVariables *const signalVariables ,ModSignalVariables *const modSignalVariables);
    virtual double setRangeFrequency() const override;

};

#endif // SETRANGEFREQCOSRIPRECT_H
