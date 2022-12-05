#include "cosmodcos.h"
#include <QtMath>


CosModCos::CosModCos(SignalVariables * const signalVariables, ModCos * const modCos)
    :   A_signal{signalVariables}, m_modCos{modCos}
{

}

double CosModCos :: getSignal(const int &i) const
{
    return (m_signalVariables->m_amplitude + m_modCos->getSignal(i)) * qCos(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation);
}

double CosModCos::getSignalIm(const int &i) const
{
    return (m_signalVariables->m_amplitude + m_modCos->getSignal(i)) * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation);
}
