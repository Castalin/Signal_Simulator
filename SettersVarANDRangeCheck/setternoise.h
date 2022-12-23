#ifndef SETTERNOISE_H
#define SETTERNOISE_H

#include "Structes/NoiseVariables.h"

class SetterNoise
{
public:
    SetterNoise(NoiseVariables *const noiseVariables);

    void setDispChannel_1(const double &dispersion) const;
    void setDispChannel_2(const double &dispersion) const;

private:
    NoiseVariables *const m_ptrToNoiseVariables;


};

#endif // SETTERNOISE_H
