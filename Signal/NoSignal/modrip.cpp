#include "modrip.h"
#include <QtMath>
#include <cstdlib>
#include <ctime>


ModRIP::ModRIP(ModSignalVariables * const modSignalVariables, const int &refreshNum)
    : A_signalMod{modSignalVariables}, A_RandomGenerator{refreshNum}
{

}

double ModRIP::getSignal(const int &i)
{
    return m_modSignalVariables->m_amplitudeMod * qCos(2 * M_PI * i * m_modSignalVariables->m_frequencyMod / m_modSignalVariables->m_decimation + generateValue());
}

double ModRIP::getSignalIm(const int &i)
{
    return m_modSignalVariables->m_amplitudeMod * qSin(2 * M_PI * i * m_modSignalVariables->m_frequencyMod / m_modSignalVariables->m_decimation + generateValue());
}

