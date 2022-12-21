#include "cos_hpm.h"
#include <QtMath>

Cos_HPM::Cos_HPM(SignalVariables * const signalVariables, ModCos * const modCos)
    : A_signal{signalVariables}, m_modCos{modCos}
{

}

double Cos_HPM::getSignal(const int &i) const
{
    return m_signalVariables->m_amplitude * qCos(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation + m_modCos->getSignal(i));
}

double Cos_HPM::getSignalIm(const int &i) const
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation + m_modCos->getSignal(i));
}
