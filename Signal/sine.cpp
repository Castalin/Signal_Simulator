#include "sine.h"
#include <QtMath>

Sine::Sine(SignalVariables *const signalVariables)
    : A_signal{signalVariables}
{

}

double Sine::getSignal(const int &i)
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation);
}

double Sine::getSignalIm(const int &i)
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation - M_PI / 2);
}
