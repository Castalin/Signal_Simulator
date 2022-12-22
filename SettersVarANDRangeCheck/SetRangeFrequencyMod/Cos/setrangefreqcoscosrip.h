#ifndef SETRANGEFREQCOSCOSRIP_H
#define SETRANGEFREQCOSCOSRIP_H

#include "AbstractANDInterfaces/i_setrangefrequency.h"
#include "AbstractANDInterfaces/a_signal.h"


class SetRangeFreqCosCosRIP : public I_setRangeFrequency, private A_signal
{
public:
    SetRangeFreqCosCosRIP(SignalVariables *const signalVariables);
    virtual double setRangeFrequency() const override;

};
#endif // SETRANGEFREQCOSCOSRIP_H
