#include "cosmodrip.h"
#include <QtMath>

CosModRIP::CosModRIP(SignalVariables *const signalVariables, ModRIP *const modRIP)
    :A_signal{signalVariables}, m_ptrToModRIP{modRIP}
{

}

double CosModRIP::getSignal(const int &i) const
{
    return (m_signalVariables->m_amplitude + m_ptrToModRIP->getSignal(i)) * qCos(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation);
}

double CosModRIP::getSignalIm(const int &i) const
{
    return (m_signalVariables->m_amplitude + m_ptrToModRIP->getSignal(i)) * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation);
}
