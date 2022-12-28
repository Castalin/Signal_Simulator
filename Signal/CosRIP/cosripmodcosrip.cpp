#include "cosripmodcosrip.h"
#include <QtMath>

CosRIPModCosRIP::CosRIPModCosRIP(SignalVariables *const signalVariables, ModRIP *const modRIP)
    :A_signal{signalVariables}, m_ptrToModRIP{modRIP}
{

}

double CosRIPModCosRIP::getSignal(const int &i)
{
    return (m_signalVariables->m_amplitude + m_ptrToModRIP->getSignal(i)) * qCos(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation + generateValue());
}

double CosRIPModCosRIP::getSignalIm(const int &i)
{
    return (m_signalVariables->m_amplitude + m_ptrToModRIP->getSignal(i)) * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation + generateValue());
}
