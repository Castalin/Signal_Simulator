#include "sine_hpm.h"
#include <QtMath>

Sine_HPM::Sine_HPM(SignalVariables * const signalVariables, ModSine * const modSine)
    : A_signal{signalVariables}, m_modSine{modSine}
{

}

double Sine_HPM::getSignal(const int &i) const
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation + m_modSine->getSignal(i));
}

double Sine_HPM::getSignalIm(const int &i) const
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation + m_modSine->getSignal(i));
}
