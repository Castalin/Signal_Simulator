#include "cosripmodcos.h"
#include <QtMath>

CosRIPModCos::CosRIPModCos(SignalVariables *const signalVariables, ModCos *const modCos)
    :A_signal{signalVariables}, m_modCos{modCos}
{

}

double CosRIPModCos::getSignal(const int &i)
{
    generateValue();
    return (m_signalVariables->m_amplitude + m_modCos->getSignal(i)) * qCos(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation + m_randVariable);
}

double CosRIPModCos::getSignalIm(const int &i)
{
    return (m_signalVariables->m_amplitude + m_modCos->getSignal(i)) * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation + m_randVariable);
}

void CosRIPModCos::generateValue()
{
    return A_RandomGenerator :: generateValue();
}
