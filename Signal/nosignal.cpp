#include "nosignal.h"

NoSignal::NoSignal(SignalVariables * const signalVariables)
    : A_signal(signalVariables)
{

}

double NoSignal::getSignal(const int &i) const
{
    return m_signalVariables->m_amplitude;
}

double NoSignal::getSignalIm(const int &i) const
{
    return m_signalVariables->m_amplitude;
}
