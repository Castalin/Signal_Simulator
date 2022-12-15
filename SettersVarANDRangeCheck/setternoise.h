#ifndef SETTERNOISE_H
#define SETTERNOISE_H

#include "Structes/NoiseVariables.h"

class SetterNoise
{
public:
    SetterNoise(NoiseVariables *const noiseVariables);

    void setDispersion(const int &dispersion) const;

private:
    NoiseVariables *const m_ptrToNoiseVariables;


};

#endif // SETTERNOISE_H
