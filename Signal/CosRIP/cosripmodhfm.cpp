#include "cosripmodhfm.h"
#include <QtMath>

CosRIPModHFM::CosRIPModHFM(SignalVariables * const signalVariables, ModCos * const modCos, const int &refreshNum)
    : A_signal{signalVariables}, A_RandomGenerator{refreshNum}, m_modCos{modCos}
{

}

double CosRIPModHFM::getSignal(const int &i)
{
    return m_signalVariables->m_amplitude * qCos(2 * M_PI * i * (m_signalVariables->m_frequency + 100000 * m_modCos->getSignal(i)) / m_signalVariables->m_decimation + generateValue());
}

double CosRIPModHFM::getSignalIm(const int &i)
{
    return m_signalVariables->m_amplitude * qSin(2 * M_PI * i * (m_signalVariables->m_frequency + 100000 * m_modCos->getSignal(i)) / m_signalVariables->m_decimation + generateValue());
}
