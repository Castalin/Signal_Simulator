#include "modsine.h"
#include <QtMath>


ModSine::ModSine(ModSignalVariables * const modSignalVariable)
    : A_signalMod(modSignalVariable)
{

}

double ModSine::getSignal(const int &i) const
{
    return m_modSignalVariables->m_amplitudeMod * qSin(2 * M_PI * i * m_modSignalVariables->m_frequencyMod / m_modSignalVariables->m_decimation);
}

double ModSine::getSignalIm(const int &i) const
{
    return m_modSignalVariables->m_amplitudeMod * qSin(2 * M_PI * i * m_modSignalVariables->m_frequencyMod / m_modSignalVariables->m_decimation - M_PI / 2);
}
