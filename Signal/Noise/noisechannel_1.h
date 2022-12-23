#ifndef NOISECHANNEL_1_H
#define NOISECHANNEL_1_H

#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "Structes/NoiseVariables.h"
#include "AbstractANDInterfaces/a_randomgenerator.h"

class NoiseChannel_1 : public I_getSignal, public I_getSignalIm, public A_RandomGenerator
{
public:
    NoiseChannel_1(NoiseVariables * const noiseVariables);

    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;
    virtual double generateValue() override;

private:
    NoiseVariables *m_noiseVariables;
};

#endif // NOISECHANNEL_1_H
