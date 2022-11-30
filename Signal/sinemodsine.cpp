#include "sinemodsine.h"
#include <QtMath>


SineModSine::SineModSine(SignalVariables * const signalVariables, ModSine * const modSine)
    :   A_signal{signalVariables}, m_modSine{modSine}
{

}

double SineModSine :: getSignal(const int &i)
{
    return (m_signalVariables->m_amplitude + m_modSine->getSignal(i)) * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation);
}

double SineModSine::getSignalIm(const int &i)
{
    return (m_signalVariables->m_amplitude + m_modSine->getSignalIm(i)) * qSin(2 * M_PI * i * m_signalVariables->m_frequency / m_signalVariables->m_decimation);
}
