#include "settermodsignal.h"

SetterModSignal::SetterModSignal(ModSignalVariables * const modSignalVariables)
    : A_signalMod{modSignalVariables}
{

}

void SetterModSignal::setModAmplitude(const int &modAmplitude)
{
    m_modSignalVariables->m_amplitudeMod = static_cast<double>(modAmplitude) / 100.0;
}

void SetterModSignal::setModFrequency(const int &index, const double &modFrequency)
{
    if (index == FREQUENCY :: kHz)
    {
        m_modSignalVariables->m_frequencyMod = modFrequency * 1e3;
    }
    else
    {
        m_modSignalVariables->m_frequencyMod = modFrequency * 1e6;
    }
}

void SetterModSignal::setModDuration(const int &index, const double &modDuration)
{
    switch (index)
    {
        case DURATION :: ms: {m_modSignalVariables->m_durationMod = modDuration / 1e3; return;}
        case DURATION :: us: {m_modSignalVariables->m_durationMod = modDuration / 1e6; return;}
        case DURATION :: ns: {m_modSignalVariables->m_durationMod = modDuration / 1e9; return;}
    }
}
