#include "a_signalmod.h"

A_signalMod::A_signalMod()
{

}

A_signalMod::~A_signalMod()
{

}

double A_signalMod :: s_amplitudeMod;
double A_signalMod :: s_frequencyMod;
double A_signalMod :: s_durationMod;

void A_signalMod::setDurationMod(const double &durationMod)
{
    s_durationMod = durationMod;
}

void A_signalMod::setFrequencyMod(const double &frequencyMod)
{
    s_frequencyMod = frequencyMod;
}

void A_signalMod::setAmplitudeMod(const double &amplitudeMod)
{
    s_amplitudeMod = amplitudeMod;
}
