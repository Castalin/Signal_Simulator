#include "cosrip.h"
#include <QtMath>

CosRIP::CosRIP(SignalVariables * const signalVariables, const int &refreshNum)
    :A_signal{signalVariables}, A_RandomGenerator{refreshNum}
{

}

double CosRIP::getSignal(const int &i)
{
    return m_signalVariables->m_amplitude * qCos(2 * M_PI * m_signalVariables->m_frequency / m_signalVariables->m_decimation * i + generateValue());
}

double CosRIP::getSignalIm(const int &i)
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * m_signalVariables->m_frequency / m_signalVariables->m_decimation * i + generateValue());
}
