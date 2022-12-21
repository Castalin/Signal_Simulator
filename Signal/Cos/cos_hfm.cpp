#include "cos_hfm.h"
#include <QtMath>

Cos_HFM::Cos_HFM(SignalVariables * const signalVariables, ModCos * const modCos)
    : A_signal{signalVariables}, m_modCos{modCos}
{

}

double Cos_HFM::getSignal(const int &i) const
{
    return m_signalVariables->m_amplitude * qCos(2 * M_PI * i * (m_signalVariables->m_frequency + 100000 * m_modCos->getSignal(i)) / m_signalVariables->m_decimation);
}

double Cos_HFM::getSignalIm(const int &i) const
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * i * (m_signalVariables->m_frequency + 100000 * m_modCos->getSignal(i)) / m_signalVariables->m_decimation);
}
