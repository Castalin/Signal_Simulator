#include "setternoise.h"

SetterNoise::SetterNoise(NoiseVariables *const noiseVariables)
    :m_ptrToNoiseVariables{noiseVariables}
{

}

void SetterNoise::setDispChannel_1(const double &dispersion) const
{
    m_ptrToNoiseVariables->m_dispersion_A = dispersion;
}

void SetterNoise::setDispChannel_2(const double &dispersion) const
{
    m_ptrToNoiseVariables->m_dispersion_B = dispersion;
}
