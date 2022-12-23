#include "noisechannel_1.h"
#include <cmath>
#include <cstdlib>

NoiseChannel_1::NoiseChannel_1(NoiseVariables * const noiseVariables)
    : m_noiseVariables{noiseVariables}
{

}

double NoiseChannel_1::getSignal(const int &i)
{
    generateValue();
    return m_randVariable;
}

double NoiseChannel_1::getSignalIm(const int &i)
{
    generateValue();
    return m_randVariable;
}

double NoiseChannel_1::generateValue()
{
    return m_randVariable = 3 * pow(m_noiseVariables->m_dispersion_A / 30000.0, 0.5) * (rand() % 1000) / 1000.0 * pow(-1.0, static_cast<double>(rand() % 2));
}
