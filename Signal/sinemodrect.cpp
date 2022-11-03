#include "sinemodrect.h"
#include <QtMath>

SineModRect::SineModRect(SignalVariables * const signalVariables, ModRect * const modRect)
    :A_signal{signalVariables}, m_modRect{modRect}
{

}

double SineModRect::getSignal(const int &i)
{
    return (m_signalVariables->m_amplitude + m_modRect->getSignal(i)) * qSin(2 * M_PI * m_signalVariables->m_frequency / m_signalVariables->m_decimation * i);
}
