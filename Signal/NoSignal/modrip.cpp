#include "modrip.h"
#include <QtMath>
#include <cstdlib>
#include <ctime>


ModRIP::ModRIP(ModSignalVariables * const modSignalVariables)
    : A_signalMod{modSignalVariables}
{

}

double ModRIP::getSignal(const int &i)
{
    generateValue();
    return m_modSignalVariables->m_amplitudeMod * qCos(2 * M_PI * i * m_modSignalVariables->m_frequencyMod / m_modSignalVariables->m_decimation + m_randVariable);
}

double ModRIP::getSignalIm(const int &i)
{
    return m_modSignalVariables->m_amplitudeMod * qSin(2 * M_PI * i * m_modSignalVariables->m_frequencyMod / m_modSignalVariables->m_decimation + m_randVariable);
}

void ModRIP::generateValue()
{
    return A_RandomGenerator :: generateValue();
}
