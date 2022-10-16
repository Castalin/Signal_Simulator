#ifndef A_SIGNALMOD_H
#define A_SIGNALMOD_H
#include "a_signal.h"

class A_signalMod : public A_signal
{
public:
    A_signalMod();

protected:
    static double s_amplitudeMod;
    static double s_frequencyMod;
    static double s_durationMod;

public:
    static void setDurationMod(const double &durationMod);
    static void setFrequencyMod(const double &frequencyMod);
    static void setAmplitudeMod(const double &amplitudeMod);
};

#endif // A_SIGNALMOD_H
