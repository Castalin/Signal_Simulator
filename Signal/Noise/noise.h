#ifndef NOISE_H
#define NOISE_H

#include "AbstractANDInterfaces/i_getsignal.h"
#include "AbstractANDInterfaces/i_getsignalim.h"
#include "Structes/NoiseVariables.h"
#include "AbstractANDInterfaces/a_randomgenerator.h"

class Noise : public I_getSignal, public I_getSignalIm, public A_RandomGenerator
{
public:
    Noise(NoiseVariables * const noiseVariables);

    virtual double getSignal(const int &i) override;
    virtual double getSignalIm(const int &i) override;
    virtual void generateValue() override;

private:
    NoiseVariables *m_noiseVariables;

};

#endif // NOISE_H
