#include "noise.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Noise::Noise(NoiseVariables * const noiseVariables)
    : m_noiseVariables{noiseVariables}
{
    srand(time(0));
}

double Noise::getSignal(const int &i) const
{
    return 3 * pow(m_noiseVariables->m_dispersion / 2000.0, 0.5) * (rand() % 1000) / 1000.0 * pow(-1.0, static_cast<double>(rand() % 2));
}

double Noise::getSignalIm(const int &i) const
{
    return 3 * pow(m_noiseVariables->m_dispersion / 2000.0, 0.5) * (rand() % 1000) / 1000.0 * pow(-1.0, static_cast<double>(rand() % 2));
}
