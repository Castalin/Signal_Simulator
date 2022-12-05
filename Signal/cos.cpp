#include "cos.h"
#include <QtMath>

Cos::Cos(SignalVariables *const signalVariables)
    : A_signal{signalVariables}
{

}

double Cos::getSignal(const int &i) const
{
    return m_signalVariables->m_amplitude * qCos(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation);
}

double Cos::getSignalIm(const int &i) const
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation);
}
