#ifndef SETTERMAINSIGNAL_H
#define SETTERMAINSIGNAL_H
#include "AbstractANDInterfaces/a_signal.h"

class SetterMainSignal : private A_signal
{
public:
    SetterMainSignal(SignalVariables *const signalVariables);
    void setAmplitude(const int &amplitude) const;
    void setFrequency(const int &index, const double &frequency) const;
    void setDuration(const int &index, const double duration) const;

private:
    enum FREQUENCY
    {
        kHz                 = 0,
        MHz                 = 1,
    };

    enum DURATION
    {
        ms                  = 0,
        us                  = 1,
        ns                  = 2,
    };

};

#endif // SETTERMAINSIGNAL_H
