#include "cosripmodhfm.h"
#include <QtMath>

CosRIPModHFM::CosRIPModHFM(SignalVariables * const signalVariables, ModCos * const modCos)
    : A_signal{signalVariables}, m_modCos{modCos}
{

}

double CosRIPModHFM::getSignal(const int &i)
{
    generateValue();
    return m_signalVariables->m_amplitude * qCos(2 * M_PI * i * (m_signalVariables->m_frequency + 100000 * m_modCos->getSignal(i)) / m_signalVariables->m_decimation + generateValue());
}

double CosRIPModHFM::getSignalIm(const int &i)
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * i * (m_signalVariables->m_frequency + 100000 * m_modCos->getSignal(i)) / m_signalVariables->m_decimation + generateValue());
}
