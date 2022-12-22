#include "noise.h"
#include <cstdlib>
#include <ctime>
#include <cmath>

Noise::Noise(NoiseVariables * const noiseVariables)
    : m_noiseVariables{noiseVariables}
{

}

double Noise::getSignal(const int &i)
{
    generateValue();
    return m_randVariable;
}

double Noise::getSignalIm(const int &i)
{

    generateValue();
    return m_randVariable;
}

void Noise::generateValue()
{
    this->m_randVariable = 3 * pow(m_noiseVariables->m_dispersion / 30000.0, 0.5) * (rand() % 1000) / 1000.0 * pow(-1.0, static_cast<double>(rand() % 2));
}
