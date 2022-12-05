#include "modcos.h"
#include <QtMath>


ModCos::ModCos(ModSignalVariables * const modSignalVariable)
    : A_signalMod(modSignalVariable)
{

}

double ModCos::getSignal(const int &i) const
{
    return m_modSignalVariables->m_amplitudeMod * qCos(2 * M_PI * i * m_modSignalVariables->m_frequencyMod / m_modSignalVariables->m_decimation);
}

double ModCos::getSignalIm(const int &i) const
{
    return m_modSignalVariables->m_amplitudeMod * qSin(2 * M_PI * i * m_modSignalVariables->m_frequencyMod / m_modSignalVariables->m_decimation);
}
