#include "noisechannel_2.h"
#include <cstdlib>
#include <cmath>

NoiseChannel_2::NoiseChannel_2(NoiseVariables * const noiseVariables)
    : m_noiseVariables{noiseVariables}
{

}

double NoiseChannel_2::getSignal(const int &i)
{
    return generateValue();
}

double NoiseChannel_2::getSignalIm(const int &i)
{
    return generateValue();
}

double NoiseChannel_2::generateValue()
{
    return m_randVariable = 3 * pow(m_noiseVariables->m_dispersion_B / 30000.0, 0.5) * (rand() % 1000) / 1000.0 * pow(-1.0, static_cast<double>(rand() % 2));
}
