#include "settermainsignal.h"

SetterMainSignal::SetterMainSignal(SignalVariables * const signalVariables)
    : A_signal{signalVariables}
{

}

void SetterMainSignal::setAmplitude(const int &amplitude)
{
    m_signalVariables->m_amplitude = static_cast<double>(amplitude) / 100.0;
}

void SetterMainSignal::setFrequency(const int &index, const double &frequency)
{
    if (index == FREQUENCY :: kHz)
    {
        m_signalVariables->m_frequency = frequency * 1e3;
    }
    else
    {
        m_signalVariables->m_frequency = frequency * 1e6;
    }
}

void SetterMainSignal::setDuration(const int &index, const double duration)
{
    switch (index)
    {
        case DURATION :: ms: {m_signalVariables->m_duration = duration / 1e3; return;}
        case DURATION :: us: {m_signalVariables->m_duration = duration / 1e6; return;}
        case DURATION :: ns: {m_signalVariables->m_duration = duration / 1e9; return;}
    }
}
