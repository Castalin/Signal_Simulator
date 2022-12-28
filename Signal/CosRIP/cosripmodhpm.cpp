#include "cosripmodhpm.h"
#include <QtMath>

CosRIPModHPM::CosRIPModHPM(SignalVariables * const signalVariables, ModCos * const modCos)
    : A_signal{signalVariables}, m_modCos{modCos}
{

}

double CosRIPModHPM::getSignal(const int &i)
{
    return m_signalVariables->m_amplitude * qCos(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation + m_modCos->getSignal(i) + generateValue());
}

double CosRIPModHPM::getSignalIm(const int &i)
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation + m_modCos->getSignal(i) + generateValue());
}
