#include "setternoise.h"

SetterNoise::SetterNoise(NoiseVariables *const noiseVariables)
    :m_ptrToNoiseVariables{noiseVariables}
{

}

void SetterNoise::setDispersion(const double &dispersion) const
{
    m_ptrToNoiseVariables->m_dispersion = dispersion;
}
