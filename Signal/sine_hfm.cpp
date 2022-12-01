#include "sine_hfm.h"
#include <QtMath>

Sine_HFM::Sine_HFM(SignalVariables * const signalVariables, ModSine * const modSine)
    : A_signal{signalVariables}, m_modSine{modSine}
{

}

double Sine_HFM::getSignal(const int &i) const
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * i * (m_signalVariables->m_frequency + m_modSine->getSignal(i)) / m_signalVariables->m_decimation);
}

double Sine_HFM::getSignalIm(const int &i) const
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * i * (m_signalVariables->m_frequency + m_modSine->getSignal(i)) / m_signalVariables->m_decimation);
}
